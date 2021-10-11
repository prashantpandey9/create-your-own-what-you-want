# # Here is the mini python project of a self balancing robot with LQR control and pybullet simulation

# Description the implementation of Control Systems namely [LQR](#lqr_sec) on our robot. 

# #### Importing Libraris
from __future__ import print_function, division
import sys
import numpy as np
import pybullet as p
import math
import time
import pybullet_data
import controlpy
import scipy
import matplotlib.pyplot as plt
from control.matlab import *
import cv2

# # LQR Controller

# Here, we are working on LQR controller. We have used control library [[1](#PythonControl)] of python to work on lqr. 
# For the lqr controllers, the state-space equations of the system are required. 
# The above equation is derived from [[2](#SystemEquation)] .
# Here,
#(M)       mass of the cart                         2 kg
#(m)       mass of the pendulum                     5 kg
#(b)       coefficient of friction for cart         0.5 N/m/sec
#(l)       length to pendulum center of mass        0.1 m
#(I)       mass moment of inertia of the pendulum   0.10500391309238813 kg.m^2
#(F)       force applied to the cart
#(x)       cart position coordinate
#(theta)   pendulum angle from vertical (down)


M = 2.
m = 5.
b = 0.5
I = 0.10500391309238813
g = 9.8
l = 0.1


############################################################################################################
#Refer to "test_lqr.py" for example code
#Variable : "A" : 2D numpy array 
#Variable : "A" : 2D numpy array

A = np.array([[ 0. , 1.,0,0]
            ,[0, 0, -g*m/M,0]
            ,[0,0, 0, 1.]
            ,[0,0,(M+m)*g/(l*M),0]])

B = np.array([[0. ]
            ,[1/M]
            ,[0]
            ,[-1/(l*M)]])

###################################################################################################################################

# The class for LQR

Q = np.array([[ 1,    0,  0,  0]
            ,[ 0, 1,  0,  0]
            ,[ 0,   0,  10,  0]
            ,[ 0,   0,  0,  100]])
R = [[500]]
K,S,e =controlpy.synthesis.controller_lqr(A,B,Q,R)
# print(K)
# print(S)
# print(e)

# From [[2](#SystemEquation)] , we get the cost function 
# J = int (x^T Q x +u^T R u)dt
# Here, we need to tune Q matrix and R such that the value of "J" is minimum. The lqp function automatically does that for you

class SelfBalanceLQR:
    '''
    Purpose:
    ---
    Class Describing the gains of LQR and various functions
    Functions:
    ---
        __init__ : Called by default to initilize the variables in LQR
        callback : It takes the data from sensors/bots and accordingly predicts the next state and respecive action
        callback_q : It can be used to change the value of gains during execution
        callback_r : It can be used to change the value of gains during execution
    Example initialization and function call:
    ---
    balance=SelfBalanceLQR()
    vel=balance.callback(data)
    '''
    def __init__(self):
        self.xvelMin=-.01# x velocity
        self.xvelMax =0
        self.yMin = -0.01#yaw
        self.yMax = 0
        self.y_ = 0
        self.Q = Q
        self.R = R
        self.K,self.S,self.e = controlpy.synthesis.controller_lqr(A,B,self.Q,self.R)
    def callback(self,data):
        ##############################################################################################
        # calculate the state using data calulated from bot
        # Variable np_x : 2D array of state to be multiplie with A 
        # Variable y : integer representing the state value that is used to calculate error/other states 
       
        np_x=np.array([[np.squeeze(np.asarray(data[0]))],[np.squeeze(np.asarray(data[1]))], [np.squeeze(np.asarray(data[2]))], [np.squeeze(np.asarray(data[3]))]])

        y=data[2]

        u_t=-np.matmul(self.K,np_x) 

        xvel = (np.matmul(A,np_x)+np.matmul(B,u_t))[1] ##### might have to change this based on your state equation

        ####################################################################################################################
        
        #storing previous values for evaluation 
        if y>self.yMax:
            self.yMax = y
        elif y<self.yMin:
            self.yMin =y
        if xvel>self.xvelMax:
            self.xvelMax=xvel
        elif xvel<self.xvelMin:
            self.xvelMin = xvel
            
        linear_vel = [xvel,0,0]
        angular_vel=[0,0,0]
        #print("Max vel " + str(self.xvelMax) + " & Min vel " + str(self.xvelMin) + " Max y " + str(self.yMax*180/3.1416) +" & Min y" + str(self.yMin*180/3.1416))
        #print("Velocity "+ str(xvel)+ " & yaw " + str(y))
        self.y_ = y # storing th previous value of state 
        
        return xvel-np_x[1] # returning the difference of current state and next state to compensate error
        
    def callback_q(self,data):
        q = data.data
        self.Q = np.array([[ q,   0],[  0, 10*q]])
        self.K,self.S,self.e = controlpy.synthesis.controller_lqr(A,B,self.Q,self.R)
        
    def callback_r(self,data):
        r = data.data
        self.R = r
        self.K,self.S,self.e = controlpy.synthesis.controller_lqr(A,B,self.Q,self.R)

def synthesizeData(robot):
    '''
    Purpose:
    ---
    Calculate the current state(position , velocity , orienation etc.)
    Input Arguments:
    ---
    `robot` :  integer
        object id of bot spawned in pybullet

    Returns:
    ---
    `data` :  1D array 
        list of information required for calculation
    Example call:
    ---
    data=synthesizeData(robot)
    '''
    # print("----------------------------------------------------------------------------------------------------------------")
    # print("Dynamic Info of Base : ",p.getDynamicsInfo(robot, -1),end="\n")
    # #0->mass , 3->local inertial pos
    # print("Base position and Orientation : " , p.getBasePositionAndOrientation(robot),end="\n")
    # #1->orientation

    # com = p.getDynamicsInfo(robot, -1)
    # com += p.getBasePositionAndOrientation(robot)[0][2] 
    # print("Centre of mass - ", com)

    #information required yaw
    #imu sensor , kp ,ki ,kd
    #set cmd_vel 
    ########################################################################################################
    #Varible : data ,1D array that contains all the state variable required to implement LQR
    pos,orn = p.getBasePositionAndOrientation(robot)
    orn = p.getEulerFromQuaternion(orn)
    vel,ang_vel = p.getBaseVelocity(robot)
    data = [pos[0],vel[0],orn[1],ang_vel[1]]
    #############################################################################################################################
    return data


if __name__ == "__main__":
    '''
    Purpose:
    ---
        Setup the pybullet environment and calculation of state variables and respective action to balance the bot
    '''
    # connecting to pybullet
    id = p.connect(p.GUI)
    p.setAdditionalSearchPath(pybullet_data.getDataPath())
    plane = p.loadURDF("plane.urdf")
    p.setGravity(0, 0, -9.8)

    robot = p.loadURDF("/home/krumpr/Documents/GitHub/CnD-SummerCamp21/Week 2/Challenge of The Week/urdf/self_balance.urdf" , [0,0,0.2])
 
    left_joint=0
    right_joint=1
    maxForce = 0
    mode = p.VELOCITY_CONTROL
    p.setJointMotorControl2(robot, left_joint,controlMode=mode, force=maxForce)
    p.setJointMotorControl2(robot, right_joint,controlMode=mode, force=maxForce)

    balance=SelfBalanceLQR()
    
    
    while(True):
        data=synthesizeData(robot)#get data from simulation and bot
        trq=balance.callback(data)#call to function to implement algorithm
        p.setJointMotorControl2(robot, left_joint , p.TORQUE_CONTROL, force = trq)
        p.setJointMotorControl2(robot, right_joint , p.TORQUE_CONTROL, force = -trq)
        p.stepSimulation()

        k= cv2.waitKey(1) & 0xFF
        time.sleep(0.01)

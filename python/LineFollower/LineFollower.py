'''

Develop a PID controller for that car such that it runs along the line y = 0.
The line is also visible on the plane.
Callibrate the PID gains such that car gets to the line as fast as possible and follows it without much disturbance.
Refer to the past two taks and their codes for hints.

'''


import gym
import numpy as np 
import pybullet as p 
import time
import math
import cv2

p_id = p.connect(p.GUI)                #Loading the simulation
p.setGravity(0, 0, -10)                #Setting the gravity

plane = p.loadURDF("/src/plane.urdf")        #Loading the plane
carPos = [0,3,0.1]                      #This is where the car will spawn, this is constant. Don't change

m = 0                           #Declaring the slope of the required line y = mx + c
c = 0                           #Declaring the contsnat of the reuired line  y = mx + c
angle = math.atan(m)

car = p.loadURDF("/src/car/car1.urdf", carPos, p.getQuaternionFromEuler([0,0,angle]))  #Loading the car with head parallel to the given line


def printLine(m, c):                        #This functions draws a line that we need to follow
    angle = math.atan(m)
    z = 0.02
    origin = [0,c,z]
    line = p.loadURDF("/src/line.urdf", origin, p.getQuaternionFromEuler([0,0,angle]))

# printLine(m, c)                    #Calling the function to print the line


num = p.getNumJoints(car)                  #Getting the total number of joints in the car
# for i in range(num):
#     print(p.getJointInfo(car, i))           #Printing the information of each joint to get the motor joints


#These are the 4 motor joints that we need to manipulate, we declare them here.

fl = 2        #Front Left wheel        
fr = 3        #Front Right wheel
bl = 4        #Back Left wheel
br = 5        #Back Right wheel

p.setJointMotorControlArray(car, [fl, bl, fr, br], p.VELOCITY_CONTROL, forces = [0,0,0,0])   #This is done to enable torque control in wheels of the car
p.stepSimulation()



'''
Above this is the loading code
Below this is the code for control and dynamics
'''
pos,  orn = p.getBasePositionAndOrientation(car)

# print(pos)

dt=0.01
sum_error=0.0
output1=0.0

P=9
D=65
I=2.50

def callback():             #Dummy function for the track-bars
    pass

# #P-D gains to be adjusted
# cv2.namedWindow('controls')                        #Making track-bars to track the PD gains in realtime
# cv2.createTrackbar('P', 'controls', 0, 900, callback)
# cv2.createTrackbar('D', 'controls', 0, 6500, callback)
# cv2.createTrackbar('I', 'controls', 0, 250, callback)

# P=cv2.getTrackbarPos('P', 'controls')
# D=cv2.getTrackbarPos('D', 'controls')
# I=cv2.getTrackbarPos('I', 'controls')

# k=cv2.waitKey(1) & 0xFF      #This here activates the track-bars   

#Declare the desired_state and base_torque globally
desired_state = 0  #Set Value Yourself
base_torque = 0   #Set Value Yourself
maxi=10
output1=0.0

def moveCar(output1):  #Enter the motor control here to move the car, give base torque and action calculated as input
    # pass
    #Use p.JointMotorControlArray() function in torque mode
    #Use differential drive to nullify the error
    #The differential drive must increase or decrease the speed of the tyres about a constant base torque using gains
    p.setJointMotorControl2(car,fl,p.TORQUE_CONTROL,force=maxi+output1)
    p.setJointMotorControl2(car,fr,p.TORQUE_CONTROL,force=maxi-output1)
    p.setJointMotorControl2(car,bl,p.TORQUE_CONTROL,force=maxi+output1)
    p.setJointMotorControl2(car,br,p.TORQUE_CONTROL,force=maxi-output1)
    # print(output1)

    # p.stepSimulation()


def calc_error(): #You can calculate the error and required action using this function
    # pass
    #Calculate error by getting the car's position using getBasePositionAndOrientation() function
    #The error is upto your imagination to select. Hint : It can be a distance between the line and the car
    #After getting the error, calculate actions using PID gains.
    #Calibrate your PID gains experimentally. Refer to the earlier tasks for hints.
    p.resetDebugVisualizerCamera(7, -90, -45, p.getBasePositionAndOrientation(car)[0])  #This will keep the camera on the car always
    pos,  orn = p.getBasePositionAndOrientation(car)
    global prev_error
    global sum_error
    error=pos[1]
    if(abs(error)<0.01):
        error=0.0
        sum_error=0.0
    p_pid = P*error
    d_pid = D*((error-prev_error)/dt)
    i_pid = I*sum_error*dt

    output1 = p_pid+i_pid+d_pid
    prev_error=error
    sum_error+=error
    if(abs(output1)<=0.01):
        output1=0
    return output1


error=0.0
prev_error=0.0
t=0
while(True):
    k=cv2.waitKey(1) & 0xFF
    # if k==27:
    #     p.resetSimulation()
    #     p.setGravity(0,0,-10)
    #     plane = p.loadURDF("/home/krumpr/Documents/GitHub/CnD-SummerCamp21/Week 1/Challenge of the week/src/plane.urdf")
    #     car = p.loadURDF("/home/krumpr/Documents/GitHub/CnD-SummerCamp21/Week 1/Challenge of the week/src/car/car1.urdf", carPos, p.getQuaternionFromEuler([0,0,angle]))   #Plane and car loaded again
    #     p.setJointMotorControlArray(car, [fl, bl, fr, br], p.VELOCITY_CONTROL, forces = [0,0,0,0])   #This is done to enable torque control in wheels of the car
    #     printLine(m, c)   #This draws a line along y = 0, which we have to follow
    #     t=0

    
    while(True):
        k=0

        # P=cv2.getTrackbarPos('P', 'controls')/100    #Getting the P from the trak-bars, P is divided by 100 to convert the range from 0-500(integers) to 0-5(floats) as that is the desired range
        # D=cv2.getTrackbarPos('D', 'controls')/100    #Getting the D from the trak-bars, D is divided by 100 to convert the range from 0-500(integers) to 0-5(floats) as that is the desired range
        # I=cv2.getTrackbarPos('I', 'controls')/100    #Getting the D from the trak-bars, D is divided by 100 to convert the range from 0-500(integers) to 0-5(floats) as that is the desired range

        # k=cv2.waitKey(1) & 0xFF
        t+=0.01
        
        
        moveCar(calc_error())

        p.stepSimulation()    #This steps the simulation further by 0.01 seconds approx

        time.sleep(0.01)
        
        # prev_error=error
        # sum_error+=error
        # print(output1)
        pos,  orn = p.getBasePositionAndOrientation(car)

        print(pos)
        # print("running")
        k=cv2.waitKey(1) & 0xFF
        if k == 27:
            print("Episode finished after {} timesteps".format(t+1))
            break


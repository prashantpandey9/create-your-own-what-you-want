#FCFS Algorithm
n= int(input("Enter number of Jobs: "))
cpubc = []
for i in range(n):
    cbc = int(input("Enter cpu burstcycles here : "))
    cpubc.append(cbc)
print("The CPU burstcycles are:", cpubc)
wt = [0]*n
tat = [0]*n
totalwt =0
totaltat = 0
wt[0]=0
for i in range(1,n):
    wt[i] = wt[i-1] + cpubc[i-1]
print("Waiting time is \t",wt)

for i in range(1,n):
    tat[0] = cpubc[0]
    tat[i] = int(wt[i]) + int(cpubc[i])
print("Turn around time is     ", tat)

print("JOBS    Burst_cycle  Waiting Time  Turn Around Time")
for i in range(0,n):
    print(f"{i+1}\t    {cpubc[i]}\t\t   {wt[i]}\t \t  {tat[i]}\t ")

total = 0
for i in range(1,n):
    total += wt[i]
#print("Total waitng time is: ",total)
print("Average of Waiting time is: ", total/n)

totaltat = 0
for i in range(1,n):
    totaltat += tat[i]
#print("Total Turn Around Time is: ",totaltat)
print("Average Turn Around Time is: ", totaltat/n)

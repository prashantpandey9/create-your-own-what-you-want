#Collatz 
def collatz(n):
    while n > 1:
        print(n, end=',')
        if (n % 2):
            # n is odd
            n = 3*n + 1
        else:
            # n is even
            n = n//2
    print(1, end='')
 
 
n = int(input('Enter n: '))
print('Sequence: ', end="")
collatz(n)
print("\n")

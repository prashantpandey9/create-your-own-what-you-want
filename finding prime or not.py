def factor(n):
         l=[]
         for i in range(1,n+1):
                  if n%i==0:
                           w=l.append(i)
         print "Factor of this no. are ",l
         if len(l)==2:
                  print "It is a Prime no.!!"
         else:
                  print "It Is  Not A prime No."
n=int(raw_input("Enter a Prime No."))
factor(n)
 

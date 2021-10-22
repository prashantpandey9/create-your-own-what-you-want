def numConcat(num1, num2):
  
     # find number of digits in num2
     digits = len(str(num2))
  
     # add zeroes to the end of num1
     num1 = num1 * (10**digits)
  
     # add num2 to num1
     num1 += num2
  
     return num1
  
  

print(numConcat(a, b))

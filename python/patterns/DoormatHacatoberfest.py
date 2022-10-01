
def doormatPattern(rows, columns):
    width = columns

    for i in range (0, int (rows / 2)):
        pattern = "|*|" * ((2 * i) + 1)
        print (pattern.center (width, '-'))

    print ("HACKTOBERFEST".center (width, '-'))
     
  
    i = int (rows / 2)
    while i > 0:
        pattern = "|*|" * ((2 * i) - 1)
        print (pattern.center (width, '-'))
        i = i-1
    return
  
rows = int(input("Enter Rows : "))
columns = rows * 3
doormatPattern(rows, columns)
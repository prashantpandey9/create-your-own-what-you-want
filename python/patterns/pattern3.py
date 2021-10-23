n = 7
d = n
for x in range( 1, n+1):
    for y in range( 1, 2*n) :
        if ( ( (y>=d)!=0 and y<=2*n-d) or
             y<=n-d+1 or y>=n+d-1) :
                print( "*", end="")
        else:
            print( " ", end="")

    d -= 1
    print( )
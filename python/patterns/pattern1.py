n=7
d=1
for x in range(1, n + 1):
    for y in range(1, n + 1):
        if y==d or y==n-d+1 or y==1 or y==n:
            print("* ", end="")
        else:
            print("  ", end="")
        
    if x<=n//2:
        d += 1
    else:
        d -= 1
    print()
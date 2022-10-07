def gcd(m,n):
    b, a = min(m,n), max(m,n)
    if a % b == 0:
        return b
    return gcd(b, a % b)
gcd(24,130)

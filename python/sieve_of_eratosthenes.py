from typing import List


def sieve(n: int) -> List[int]:
    """
    >>> sieve(30)
    [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    """
    p = [True] * n
    for i in range(3, int(n**0.5)+1, 2):
        if p[i]:
            p[i*i::2*i] = [False] * int((n-i * i-1)/(2 * i)+1)
    return [2] + [i for i in range(3, n, 2) if p[i]]


if __name__ == "__main__":
    import doctest

    doctest.testmod()
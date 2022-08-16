def power(x, n=2):
    res = 1
    while n > 0:
        res = res * x
        n = n - 1
    return res

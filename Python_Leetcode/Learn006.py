def mul(*args):
    if len(args) > 0:
        s = 1
        for num in args:
            if isinstance(num, (int, float)):
                s = s * num
            else:
                raise TypeError('bad opearate')
        return s
    else:
        raise TypeError('no input')


def move(n, a, b, c):
    if(n == 1):
        print(a, '-->', c)
        return
    return move(n-1, a, c, b)


# 测试
print('mul(5) =', mul(5))
print('mul(5, 6) =', mul(5, 6))
print('mul(5, 6, 7) =', mul(5, 6, 7))
print('mul(5, 6, 7, 9) =', mul(5, 6, 7, 9))
if mul(5) != 5:
    print('测试失败!')
elif mul(5, 6) != 30:
    print('测试失败!')
elif mul(5, 6, 7) != 210:
    print('测试失败!')
elif mul(5, 6, 7, 9) != 1890:
    print('测试失败!')
else:
    try:
        mul()
        print('测试失败!')
    except TypeError:
        print('测试成功!')

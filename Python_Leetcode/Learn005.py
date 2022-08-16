#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from abstest import my_abs
import math

# n1 = 255
# n2 = 1000
# print(str(hex(n1)), hex(n2))
# print(my_abs('9'))


def quadratic(a, b, c):
    if not isinstance(a, (int, float)):
        raise TypeError('bad input')
    temp = math.sqrt(b * b - 4 * my_abs(a) * c)
    x1 = (-b + temp) / (2 * a)
    x2 = (-b - temp) / (2 * a)
    return x1, x2


print('quadratic(2, 3, 1) =', quadratic(2, 3, 1))
print('quadratic(1, 3, -4) =', quadratic(1, 3, -4))

if quadratic(2, 3, 1) != (-0.5, -1.0):
    print('测试失败')
elif quadratic(1, 3, -4) != (1.0, -4.0):
    print('测试失败')
else:
    print('测试成功')

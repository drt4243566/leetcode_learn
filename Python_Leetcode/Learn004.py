#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# for x in range(3)
L = ['Bart', 'Lisa', 'Adam']
# for person in L:
#     print('Hello, %s!' % (person))

# n = 0
# while n < 10:
#     n = n + 1
#     if n % 2 == 0:
#         continue
#     print(n)

d = {'drt': 95, 'yanggong': 65}
print(d['drt'])
d['wubo'] = 99
print(d['wubo'])
print('wubo' in d)
print(d.get('drt'), d.get('xiaoyang', -1))
d.pop('drt')
print(d)

s1 = set([1, 2, 3])
s2 = set([2, 4, 5])
s = s1 & s2
print(s)
s.add(5)
print(s)
s.add('5')
print(s)
s.add([1, 2])
print(s)

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# name = input("pls input your name:\n")
# print('hello', name, '\n')
# print('3>2?', not 3 > 2)
print(ord('A'))
myBytes = 'ABC'.encode('ascii')
myStr = b'ABB'.decode('ascii')
print(myBytes, myStr, len(myStr))
print('myGod %s+%d' % ('Lady', 10086))
print('Hi, {0}, your score is {1}'.format('小子', 59.996))

s1 = 72
s2 = 85
r = (s2-s1)/s1
print('成绩提升了%.1f%%' % (r*100))
print('成绩提升了{0:.1f}%'.format(r*100))
print(f'成绩提升了{r*100:.1f}%')

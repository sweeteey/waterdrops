#!/usr/bin/python3
'''找出字符串中中英文、空格、数字、标点符号个数'''

import string

def str_count(s):
    count_zh = count_en = count_sp = count_dg = count_pu = 0
    for c in s:
        if c in string.ascii_letters:
            count_en += 1
        elif c.isalpha():
            count_zh += 1
        elif c.isspace():
            count_sp += 1
        elif c.isdigit():
            count_dg += 1
        else:
            count_pu += 1
    print("英文字个数:", count_en)
    print("中文字个数:", count_zh)
    print("空格个数:", count_sp)
    print("数字个数:", count_dg)
    print("标点符号个数:", count_pu)

s = input("请输入一个字符串:")
str_count(s)
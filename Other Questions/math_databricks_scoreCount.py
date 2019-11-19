#!/bin/python

import math
import os
import random
import re
import sys



# Complete the compute_number_score function below.
def evenCount(number):
    num = int(number)
    cnt = 0
    if num == 0:
        return 1
    while num > 0:
        reminder = num % 10
        if reminder % 2 == 0:
            cnt += 1
        num = int(num/10)
    return cnt

def count7(number):
    nums = str(number)
    cnt = 0
    for char in nums:
        if char == '7':
            cnt += 1
    return cnt

def count5(number):
    nums = str(number)
    cnt = 0
    for i in range(len(nums)-1):
        if(nums[i] == '5' and nums[i+1] == '5'):
            cnt += 1
    return cnt

def countSequence(number):
    nums = str(number)
    score, start, end = 0, 0, 0
    while end < len(nums)-1:
        if ord(nums[end+1]) == ord(nums[end])-1:
            end += 1
        else:
            score += (end-start+1) * (end-start+1)
            end += 1
            start = end
    score += (end-start+1) * (end-start+1)
    return score

def multipleOf3(number):
    return number % 3 == 0    

def compute_number_score(number):
    score = 0
    score += 1 * count7(number)
    score += 3 * count5(number)
    score += countSequence(number)
    if multipleOf3(number):
        score += 2
    score += 4 * evenCount(number)
    return score

if __name__ == '__main__':
#!/usr/bin/env python3

import numpy as np
import sys

def main():
    array = list(np.random.randint(1000000, size=int(sys.argv[1])))
    print(array)
    array = merge_sort(array)
    print(array)


def merge_sort(arr):
    result = arr

    if len(arr) == 2:
        if arr[0] > arr[1]:
            tmp = arr[0]
            arr[0] = arr[1]
            arr[1] = tmp

    elif len(arr) > 2:
        half = len(arr) // 2
        left = merge_sort(arr[:half])
        right = merge_sort(arr[half:])

        result = merge(left, right)

    return result


def merge(arr_a, arr_b):
    result_arr = []
    a_i = 0
    b_i = 0

    while a_i != len(arr_a) or b_i != len(arr_b):
        if a_i != len(arr_a):
            if b_i != len(arr_b):
                if arr_a[a_i] < arr_b[b_i]:
                    result_arr.append(arr_a[a_i])
                    a_i += 1
                else:
                    result_arr.append(arr_b[b_i])
                    b_i += 1
            else:
                result_arr.append(arr_a[a_i])
                a_i += 1
        else:
            result_arr.append(arr_b[b_i])
            b_i += 1

    return result_arr


if __name__ == '__main__':
    main()

#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt
import math
import sys

def main():
    merge8 = pd.read_csv('csv/merge.csv')
    radix8 = pd.read_csv('csv/radix.csv')
    merge32 = pd.read_csv('csv/merge32.csv')
    radix32 = pd.read_csv('csv/radix32.csv')
    log_array = get_log_array(radix8.shape[0])
    linear_array = get_linear_array(radix8.shape[0])

    plt.plot(merge32['N'], merge32['TIME'], label='merge (32-bit)')
    plt.plot(radix32['N'], radix32['TIME'], label='radix (32-bit)')
    plt.plot(merge8['N'], merge8['TIME'], label='merge (8-bit)')
    plt.plot(radix8['N'], radix8['TIME'], label='radix (8-bit)')
    plt.plot(radix8['N'], log_array, label='N LOG N')
    plt.plot(radix8['N'], linear_array, label='LINEAR')
    # plt.yscale('log')
    # plt.xscale('log')
    plt.xlabel('Array Length (N)')
    plt.ylabel('Runtime (T)')
    plt.legend()
    plt.show()


def get_linear_array(length):
    array = []
    for i in range(0, length):
        array.append(i)
    
    return array


def get_log_array(length):
    array = []
    for i in range(1, length + 1):
        array.append(i * math.log(i, 2))
    
    return array

if __name__ == '__main__':
    main()

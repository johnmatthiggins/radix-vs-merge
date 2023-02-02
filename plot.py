#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt
import sys

def main():
    merge8 = pd.read_csv('csv/merge.csv')
    radix8 = pd.read_csv('csv/radix.csv')
    merge32 = pd.read_csv('csv/merge32.csv')
    radix32 = pd.read_csv('csv/radix32.csv')

    plt.plot(merge32['N'], merge32['TIME'], label='merge (32-bit)')
    plt.plot(radix32['N'], radix32['TIME'], label='radix (32-bit)')
    plt.plot(merge8['N'], merge8['TIME'], label='merge (8-bit)')
    plt.plot(radix8['N'], radix8['TIME'], label='radix (8-bit)')
    plt.yscale('log')
    plt.xscale('log')
    plt.legend()
    plt.show()

if __name__ == '__main__':
    main()

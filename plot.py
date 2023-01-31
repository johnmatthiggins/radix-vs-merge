#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt

def main():
    merge8 = pd.read_csv('merge.csv')
    radix8 = pd.read_csv('radix.csv')
    radix32 = pd.read_csv('radix32.csv')


    plt.plot(radix8['N'], radix8['TIME'], label='radix (8-bit)')
    plt.plot(merge8['N'], merge8['TIME'], label='merge (8-bit)')
    plt.plot(radix32['N'], radix32['TIME'], label='radix (32-bit)')
    plt.xscale('log')
    plt.legend()
    plt.show()

if __name__ == '__main__':
    main()

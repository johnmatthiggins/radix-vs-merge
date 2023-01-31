#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt
import sys

def main():
    # merge8 = pd.read_csv('merge.csv')
    # radix8 = pd.read_csv('radix.csv')
    merge32 = pd.read_csv('merge32.csv')
    radix32 = pd.read_csv('radix32.csv')

    plt.plot(merge32['N'], merge32['TIME'], label='merge (32-bit)')
    plt.plot(radix32['N'], radix32['TIME'], label='radix (32-bit)')
    plt.xscale('log')
    plt.legend()
    plt.savefig('%s.png' %(sys.argv[1]))

if __name__ == '__main__':
    main()

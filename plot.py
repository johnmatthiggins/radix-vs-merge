#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt

def main():
    merge = pd.read_csv('merge.csv')
    radix = pd.read_csv('radix.csv')


    plt.plot(radix['N'], radix['TIME'], label='radix')
    plt.plot(merge['N'], merge['TIME'], label='merge')
    plt.show()

if __name__ == '__main__':
    main()

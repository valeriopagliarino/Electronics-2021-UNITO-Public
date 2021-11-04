from sys import argv
import numpy as np
import pandas as pd

if(len(argv) < 3):
    print("passa come argomenti input file e output file")

data = pd.read_csv(argv[1])
numbers = data.to_numpy().transpose()[1]

np.savetxt(argv[2], numbers)

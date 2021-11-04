from sys import argv
import numpy as np
import pandas as pd

data = pd.read_csv(argv[1])
numbers = data.to_numpy().transpose()[1]

ints = [int(i) for i in numbers]
unique, counts = np.unique(ints, return_counts=True)

for i in zip(range(0,16), counts):
    print(f"{i[0]} : {i[1]}")

from sys import argv
import numpy as np

with open(argv[1]) as file:
    data = file.readlines()

numbers = [float(i[:-1]) for i in data]
ints = [int(i) for i in numbers]

unique, counts = np.unique(ints, return_counts=True)

for i in zip(range(1,16), counts):
    print(f"{i[0]} : {i[1]}")

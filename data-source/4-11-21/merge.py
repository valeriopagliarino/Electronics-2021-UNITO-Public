from sys import argv
import numpy as np
import pandas as pd

tot_data = []
for i in argv[1:]:
    data = pd.read_csv(i).to_numpy().transpose()[1]
    for j in data:
        tot_data.append(j)

np.savetxt("output_merge.txt", np.array(tot_data))

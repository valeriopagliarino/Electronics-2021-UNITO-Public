import pandas as pd
from matplotlib import pyplot as plt
import numpy as np

from utilities import *

data = pd.read_csv('../data-source/28-10-21/calibrazione_dac.csv')

n = data['binario']
v = data['V']

v_err = np.ones(16)*0.1
fit_p, v_fit = linear_fit(n, v, v_err)

stats(n, v, y_err=v_err, y_fit=v_fit, fit_par_values=fit_p, fit_par_names=['m', 'q'])
graph(n, v, y_err=v_err, y_fit=v_fit, title='Calibrazione del DAC', x_label='binario', y_label='V (V)', x_ticks=np.arange(0,16,1), x_tick_labels=[bin(i)[2:] for i in range(16)])

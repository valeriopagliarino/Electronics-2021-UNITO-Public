'''Functions for bode_gain.py'''

import ROOT
from uncertainties import ufloat
import uncertainties.umath as umath
import numpy as np
import pandas as pd


def pair_dat_err(data, errors):
    '''Convert two iterables (pandas Series, lists...) of data/errors
        in a numpy array of uncertainties floats paired'''

    tmp_list = []
    for d, e in zip(data, errors):
        tmp_list.append(ufloat(d, e))

    return np.array(tmp_list)


def uncertainties_to_root_graph_errors(x_de: np.array, y_de: np.array):
    '''Make a ROOT.TGraphErrors from 2 np.arrays of uncertainties.ufloats'''
    
    size = np.size(x_de)

    x_d, y_d, x_e, y_e = [], [], [], []
    
    for i in x_de:
        d,e = i.n, i.s
        x_d.append(d)
        x_e.append(e)

    for j in y_de:
        d,e = j.n, j.s
        y_d.append(d)
        y_e.append(e)


    return ROOT.TGraphErrors(size, np.array(x_d), np.array(y_d), np.array(x_e), np.array(y_e))
    

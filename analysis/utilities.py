'''Functions for analysis'''

import ROOT
from uncertainties import ufloat
import uncertainties.umath as umath
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from scipy.optimize import curve_fit


def pair_dat_err(data, errors):
    '''Convert two iterables (pandas Series, lists...) of data/errors
        in a numpy array of uncertainties floats paired'''

    tmp_list = []
    for d, e in zip(data, errors):
        tmp_list.append(ufloat(d, np.abs(e)))

    return np.array(tmp_list)


def uncertainties_to_root_graph_errors(x_de: np.array, y_de: np.array):
    '''Make a ROOT.TGraphErrors from 2 np.arrays of uncertainties.ufloats'''

    size = np.size(x_de)

    x_d, y_d, x_e, y_e = [], [], [], []

    for i in x_de:
        d, e = i.n, i.s
        x_d.append(d)
        x_e.append(e)

    for j in y_de:
        d, e = j.n, j.s
        y_d.append(d)
        y_e.append(e)

    return ROOT.TGraphErrors(size, np.array(x_d), np.array(y_d), np.array(x_e), np.array(y_e))


def err_dgt(list_data: np.array, percentage: float, dgt_part: float):
    list_errors = list_data * percentage / 100. + dgt_part
    return list_errors


def chi(list_data: np.array, list_err: np.array, list_exp: np.array):
    '''Calculate chi squared for a list of data and expected values'''
    tot = ((list_data-list_exp) / list_err)**2
    return tot

def lin_func(x, m, q):
    '''1st grade pol'''
    return q + m*x

def linear_fit(x, y, y_err):
    '''Fit data with a 1st grade pol, and return parameters'''
    fit_p, cov = curve_fit(lin_func, x, y, sigma=y_err)
    fitted = lin_func(x, fit_p[0], fit_p[1])

    q = ufloat(fit_p[0], np.sqrt(cov[0][0]))
    m = ufloat(fit_p[1], np.sqrt(cov[1][1]))

    return (q,m), fitted


def graph(x, y, x_err=None, y_err=None, y_fit=None, curve_label='dati sperimentali', fit_label = 'fit', title='', x_label='', y_label='', x_ticks=None, y_ticks=None, x_tick_labels=None):
    '''Draw errorbar and if present a fit curve'''
    fig, ax = plt.subplots(figsize=(6, 8))

    ax.set_title(title)
    ax.set_xlabel(x_label)
    ax.set_ylabel(y_label)


    if (x_ticks is not None):
        ax.set_xticks(x_ticks)

    if (x_tick_labels is not None):
        ax.set_xticklabels(x_tick_labels)


    if (y_ticks is not None):
        ax.set_yticks(y_ticks)

    ax.errorbar(x, y, xerr=x_err, yerr=y_err, label=curve_label, fmt='.', color='black')

    if(y_fit is not None):
        ax.plot(x, y_fit, label=fit_label, c='blue')


    ax.legend()
    ax.grid()

    plt.show()


def stats(x, y, x_err=None, y_err=None, y_fit=None, title=["x", "x_err", "y", "y_err", "y_fit", "chi^2"], fit_par_names=[], fit_par_values=[]):
    '''Print data, fit parameters and chi squared'''
    c = chi(y, y_err, y_fit)

    df = pd.DataFrame({
        title[0]: x,
        title[1]: x_err,
        title[2]: y,
        title[3]: y_err,
        title[4]: y_fit,
        title[5]: c
    })

    print('\nData')
    print(df)

    if (y_fit is not None):
        print('\nFit parameters')
        for i,j in zip(fit_par_names, fit_par_values):
            print(f"{i} = {j}")

        print(f'Chi tot = {c.sum()}')

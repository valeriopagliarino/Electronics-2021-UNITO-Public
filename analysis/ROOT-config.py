# exec(open("./configure.py").read())

import os
print("Start config for JupyROOT Env. on Google Coolab - It takes about 3 minutes")
print("WGET...")
os.system("wget https://github.com/MohamedElashri/HEP-ML/releases/download/ROOT/ROOT.tar.zip > /dev/null")
print("Done.")
#Se questo ^^ non dovesse risultare esistente oppure modificato, ne esiste una copia sul LaCie D2 in Collegio. Ringraziamo Mohamed Elashri.
print("UNZIP...")
os.system("unzip /content/ROOT.tar.zip > /dev/null")
print("TAR...")
os.system("tar -xf  ROOT.tar  > /dev/null")
print("APT...")
os.system("apt-get install git dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev tar gfortran subversion > /dev/null")
os.system("install root_numpy") # optional if you want to convert Trees to numpy arrays and other things like that

print("Installation completed.")

import sys
sys.path.append("/content/root_build/")
sys.path.append("/content/root_build/bin/")
sys.path.append("/content/root_build/include/")
sys.path.append("/content/root_build/lib/")
import ctypes
ctypes.cdll.LoadLibrary('/content/root_build/lib//libCore.so')
ctypes.cdll.LoadLibrary('/content/root_build/lib//libThread.so')
ctypes.cdll.LoadLibrary('/content/root_build/lib//libTreePlayer.so')

print("Shared objects loaded.")
import ROOT
print("Completed!")

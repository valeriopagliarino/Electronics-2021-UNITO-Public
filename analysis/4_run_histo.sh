#!/bin/bash

root -l -e "gSystem->Load(\"/usr/local/lib/libsugodata.so\");" -e ".x 4_hist_arduino.cpp"

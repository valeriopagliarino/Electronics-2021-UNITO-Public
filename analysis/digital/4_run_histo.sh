#!/bin/bash

root -l -e "gSystem->Load(\"/usr/local/lib/libsugodata.so\");" -e ".x hist_arduino.cpp($1)"

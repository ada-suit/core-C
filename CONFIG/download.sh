#!/usr/bin/env bash

# change directories
cd ~/adasrc/

# clear old builds
make clean

# compile code
make self

# run the program
sudo -u ada ./bin

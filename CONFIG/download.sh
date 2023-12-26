#!/usr/bin/env bash

# change directories
cd ~/adasrc/

# clear old builds
echo -e "\nClean\n==============="
make clean

# compile code
echo -e "\nCompile\n==============="
make self

# run the program
echo -e "\nRun\n==============="
sudo -u ada ./bin

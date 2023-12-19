#!/usr/bin/env bash

# change directories
cd ~/pulse/

# clear old builds
make clean

# compile code
make self

# run the program
sudo -u wlp ./wavelinkPulse


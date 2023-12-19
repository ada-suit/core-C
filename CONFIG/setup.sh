#!/usr/bin/env bash

# Directory Structure
mkdir ~/arasrc
cd ~/arasrc
mkdir logs src saves lib

# download.sh script
sudo curl -o ./download.sh https://raw.githubusercontent.com/karshPrime/ada/main/CONFIG/download.sh
chmod +x ./download.sh

# Get Service file
sudo curl -o /etc/systemd/system/adad.service https://raw.githubusercontent.com/karshPrime/ada/main/CONFIG/adad.service

# Start and enable the service file
sudo systemctl enable adad.service
sudo systemctl start adad.service

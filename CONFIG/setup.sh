#!/usr/bin/env bash

# Directory Structure
mkdir ~/pulse
cd ~/pulse
mkdir logs src saves lib

# download.sh script
sudo curl -o ./download.sh https://raw.githubusercontent.com/karshPrime/wavelinkPulse/main/CONFIG/download.sh
chmod +x ./download.sh

# Get Service file
sudo curl -o /etc/systemd/system/wavelinkPulse.service https://raw.githubusercontent.com/karshPrime/wavelinkPulse/main/CONFIG/wavelinkPulse.service

# Start and enable the service file
sudo systemctl enable wavelinkPulse.service
sudo systemctl start wavelinkPulse.service

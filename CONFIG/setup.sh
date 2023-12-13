#!/usr/bin/env bash

# Directory Structure
mkdir ~/pulse
cd ~/pulse
mkdir logs src saves lib

# Get Service file
sudo curl -o /etc/systemd/system/wavelinkPulse.service https://raw.githubusercontent.com/karshPrime/wavelinkPulse/main/CONFIG/wavelinkPulse.service

# Start and enable the service file
sudo systemctl enable wavelinkPulse.service
sudo systemctl start wavelinkPulse.service

#!/usr/bin/env bash

# Create the User
sudo adduser wlp --disabled-password --no-create-home

# Modify User Shell
sudo usermod -s /sbin/nologin wlp

# Grant Execute Permissions
sudo chmod o+x ~/pulse

# Grant Read/Write Permissions
sudo chmod o+rwX ~/pulse/logs
sudo chmod o+rwX ~/pulse/saves

# Grant Library Dependencies Access
sudo chmod -R o+rX ~/pulse/lib
sudo chmod -R o+rX ~/pulse/src
sudo chmod -R o+rX /usr/bin

# Ensure $USER Still Has Full Control:
sudo chown -R $USER:$USER ~/pulse

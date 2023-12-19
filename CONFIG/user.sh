#!/usr/bin/env bash

# Create the User
sudo adduser ada --disabled-password --no-create-home

# Modify User Shell
sudo usermod -s /sbin/nologin ada

# Grant Execute Permissions
sudo chmod o+x ~/adasrc

# Grant Read/Write Permissions
sudo chmod o+rwX ~/adasrc/logs
sudo chmod o+rwX ~/adasrc/saves

# Grant Library Dependencies Access
sudo chmod -R o+rX ~/adasrc/lib
sudo chmod -R o+rX ~/adasrc/src
sudo chmod -R o+rX /usr/bin

# Ensure $USER Still Has Full Control:
sudo chown -R $USER:$USER ~/adasrc

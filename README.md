# Adaptive Device Assistant (A.D.A.)

## Overview

The Adaptive Device Assistant (A.D.A.) is a Raspberry Pi-based project focused on system programming, GPIO interfacing, and remote communication. The project aims to create a flexible and intelligent device that can adapt to different scenarios through the use of sensors, buttons, LEDs, and remote control mechanisms.

## Features 

- GPIO Port Control: Interact with Raspberry Pi GPIO ports to manage buttons and LEDs.
- Sensor Integration: Expand functionality by incorporating various sensors in future updates.
- Telegram Bot Interface: Control and monitor the device remotely using a Telegram bot.
- SSH Communication: Enable the Raspberry Pi to trigger actions on a remote machine based on sensor data.

\* full set of features (planned and added) can be viewed at the [Project Board](https://github.com/users/karshPrime/projects/6/views/1).

## Getting Started

### Prerequisites

- Raspberry Pi running GNU/Linux (distro doesn't matter*)
- Secure Shell (SSH) access to the Raspberry Pi
- Active Internet connection

### Installation

To simplify the installation process, a [setup script](./CONFIG/setup.sh) is provided, that configures the Raspberry Pi in accordance to this project's needs. This script takes care of all dependencies, systemd services and system users.

Additional instructions on setting up the Raspberry Pi can be found [here](./CONFIG/README.md).



## Project Progress

To track the progress of the project and view the backlog, refer to the [GitHub Project Board](https://github.com/users/karshPrime/projects/6/views/1). This board provides an overview of upcoming tasks, features in progress, and those completed.

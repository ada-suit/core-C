# Adaptive Digital Assistant (A.D.A.)

## Overview

The Adaptive Digital Assistant (A.D.A.) is a Raspberry Pi-based project focused on system programming, GPIO interfacing, and remote communication. The project aims to create a flexible and intelligent device that can adapt to different scenarios through the use of sensors, buttons, LEDs, and remote control mechanisms.

While I aim to include all planned functionalities, my main focus is to improve my C coding skills and hands-on experience with hardware. To achieve this, I'll minimize the use of external libraries, opting for my self implementations. However, I will follow the standard C style, avoiding creating a unique style.

## Features 

- GPIO Port Control: Interact with Raspberry Pi GPIO ports to manage buttons and LEDs.
- Sensor Integration: Expand functionality by incorporating various sensors in future updates.
- Telegram Bot Interface: Control and monitor the device remotely using a Telegram bot.
- SSH Communication: Enable the Raspberry Pi to trigger actions on a remote machine based on sensor data.

\* full set of features (planned and added) can be viewed at the [Project Board](https://github.com/users/karshPrime/projects/6/views/1).

> PS: In the [project board](https://github.com/users/karshPrime/projects/6/views/1), click on a card's title (especially for cards in **In Progress**, **In Review**, and **Done**) to get more information about it's specifics.

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


## Decisions

I prioritize clear and readable code. Comments throughout the code explain statement purposes. Additionally, a list below provides explanations for specific decisions marked with comments like `// [num]`.

### main.c

<details>
<summary> [1] Button Initialization Optimization </summary>
For buttons, I store the array size in button_count to cut down on computational overhead in the main loop. This optimizes performance by avoiding repetitive calls to component_total() within each iteration. This choice minimizes redundant instructions by saving the array size once and reusing it, focusing solely on button state and value checks during the loop. 
<br>This optimization is exclusive to buttons, as LEDs and buzzers lack similar state or value considerations.
</details>

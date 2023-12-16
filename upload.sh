#!/usr/bin/env bash

# copy files
scp -r ./src/* core3b+:~/pulse/src/.
scp -r ./lib/* core3b+:~/pulse/lib/.

# call download script
ssh core3b+ 'sh ~/pulse/download.sh'


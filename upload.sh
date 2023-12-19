#!/usr/bin/env bash

# copy files
scp -r ./src/* core3b+:~/adasrc/src/.
scp -r ./lib/* core3b+:~/adasrc/lib/.

# call download script
ssh core3b+ 'sh ~/adasrc/download.sh'

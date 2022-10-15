#!/bin/bash

VM_ID='192.168.56.6'
if [ ! -z "$1" ]; then
    VM_ID="$1"
fi

actual_level=$(basename "$(pwd)" | grep --max-count=1 '^level0[0-9]$' | head --lines=1 | sed 's/level0\([0-9]\)/\1/g')

if [ -z "${actual_level}" ]; then
    exit 1
fi
previous_level=$((${actual_level} - 1))

cat ../level0${previous_level}/flag
echo

ssh level0${actual_level}@${VM_ID} -p 4242

#https://42born2code.slack.com/archives/C7NF60E0Z/p1635519655151500?thread_ts=1635518586.151200&cid=C7NF60E0Z
#https://42born2code.slack.com/archives/C7NF60E0Z/p1650404494708309?thread_ts=1650403796.922179&cid=C7NF60E0Z

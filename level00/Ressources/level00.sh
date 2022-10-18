#!/bin/bash

VM_ID=$(cat ../../ip)
if [ ! -z "$1" ]; then
    VM_ID="$1"
fi
ACTUAL_LEVEL=$(echo "$0" | grep --only --color=never --max-count=1 "level[0-9][0-9].sh" | head --lines=1 | grep --only --color=never --max-count=1 '[0-9]' | head --lines=1)

if [ -z "${ACTUAL_LEVEL}" ]; then
    echo "cannot get the level number of the actua level"
    exit 1
fi

act_level_password="level00"

flag=""
cnt=0
while [ -z "${flag}" ] && [ "${cnt}" -lt 20 ]
do
    flag=$(sshpass -p "${act_level_password}" ssh level0${ACTUAL_LEVEL}@${VM_ID} -p 4242 'echo -e "5276\n" > /tmp/level00_password ; echo "cat /home/users/level01/.pass" > /tmp/level00_cmd ; cat /tmp/level00_password /tmp/level00_cmd | ./level00' 2> /dev/null | grep --max-count=1 '^[a-zA-Z0-9]\{40\}$' | head --line=1)

    let cnt++
done



#sshpass -p "${act_level_password}" ssh level0${ACTUAL_LEVEL}@${VM_ID} -p 4242 'cat /tmp/level00_password /tmp/level00_cmd | ./level00' 2> /dev/null

echo -e "FLAG:\n${flag}"

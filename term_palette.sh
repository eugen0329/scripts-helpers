#!/bin/bash

text='Abc'
delim='     '
empty='   '


nocolor="\033[0m"
fgs=(
  'm' '1m' '30m' '1;30m' '31m' '1;31m' '32m'
  '1;32m' '33m' '1;33m' '34m' '1;34m' '35m'
  '1;35m' '36m' '1;36m' '37m' '1;37m'
)
for h in {40..47}; do bgs+=(${h}m); done

echo "     ${delim}${empty}${delim}$(for h in "${bgs[@]}"; do echo -n "$h$delim";done)"

for fg in "${fgs[@]}" ; do
  printf " %5s \033[$fg   $text  " $fg
  for bg in "${bgs[@]}" ; do echo -en " \033[$fg\033[$bg  $text  $nocolor"; done
  echo
done


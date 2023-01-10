#!/bin/bash
cat /etc/passwd | sed '/^#/d' | awk 'NR%2==0' | awk -F ':*' '{print $1}'  | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2"p | paste -s -d, - | sed 's/, */, /g' | tr '\n' '.'

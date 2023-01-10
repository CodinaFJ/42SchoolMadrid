#!/bin/bash
echo "obase=13; $(echo $(echo "ibase=5; $(echo $FT_NBR1 | tr "\'\"\?\!" "0234" | tr "\\" "1")" | bc) + $(echo "ibase=5; $(echo $FT_NBR2 | tr "mrdoc" "01234")" | bc) | bc)" | bc | tr "01234" "gtaio" | tr "5" " " | tr "6789ABC" "luSnemf"

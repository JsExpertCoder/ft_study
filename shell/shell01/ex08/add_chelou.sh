#!/bin/sh

echo $FT_NBR1 + $FT_NBR2 | sed "s/\'/0/g" | tr '\\\"\?\!' 1234 | tr 'mrdoc' 01234 | xargs echo 'obase=13; ibase=5;' | bc | tr '0123456789ABC' 'gtaio luSnemf'

# echo $FT_NBR1 + $FT_NBR2 | sed 's/\\/1/g' | sed 's/?/3/g' | sed 's/!/4/g' | sed "s/\'/0/g" | sed "s/\"/2/g" | tr "mrdoc" "01234" | xargs echo "ibase=5; obase=23;" | bc | tr "0123456789ABC" "gtaio luSnemf"

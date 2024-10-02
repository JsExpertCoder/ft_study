#!/bin/sh

id -Gn $FT_USER | tr ' ' ',' | tr -d '\n'

#echo -n $(id -Gn $FT_USER | tr ' ' ',')


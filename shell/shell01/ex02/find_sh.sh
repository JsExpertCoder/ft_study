#!/bin/sh

find . -type f -name '*.sh' -execdir basename '{}' .sh \;
# basename -s ".sh" $(find . -name "*.sh") 

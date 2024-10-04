#!/bin/sh

ls -l | awk '{if (NR % 2 != 0) print $0}'

# ls -l | awk 'NR % 2 == 1'
# ls -l | sed -n  'p;n'

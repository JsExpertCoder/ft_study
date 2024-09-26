#!/bin/bash
git log --format="%H" -5
#git log --pretty=oneline -n 5 | cut -d' ' -f1
#git log -5 | grep commit | cut -d' ' -f2

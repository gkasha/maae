#!/bin/bash

shopt -s expand_aliases
source ~/.bash_aliases

src_maae; ros2 run auction agent $1 $2 $3 $4

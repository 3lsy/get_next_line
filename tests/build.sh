#!/usr/bin/bash

cc -Wall -Wextra -Werror -I../ -D BUFFER_SIZE=10000000 ../get_next_line.c ../get_next_line_utils.c test.c

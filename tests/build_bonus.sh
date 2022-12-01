#!/usr/bin/bash

cc -Wall -Wextra -Werror -I../ -D BUFFER_SIZE=10000000 ../get_next_line_bonus.c ../get_next_line_utils_bonus.c test_bonus.c

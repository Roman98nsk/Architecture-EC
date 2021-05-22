#pragma once
#include "myTerm.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define RECTANGLE "a"
#define RIGHT_BOTTOM_CORNER "j"
#define LEFT_BOTTOM_CORNER "m"
#define RIGHT_UPPER_CORNER "k"
#define LEFT_UPPER_CORNER "l"
#define VERTICAL "x"
#define HORIZONTAL "q"

int bc_printA(char *str);
int bc_box(int x1, int y1, int x2, int y2);
int bc_printbigchar(int *big, int x, int y, enum colors fg, enum colors bg);
int bc_setbigcharpos(int *big, int x, int y, int value);
int bc_getbigcharpos(int *big, int x, int y, int *value);
int bc_bigcharwrite(int fd, int *big, int count);
int bc_bigcharread(int fd, int *big, int need_count, int *count);

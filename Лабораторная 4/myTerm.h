#pragma once

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

enum colors {
  cl_black,
  cl_red,
  cl_green,
  cl_brown,
  cl_blue,
  cl_magenta,
  cl_cyan,
  cl_light_blue,
  cl_default,
  cl_white
};

void mt_clrscr();
int mt_gotoXY(int x, int y);
int mt_getscreensize(int *rows, int *cols);
int mt_setfgcolor(enum colors);
int mt_setbgcolor(enum colors);

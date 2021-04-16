#ifndef MYTERM_H
#define MYTERM_H

#include <stdio.h>
#include <sys/ioctl.h>

enum colors {
  MT_BLACK,
  MT_RED,
  MT_GREEN,
  MT_YELLOW,
  MT_BLUE,
  MY_VIOLET,
  MT_BIRUZ,
  MT_WHITE,
  MT_DEFAULT = 0
};

int mt_clrscr(void);
int mt_gotoXY(int str, int stl);
int mt_getscreensize(int *rows, int *cols);
int mt_setfgcolor(enum colors color);
int mt_setbgcolor(enum colors color);

#endif

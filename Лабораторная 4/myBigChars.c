#include "myBigChars.h"

int bc_printA(char *str) {
  printf("\E(0%s\E(B", str);
  return 0;
}

int bc_box(int x1, int y1, int x2, int y2) {

  for (int i = x1; i < x1 + x2; i++) {
    mt_gotoXY(i, y1);
    bc_printA(HORIZONTAL);
    mt_gotoXY(i, y1 + y2);
    bc_printA(HORIZONTAL);
  }
  for (int i = y1; i < y1 + y2; i++) {
    mt_gotoXY(x1, i);
    bc_printA(VERTICAL);
    mt_gotoXY(x1 + x2, i);
    bc_printA(VERTICAL);
  }
  mt_gotoXY(x1, y1);
  bc_printA(LEFT_UPPER_CORNER);
  mt_gotoXY(x1 + x2, y1);
  bc_printA(RIGHT_UPPER_CORNER);
  mt_gotoXY(x1 + x2, y1 + y2);
  bc_printA(RIGHT_BOTTOM_CORNER);
  mt_gotoXY(x1, y1 + y2);
  bc_printA(LEFT_BOTTOM_CORNER);
  return 0;
}

int bc_printbigchar(int *big, int x, int y, enum colors fg, enum colors bg) {

  int pos, bit;
  int i, j;
  char row[9];
  row[8] = '\0';
  mt_setfgcolor(fg);
  mt_setbgcolor(bg);
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      pos = i >> 2;
      bit = (big[pos] >> ((i % 4) * 8 + j)) & 1;
      if (bit == 0)
        row[j] = ' ';
      else
        row[j] = *RECTANGLE;
    }
    mt_gotoXY(x, y + i);
    bc_printA(row);
  }
  mt_setfgcolor(cl_default);
  mt_setbgcolor(cl_default);
  return 0;
}

int bc_getbigcharpos(int *big, int x, int y, int *value) {
  if (x < 0 || x > 7 || y < 0 || y > 7) {
    return -1;
  }
  int ind = 0;
  if (x > 3) {
    ind = 1;
  }
  *value = ((big[ind] >> (x * 8)) >> y) & 1;
  return 0;
}

int bc_setbigcharpos(int *big, int x, int y, int value) {
  if (x < 0 || x > 7 || y < 0 || y > 7 || value > 1 || value < 0) {
    return -1;
  }
  int ind = 0;
  if (x > 3) {
    ind = 1;
  }
  if (value == 1) {
    big[ind] |= 1 << (x * 8 + y);
  } else if (value == 0) {
    big[ind] &= ~(1 << (x * 8 + y));
  }
  return 0;
}

int bc_bigcharwrite(int fd, int *big, int count) {
  int check = write(fd, big, sizeof(int) * count);
  if (check == -1) {
    return -1;
  }
  return 0;
}

int bc_bigcharread(int fd, int *big, int need_count, int *count) {
  *count = read(fd, big, sizeof(int) * need_count);

  if (*count == -1) {
    *count = 0;
    return -1;
  }
  return 0;
}

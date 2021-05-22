#include "myTerm.h"

int main() {
  char str;
  int tmp, tmp2;
  mt_clrscr();
  mt_getscreensize(&tmp, &tmp2);
  printf("Test 2: termsize %d,%d\n", tmp, tmp2);
  mt_gotoXY(5, 10);
  mt_setfgcolor(MT_RED);
  mt_setbgcolor(MT_BLACK);
  printf("I'm: Yaroshev Roman\n");
  mt_gotoXY(6, 8);
  mt_setfgcolor(MT_GREEN);
  mt_setbgcolor(MT_WHITE);
  printf("IV-921\n");

  mt_setfgcolor(MT_DEFAULT);
  mt_setbgcolor(MT_DEFAULT);
  printf("\n");

  return 0;
}

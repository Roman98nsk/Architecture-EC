#include "myTerm.h"

/*
 * mt_clrscr (void)
 ------------------
 * производит очистку и перемещение курсора
 * в левый верхний угол экрана
 * команда: echo -e "\033["
 * команда: echo -e "\033[0|1|2|J" - очистка всего экрана
*/

int mt_clrscr(void) {
  printf("\E[H\E[J");
  return 0;
}

/*
 * mt_gotoXY (int str, int stl)
 ------------------------------
 * Перемещает курсор в указанную позицию.
 * str - номер строки;
 * stl - номер столбца.
 * команда: echo -e "\033[10;30H"
*/

int mt_gotoXY(int str, int stl) {
  printf("\E[%d;%dH", str, stl);
  return 0;
}

/*
 * mt_getscreensize (int *rows, int *cols)
 -----------------------------------------
 * определяет размер экрана терминала
 * (кол-во строк, столбцов)
*/

int mt_getscreensize(int *rows, int *cols) {
  struct winsize ws;
  ioctl(1, TIOCGWINSZ, &ws);
  *rows = ws.ws_row;
  *cols = ws.ws_col;

  return 0;
}

/*
 * mt_setfgcolor (enum colors color)
 ------------------------------
 * Устанавливает цвет последующих выводимых символов.
 * В кач-ве параметра передается константа из созданного
 * Вами перечислимого типа colors, описывающего цвета
 * терминала
 * команда: echo -e "\033[31mTEST" - красный цвет шрифта
 * команда: echo -e "\033[31mTEST\033[0m" - цвет по умолчанию
*/

int mt_setfgcolor(enum colors color) {
  printf("\E[3%dm", color);
  return 0;
}

/*
 * mt_setbcolor (enum colors color)
 ----------------------------
 * Устанавливает цвет фона послед-их
 * выводимых символов. В кач-ве параметра передается
 * константа из созданного Вами перечислимого типа cоlors,
 * описывающего цвет терминала
*/

int mt_setbgcolor(enum colors color) {
  printf("\E[4%dm", color);
  return 0;
}

#ifndef NCURSES_HELPERS_H
#define NCURSES_HELPERS_H

#include <ncurses.h>

WINDOW *createWindow(int y, int x, int height, int width);
void printTextInArea(WINDOW *win, int y, int x, int height, int width, const char *text);

#endif

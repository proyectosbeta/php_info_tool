#include <ncurses.h>
#include "../include/ncurses_helpers.h"

WINDOW *createWindow(int y, int x, int height, int width)
{
    WINDOW *win = newwin(height, width, y, x);
    refresh();
    return win;
}

void printTextInArea(WINDOW *win, int y, int x, int height, int width, const char *title, const char *text)
{
    box(win, 0, 0);
    mvwprintw(win, y, x + 15, "%s", title);
    mvwprintw(win, y + 2, x + 2, "%s", text);
    wrefresh(win);
}

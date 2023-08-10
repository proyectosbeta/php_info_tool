#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/php_info.h"
#include "../include/opcache_info.h"
#include "../include/ncurses_helpers.h"

typedef struct
{
    int y, x, height, width;
    const char *title;
    const char *text;
} AreaSection;

int main()
{
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Configure the ncurses window
    int height = LINES - 4, width = COLS - 4;
    int top_height = height / 2, bottom_height = (height - top_height);

    // Get information from PHP
    char phpVersion[200];
    getPhpVersion(phpVersion, sizeof(phpVersion));

    // Get opcache information
    char opCacheInfo[200];
    getOpcacheInfo(opCacheInfo, sizeof(opCacheInfo));

    AreaSection sections[] = {
        {2, 2, top_height, width, " PHP Information ", phpVersion},
        {2 + top_height, 2, bottom_height, width / 2, " Opcache Information ", opCacheInfo},
        {2 + top_height, 4 + width / 2, bottom_height, width / 2, " Opcache Xdebug ", "Xdebug"}};

    // Create and display the areas
    for (int i = 0; i < sizeof(sections) / sizeof(sections[0]); i++)
    {
        WINDOW *win = createWindow(sections[i].y, sections[i].x, sections[i].height, sections[i].width);
        printTextInArea(win, 0, 0, sections[i].height, sections[i].width, sections[i].title, sections[i].text);
    }

    // Wait for the user to press the 'q' key to exit
    int ch;
    while ((ch = getch()) != 'q')
    {
        // continue waiting
    }

    // end ncurses
    endwin();

    return 0;
}

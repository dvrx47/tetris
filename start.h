#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <ncurses.h>
#include <unistd.h>
#include <menu.h>

#ifndef start_h
#define start_h

typedef struct pos
{
    int x;
    int y;
} pos;

typedef struct table
{
    int colour;
    pos *coords;
} table;

typedef struct field
{
    bool block;
    int colour;
} field;

int init();
void print_menu(WINDOW *menu_win, int rewers);
int gameMenu();

field **tetrion;

pos *block0;
pos *block1;
pos *block2;
pos *block3;
pos *block4;
pos *block5;
pos *block6;

#endif

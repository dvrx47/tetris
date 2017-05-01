#include "start.h"


char *labels[]=
{
    "Easy",
    "Normal",
    "Hard"
};
int volume= sizeof(labels) / sizeof(char *);

int gameMenu()
{

    int xSize=25, ySize=8;
    WINDOW *menu_win;
    int startx=0;
    int starty=0;
    int xmax, ymax;
    int reverse=0;
    int menuPos=-1;
    int c;

    initscr();
    curs_set(0);
    clear();
    noecho();
    cbreak();
    getmaxyx(stdscr, ymax, xmax);
    startx= (xmax - xSize) / 2;
    starty= (ymax - ySize) / 2;

    menu_win= newwin(ySize, xSize, starty, startx);
    keypad(menu_win, TRUE);
    refresh();
    print_menu(menu_win, reverse);
    while (menuPos==-1)
    {
        c= wgetch(menu_win);
        if (c==KEY_UP)
        {
            reverse=(reverse+volume-1)%volume;
        }
        else if (c==KEY_DOWN)
        {
            reverse=(reverse+1)%volume;
        }
        else if (c=='\n')
        {
            menuPos=reverse;
        }
        print_menu(menu_win, reverse);
    }
    delwin(menu_win);
    endwin();
    return menuPos;
}

void print_menu(WINDOW *menu_win, int reverse)
{
    int x, y;

    x= 10;
    y= 3;
    box(menu_win, 0, 0);
    mvwprintw(menu_win, 1,1, "Choose game level:");
    for (int i=0; i<volume; ++i)
    {
        if (reverse == i)
        {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", labels[i]);
            wattroff(menu_win, A_REVERSE);
        }
        else
        {
            mvwprintw(menu_win, y, x, "%s", labels[i]);
        }
        ++y;
    }
    wrefresh(menu_win);
}

int init()
{
    block0=malloc(4*sizeof(pos));
    {block0[0].x=1; block0[1].x=1; block0[2].x=1; block0[3].x=1; block0[0].y=0; block0[1].y=1; block0[2].y=2; block0[3].y=3;};
    block1=malloc(4*sizeof(pos));
    {block1[0].x=0; block1[1].x=1; block1[2].x=2; block1[3].x=1; block1[0].y=1; block1[1].y=1; block1[2].y=1; block1[3].y=2;};
    block2=malloc(4*sizeof(pos));
    {block2[0].x=1; block2[1].x=2; block2[2].x=1; block2[3].x=2; block2[0].y=1; block2[1].y=1; block2[2].y=2; block2[3].y=2;};
    block3=malloc(4*sizeof(pos));
    {block3[0].x=1; block3[1].x=1; block3[2].x=1; block3[3].x=2; block3[0].y=0; block3[1].y=1; block3[2].y=2; block3[3].y=2;};
    block4=malloc(4*sizeof(pos));
    {block4[0].x=1; block4[1].x=1; block4[2].x=1; block4[3].x=0; block4[0].y=0; block4[1].y=1; block4[2].y=2; block4[3].y=2;};
    block5=malloc(4*sizeof(pos));
    {block5[0].x=0; block5[1].x=1; block5[2].x=1; block5[3].x=2; block5[0].y=1; block5[1].y=1; block5[2].y=2; block5[3].y=2;};
    block6=malloc(4*sizeof(pos));
    {block6[0].x=0; block6[1].x=1; block6[2].x=1; block6[3].x=2; block6[0].y=2; block6[1].y=1; block6[2].y=2; block6[3].y=1;};

    int delay;

    init_pair(1, COLOR_RED, COLOR_BLACK);

    delay=gameMenu();

    if(delay==0) delay=400000;else
    if(delay==1) delay=250000;else
    if(delay==2) delay=100000;

    tetrion=malloc(20*sizeof(field*));
    for(int i=0;i<20;++i)tetrion[i]=calloc(10, sizeof(field));

    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    scrollok(stdscr, TRUE);
    clear();

    int left=30,right=51,down=20;
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(7));

    for(int i=0;i<20;++i)
    {
        mvaddch(i,left,ACS_VLINE);
        mvaddch(i,right,ACS_VLINE);
    }
    mvaddch(down,left,ACS_LLCORNER);
    mvaddch(down,right,ACS_LRCORNER);
    for(int i=left+1;i<right;++i)mvaddch(down,i,ACS_HLINE);

    mvaddch(10,60,ACS_LLCORNER);
    mvaddch(10,71,ACS_LRCORNER);

    mvaddch(4,60,ACS_ULCORNER);
    mvaddch(4,71,ACS_URCORNER);

    for(int i=61;i<71;++i)
    {
        mvaddch(4,i,ACS_HLINE);
        mvaddch(10,i,ACS_HLINE);
    }

    for(int i=5;i<10;++i)
    {
        mvaddch(i,60,ACS_VLINE);
        mvaddch(i,71,ACS_VLINE);
    }

    mvprintw(3,60,"NEXT:");
    mvprintw(0,0,"POINTS:");

    refresh();

    return delay;
}

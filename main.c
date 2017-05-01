#include "tetris.h"


bool kbhit();

int main(void)
{
    srand(time(NULL));
    int delay=init();

    int key;

    int nextBlock=randBlock(), currentBlock, point=0;
    table * block=malloc(sizeof(table));

    int orientation;
    int i;
    do
    {
        orientation=0;
        ++point;
        currentBlock=nextBlock;
        nextBlock=randBlock();
        block=refreshTetrion(currentBlock, nextBlock, point);
        attron(COLOR_PAIR(currentBlock+1));
        while(canFall(block))
        {
            //key service
            //key=wgetch(stdscr);
            i=0;
            moveBlock(block, 0);
            while(kbhit())
            {
                key=getch();
                if(key==KEY_DOWN && canFall(block))moveBlock(block, 0);else
                if(key==KEY_UP && canRotate(block, currentBlock, orientation))rotateBlock(block, currentBlock, &orientation);else
                if(key==KEY_LEFT && canLeft(block)) moveBlock(block, 1);else
                if(key==KEY_RIGHT && canRight(block)) moveBlock(block, 2);
                usleep(delay/10);
                ++i;
                if(i==10)break;
                refresh();
            }
            usleep(delay-i*delay/10);
        }
        point+=bonusPoints();
        freeBlock(block);
    }while(!gameEnd());

    closeGame();
    return 0;
}

bool kbhit()
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

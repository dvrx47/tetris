#include "tetris.h"

void rotateBlock(table *block, int currentBlock, int * orientation)
{
    int repair=37;

    for(int i=0;i<4;++i)
    {
        mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair,' ');
        mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair+1, ' ');
    }

    if(currentBlock==0)
    {
        if(*orientation==0)
        {
            *orientation=1;
            block->coords[0].x = block->coords[2].x-1;
            block->coords[1].x = block->coords[2].x+1;
            block->coords[3].x = block->coords[2].x+2;
            for(int i=0;i<4;++i) block->coords[i].y=block->coords[2].y;
        }else
        if(*orientation==1)
        {
            *orientation=0;
            for(int i=0;i<4;++i) block->coords[i].x=block->coords[2].x;
            block->coords[0].y = block->coords[2].y-2;
            block->coords[1].y = block->coords[2].y-1;
            block->coords[3].y = block->coords[2].y+1;
        }
    }else

    if(currentBlock==1)
    {
        if(*orientation==0)
        {
            *orientation=1;
            --block->coords[2].x;
            --block->coords[2].y;
        }else
        if(*orientation==1)
        {
            *orientation=2;
            ++block->coords[3].x;
            --block->coords[3].y;
        }else
        if(*orientation==2)
        {
            *orientation=3;
            ++block->coords[0].x;
            ++block->coords[0].y;
        }else
        if(*orientation==3)
        {
            *orientation=0;
            --block->coords[0].x;
            --block->coords[0].y;
            --block->coords[3].x;
            ++block->coords[3].y;
            ++block->coords[2].x;
            ++block->coords[2].y;
        }
    }else

    if(currentBlock==3)
    {
        if(*orientation==0)
        {
            *orientation=1;
            --block->coords[0].x;
            ++block->coords[0].y;
            --block->coords[2].x;
            --block->coords[3].y;
        }else

        if(*orientation==1)
        {
            *orientation=2;
            --block->coords[0].y;
            --block->coords[3].x;
            --block->coords[3].y;
            ++block->coords[2].x;
        }else

        if(*orientation==2)
        {
            *orientation=3;
            ++block->coords[0].y;
            ++block->coords[2].x;
            --block->coords[2].y;
            ++block->coords[3].x;
        }else

        if(*orientation==3)
        {
            *orientation=0;
            ++block->coords[0].x;
            --block->coords[0].y;
            --block->coords[2].x;
            ++block->coords[2].y;
            block->coords[3].y+=2;
        }
    }else

    if(currentBlock==4)
    {
        if(*orientation==0)
        {
            *orientation=1;
            ++block->coords[0].x;
            ++block->coords[0].y;
            --block->coords[2].x;
            --block->coords[2].y;
            block->coords[3].y-=2;
        }else

        if(*orientation==1)
        {
            *orientation=2;
            --block->coords[0].x;
            ++block->coords[0].y;
            ++block->coords[2].x;
            --block->coords[2].y;
            block->coords[3].x+=2;

        }else

        if(*orientation==2)
        {
            *orientation=3;
            --block->coords[0].x;
            --block->coords[0].y;
            ++block->coords[2].x;
            ++block->coords[2].y;
            block->coords[3].y+=2;
        }else

        if(*orientation==3)
        {
            *orientation=0;
            ++block->coords[0].x;
            --block->coords[0].y;
            --block->coords[2].x;
            ++block->coords[2].y;
            block->coords[3].x-=2;
        }
    }

    if(currentBlock==5)
    {
        if(*orientation==0)
        {
            *orientation=1;
            ++block->coords[0].x;
            block->coords[0].y+=2;
            ++block->coords[1].x;
        }else
        if(*orientation==1)
        {
            *orientation=0;
            --block->coords[0].x;
            block->coords[0].y-=2;
            --block->coords[1].x;
        }
    }

    if(currentBlock==6)
    {
        if(*orientation==0)
        {
            *orientation=1;
            block->coords[0].x+=2;
            ++block->coords[0].y;
            ++block->coords[3].y;
        }else
        if(*orientation==1)
        {
            *orientation=0;
            block->coords[0].x-=2;
            --block->coords[0].y;
            --block->coords[3].y;
        }
    }

    for(int i=0;i<4;++i)
    {
        mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair, ' '|A_REVERSE);
        mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair+1, ' '|A_REVERSE);
    }

    refresh();
}

bool canRotate(table * block, int currentBlock, int orientation)
{
    if(currentBlock==0)
    {
        if(orientation==0)
        {
            if(block->coords[2].x<-2)return false;
            if(block->coords[2].x>4)return false;
            if(block->coords[2].y>=4)
            {
                if(tetrion[block->coords[2].y-4][block->coords[2].x+2].block==1)return false;
                if(tetrion[block->coords[2].y-4][block->coords[2].x+4].block==1)return false;
                if(tetrion[block->coords[2].y-4][block->coords[2].x+5].block==1)return false;
            }
        }else

        if(orientation==1)
        {
            if(block->coords[2].y>=6)
            {
                if(tetrion[block->coords[2].y-5][block->coords[2].x+3].block==1)return false;
                if(tetrion[block->coords[2].y-6][block->coords[2].x+3].block==1)return false;
                if(tetrion[block->coords[2].y-3][block->coords[2].x+3].block==1)return false;
            }
        }
        return true;
    }else

    if(currentBlock==1)
    {
        if(orientation==0)
        {
            if(block->coords[1].y>=5)
            {
                if(tetrion[block->coords[1].y-3][block->coords[1].x+3].block==1)return false;
            }
        }else

        if(orientation==1)
        {
            if(block->coords[1].x>5)return false;
            if(block->coords[1].y>=4)
            {
                if(tetrion[block->coords[1].y-4][block->coords[1].x+4].block==1)return false;
            }
        }else

        if(orientation==2)
        {
            if(block->coords[1].y>=4)
            {
                if(tetrion[block->coords[1].y-3][block->coords[1].x+3].block==1)return false;
            }
        }else

        if(orientation==3)
        {
            if(block->coords[1].x<-2)return false;
            if(block->coords[1].y>=4)
            {
                if(tetrion[block->coords[1].y-4][block->coords[1].x+2].block==1)return false;
            }
        }
        return true;
    }else

    if(currentBlock==2)
    {
        return false;
    }else

    if(currentBlock==3)
    {
        if(orientation==0)
        {
            if(block->coords[1].x<-2)return false;
            if(block->coords[1].y>=4)
            {
                if(tetrion[block->coords[1].y-4][block->coords[1].x+4].block==1)return false;
                if(tetrion[block->coords[1].y-4][block->coords[1].x+2].block==1)return false;
                if(tetrion[block->coords[1].y-3][block->coords[1].x+2].block==1)return false;
            }
        }else

        if(orientation==1)
        {
            if(block->coords[1].y>=5)
            {
                if(tetrion[block->coords[1].y-3][block->coords[1].x+3].block==1)return false;
                if(tetrion[block->coords[1].y-5][block->coords[1].x+3].block==1)return false;
                if(tetrion[block->coords[1].y-5][block->coords[1].x+2].block==1)return false;
            }
        }else

        if(orientation==2)
        {
            if(block->coords[1].x>5)return false;
            if(block->coords[1].y>=5)
            {
                if(tetrion[block->coords[1].y-5][block->coords[1].x+4].block==1)return false;
                if(tetrion[block->coords[1].y-4][block->coords[1].x+2].block==1)return false;
                if(tetrion[block->coords[1].y-4][block->coords[1].x+4].block==1)return false;
            }
        }else

        if(orientation==3)
        {
            if(block->coords[1].y>=5)
            {
                if(tetrion[block->coords[1].y-3][block->coords[1].x+3].block==1)return false;
                if(tetrion[block->coords[1].y-3][block->coords[1].x+4].block==1)return false;
                if(tetrion[block->coords[1].y-5][block->coords[1].x+3].block==1)return false;
            }
        }
        return true;
    }else

    if(currentBlock==4)
    {
        if(orientation==0)
        {
            if(block->coords[1].x>5)return false;
            if(block->coords[1].y>=5)
            {
                if(tetrion[block->coords[1].y-4][block->coords[1].x+4].block==1)return false;
                if(tetrion[block->coords[1].y-4][block->coords[1].x+2].block==1)return false;
                if(tetrion[block->coords[1].y-5][block->coords[1].x+2].block==1)return false;
            }
        }else

        if(orientation==1)
        {
            if(block->coords[1].y>=5)
            {
                if(tetrion[block->coords[1].y-5][block->coords[1].x+3].block==1)return false;
				if(tetrion[block->coords[1].y-5][block->coords[1].x+4].block==1)return false;
				if(tetrion[block->coords[1].y-3][block->coords[1].x+3].block==1)return false;
            }
        }else

        if(orientation==2)
        {
            if(block->coords[1].x<-2)return false;
            if(block->coords[1].y>=4)
            {
                if(tetrion[block->coords[1].y-4][block->coords[1].x+2].block==1)return false;
				if(tetrion[block->coords[1].y-4][block->coords[1].x+4].block==1)return false;
				if(tetrion[block->coords[1].y-3][block->coords[1].x+4].block==1)return false;
            }
        }else

        if(orientation==3)
        {
            if(block->coords[1].y>=5)
            {
                if(tetrion[block->coords[1].y-5][block->coords[1].x+3].block==1)return false;
				if(tetrion[block->coords[1].y-3][block->coords[1].x+3].block==1)return false;
				if(tetrion[block->coords[1].y-3][block->coords[1].x+2].block==1)return false;
            }
        }
        return true;
    }else

    if(currentBlock==5)
    {
        if(orientation==0)
        {
            if(block->coords[2].y>=5)
            {
                if(tetrion[block->coords[2].y-3][block->coords[2].x+3].block==1)return false;
				if(tetrion[block->coords[2].y-5][block->coords[2].x+4].block==1)return false;
            }
        }else

        if(orientation==1)
        {
            if(block->coords[2].x<-2)return false;
            if(block->coords[2].y>=5)
            {
                if(tetrion[block->coords[2].y-5][block->coords[2].x+3].block==1)return false;
				if(tetrion[block->coords[2].y-5][block->coords[2].x+2].block==1)return false;
            }
        }
        return true;
    }else

    if(currentBlock==6)
    {
        if(orientation==0)
        {
            if(block->coords[2].y>=4)
            {
                if(tetrion[block->coords[2].y-4][block->coords[2].x+4].block==1)return false;
				if(tetrion[block->coords[2].y-3][block->coords[2].x+4].block==1)return false;
            }
        }else

        if(orientation==1)
        {
            if(block->coords[2].x<-2)return false;
            if(block->coords[2].y>=5)
            {
                if(tetrion[block->coords[2].y-4][block->coords[2].x+2].block==1)return false;
				if(tetrion[block->coords[2].y-5][block->coords[2].x+4].block==1)return false;
            }
        }
        return true;
    }
    return false;
}

int bonusPoints()
{
    int point=0;
    int err;

    for(int i=1;i<20;++i)
    {
        err=0;
        for(int k=0; k<10; ++k) if(tetrion[i][k].block==0){err=1; break;}

        if(err==0)
        {
            point+=10;
            for(int k=0;k<10;++k)
            {
                for(int h=i;h>0;--h)
                {
                    if(tetrion[h-1][k].block==1)
                    {
                        attron(COLOR_PAIR(tetrion[h-1][k].colour));
                        mvaddch(h,2*k+31,' '|A_REVERSE);
                        mvaddch(h,2*k+32,' '|A_REVERSE);
                    }
                    else
                    {
                        mvaddch(h,2*k+31,' ');
                        mvaddch(h,2*k+32,' ');
                    }
                    tetrion[h][k].block=tetrion[h-1][k].block;
                    tetrion[h][k].colour=tetrion[h-1][k].colour;
                }
            }
        }
    }
    refresh();
    return point;
}

bool canRight(table * block)
{
    for(int i=0;i<4;++i)if(block->coords[i].x>5) return false;
    for(int i=0;i<4;++i)
    {
        if(block->coords[i].y>3) if(tetrion[block->coords[i].y-4][block->coords[i].x+4].block==1) return false;
    }
    return true;
}

bool canLeft(table * block)
{
    for(int i=0;i<4;++i)if(block->coords[i].x<-2) return false;
    for(int i=0;i<4;++i)
    {
        if(block->coords[i].y>3) if(tetrion[block->coords[i].y-4][block->coords[i].x+2].block==1) return false;
    }
    return true;
}

bool canFall(table * block)
{
    bool err=0;
    for(int i=0;i<4;++i)
    {
        if(block->coords[i].y==23) err=1;
        else if(block->coords[i].y>3) if(tetrion[block->coords[i].y-3][block->coords[i].x+3].block==1) err=1;
        if(err)
        {
            for(int i=0;i<4;++i)
            {
                if(block->coords[i].y>3)
                {
                    tetrion[block->coords[i].y-4][block->coords[i].x+3].block=1;
                    tetrion[block->coords[i].y-4][block->coords[i].x+3].colour=block->colour;
                }
            }
            return 0;
        }
    }

    return 1;
}

void moveBlock(table * block, int direction)
{
    int repair=37;

    if(direction==0)
    {
        for(int i=0;i<4;++i)
        {
            mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair,' ');
            mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair+1, ' ');
            ++block->coords[i].y;
        }

        for(int i=0;i<4;++i)
        {
            mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair, ' '|A_REVERSE);
            mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair+1, ' '|A_REVERSE);
        }
        refresh();
        return;
    }

    int temp;
    if(direction==1) temp=-1;
    if(direction==2) temp=1;

    for(int i=0;i<4;++i)
    {
        mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair,' ');
        mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair+1, ' ');
        block->coords[i].x+=temp;
    }

    for(int i=0;i<4;++i)
    {
        mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair, ' '|A_REVERSE);
        mvaddch(block->coords[i].y-4, 2*block->coords[i].x+repair+1, ' '|A_REVERSE);
    }
    refresh();
}

int randBlock()
{
    return rand()%7;
}


void closeGame()
{
    for(int i=0;i<20;++i)free(tetrion[i]);
    free(tetrion);
    free(block0);
    free(block1);
    free(block2);
    free(block3);
    free(block4);
    free(block5);
    free(block6);
    attron(COLOR_PAIR(3));
    mvprintw(21,36,"GAME OVER");
    refresh();
    sleep(3);
    getch();
    endwin();
}

bool gameEnd()
{
    for(int i=0;i<10;++i)if(tetrion[0][i].block==1)return 1;
    return 0;
}

void freeBlock(table * block)
{
    free(block->coords);
    free(block);
}

table * refreshTetrion(int currentBlock, int nextBlock, int point)
{
    table *current=malloc(sizeof(table));

    current->coords=malloc(4*sizeof(pos));

    current->colour=currentBlock+1;

    pos *temp;

    if(currentBlock==0)temp=block0;else
    if(currentBlock==1)temp=block1;else
    if(currentBlock==2)temp=block2;else
    if(currentBlock==3)temp=block3;else
    if(currentBlock==4)temp=block4;else
    if(currentBlock==5)temp=block5;else
    if(currentBlock==6)temp=block6;

    for(int i=0;i<4;++i)
        {
            current->coords[i].x=temp[i].x;
            current->coords[i].y=temp[i].y;
        }
    for(int i=5;i<10;++i)mvprintw(i,61,"          ");

    drawNext(nextBlock);
    attron(COLOR_PAIR(7));
    mvprintw(0,7,"%5d",point);

    refresh();
    return current;
}

void drawNext(int nextBlock)
{
    pos *temp=NULL;
    if(nextBlock==0)temp=block0;else
    if(nextBlock==1)temp=block1;else
    if(nextBlock==2)temp=block2;else
    if(nextBlock==3)temp=block3;else
    if(nextBlock==4)temp=block4;else
    if(nextBlock==5)temp=block5;else
    if(nextBlock==6)temp=block6;

    attron(COLOR_PAIR(nextBlock+1));

    for(int i=0;i<4;++i)
    {
        mvaddch(temp[i].y+5,2*temp[i].x+63,' '|A_REVERSE);
        mvaddch(temp[i].y+5,2*temp[i].x+64,' '|A_REVERSE);
    }
}

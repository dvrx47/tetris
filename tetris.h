#include "start.h"
#include <time.h>

#ifndef tetris_h
#define tetris_h

void moveBlock(table * block, int direction);
void rotateBlock(table *block, int currentBlock, int * orientation);
int randBlock();
void closeGame();
bool gameEnd();
void freeBlock(table * block);
table * refreshTetrion(int currentBlock, int nextBlock, int point);
void drawNext(int nextBlock);
bool canFall(table * block);
bool canRight(table * block);
bool canLeft(table * block);
bool canRotate(table * block, int currentBlock, int orientation);
int bonusPoints();

#endif

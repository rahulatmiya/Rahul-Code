#ifndef BOARD_H_
#define BOARD_H_
#include "Tile.h"

class Board{
	Tile board[8][8];
public:
    Board();
    Board(char data[8][8]);
    Tile& getTile(char file,int row);
    void show();
};

#endif /* BOARD_H_ */

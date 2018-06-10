#ifndef PIECE_H_
#define PIECE_H_
#include "PieceEnum.h"
class Tile;
class Piece{
	PieceEnum type;
	Tile* position;
public:
	Piece();
	Piece(PieceEnum type);
	void setType(PieceEnum type);
	void setPosition(Tile * position);
	PieceEnum getType();
	Tile * getPosition();
	void show();
};
#endif /* PIECE_H_ */


#ifndef TILE_H_
#define TILE_H_
#include "Piece.h"
class Tile{
	char file;
	int row;
	Piece* piece;
	bool validFile(char file);
	bool validRow(int row);
  public:
	void print();
	void read();
	void setFile(char file);
	void setRow(int row);
	void setPiece(Piece* piece);
	Piece* getPiece();
	char getFile();
	int  getRow();
	Tile();
	Tile(char file, int row);
};
#endif /* TILE_H_ */

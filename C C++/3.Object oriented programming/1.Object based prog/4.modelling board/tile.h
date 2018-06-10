#ifndef TILE_H_
#define TILE_H_

class Tile{
	char file;
	int row;
	char piece;
	bool validFile(char file);
	bool validRow(int row);
  public:
	void print();
	void read();
	void setFile(char file);
	void setRow(int row);
	void setPiece(char piece);
	char getPiece();
	char getFile();
	int  getRow();
	Tile();
	Tile(char file, int row);
};
#endif /* TILE_H_ */

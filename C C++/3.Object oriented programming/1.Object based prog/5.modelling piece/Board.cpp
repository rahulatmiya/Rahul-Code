#include "Board.h"
#include "PieceEnum.h"
#include <iostream>
using namespace std;

Board::Board(){

}

Board::Board(char data[8][8]){
	for(int row=8; row >=1 ; row--){
		for(char file='a' ; file <= 'h' ; file++){
			board[8-row][file-'a'].setRow(row);
			board[8-row][file-'a'].setFile(file);
			Piece* p = NULL;
			if( data[8-row][file-'a'] != ' ' )
				p = new Piece((PieceEnum)data[8-row][file-'a']);
			board[8-row][file-'a'].setPiece(p);
		}
	}
}

Tile& Board::getTile(char file, int row){
	return board[8-row][file-'a'];
}

void Board::show()
{
  Piece* p = NULL;
  char ch = ' ';
  cout << " -------------------------------"<<endl;
  for(int row = 8 ; row >= 1 ; row--){
     for(char file = 'a' ; file <= 'h' ; file++ ){
    	  p = getTile(file,row).getPiece();
    	  if(p == NULL) ch = ' ';
    	  else ch = (char)p->getType();
          cout << "| " << ch << " ";
     }
     cout << "|";
     if( row != 1 )
     {
       cout<<endl<<"|-------------------------------|"<<endl;
     }
  }
  cout <<endl<<" -------------------------------"<<endl;
}

Board::~Board(){
	for(int row=8; row >=1 ; row--){
			for(char file='a' ; file <= 'h' ; file++){
				Piece* p = board[8-row][file-'a'].getPiece();
				if(p!=NULL) delete p;
			}
		}
}

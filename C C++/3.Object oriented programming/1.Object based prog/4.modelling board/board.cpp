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
			board[8-row][file-'a'].setPiece(data[8-row][file-'a']);

		}
	}
}

Tile& Board::getTile(char file, int row){
	return board[8-row][file-'a'];
}

void Board::show()
{
  cout << " -------------------------------"<<endl;
  for(int row = 8 ; row >= 1 ; row--){
     for(char file = 'a' ; file <= 'h' ; file++ ){

          cout << "| " <<  getTile(file,row).getPiece() << " ";
     }
     cout << "|";
     if( row != 1 )
     {
       cout<<endl<<"|-------------------------------|"<<endl;
     }
  }
  cout <<endl<<" -------------------------------"<<endl;
}

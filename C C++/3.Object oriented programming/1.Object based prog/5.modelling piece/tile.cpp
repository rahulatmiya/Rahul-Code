#include <iostream>
#include "Tile.h"
#include "PieceEnum.h"
using namespace std;


Tile::Tile(){
		this->file = 'a';
		this->row = 1;
		this->piece = NULL;
};

Tile::Tile(char file, int row)
{
		if( validFile(file) && validRow(row) ){
			this->file = file;
			this->row = row;
		} 
		else{
	   		this->file = 'a';
   	    	this->row = 1;
		};
}

void Tile::print()
{
	cout << "file = " << this->file << endl;
	cout << "row = " << this->row << endl;
	piece->show();
}

void Tile::read()
{
	do
	{
		cout << "Enter file " << endl;
		cin  >> file;
	} while ( !validFile(file) );  
	do
	{
		cout << "Enter row " << endl;
		cin  >> row;
	} while ( !validRow(row) );
}

bool Tile::validFile(char file)
{
	return ( file >= 'a' && file <= 'h' );
}

bool Tile::validRow(int row)
{
	return ( row >= 1 && row <= 8 );
}

void Tile::setFile(char file){
  if(validFile(file)){
    this->file = file;
  }
}

void Tile::setRow(int row){
  if(validRow(row)){
    this->row = row;
  }
}

void Tile::setPiece(Piece* piece){
  this->piece = piece;
}

int Tile::getRow(){
  return row;
}

char Tile::getFile(){
  return file;
}

Piece* Tile::getPiece(){
  return piece;
}

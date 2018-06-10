#include <iostream>
#include "Tile.h"
using namespace std;

Tile::Tile(){
		this->file = 'a';
		this->row = 1;
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

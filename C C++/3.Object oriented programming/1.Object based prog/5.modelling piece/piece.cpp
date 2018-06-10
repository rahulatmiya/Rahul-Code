#include "Piece.h"
#include "stdlib.h"
#include "iostream"
#include "PieceEnum.h"
#include "Tile.h"

using namespace std;

Piece::Piece(){
	type = WHITE_PAWN;
	position = NULL;
}

Piece::Piece(PieceEnum type){
	this->type = type;
	position = NULL;
}

void Piece::setType(PieceEnum type){
   this->type = type;
}

void Piece::setPosition(Tile* position){
   this->position = position;
}

PieceEnum Piece::getType(){
   return type;
}

Tile* Piece::getPosition(){
   return position;
}

void Piece::show(){
	cout << "Type is " << type << endl;
    if(position != NULL){
    	cout << "row is "<< position->getRow() << endl;
    	cout << "file is "<< position->getFile() << endl;
    }
    else{
        cout << position << endl;
    }
}

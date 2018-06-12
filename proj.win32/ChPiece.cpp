#include "ChPiece.h"

ChPiece::ChPiece()
{
	spSprite pic = new Sprite();
	//pic->setResAnim(PiecesRes.getResAnim("BPawn"));
	figure = pic;
	name = "Pawn";
	white = false;
}

ChPiece::ChPiece(std::string Name, bool clr, Vector2 place, ResAnim* PiecesRes)
{
	spSprite pic = new Sprite();

	
	if (clr)
	{
		pic->setResAnim(PiecesRes);
		pic->setPosition(place);
		addChild(pic);
		figure = pic;
	}
	else
	{
		pic->setResAnim(PiecesRes);
		pic->setPosition(place);
		addChild(pic);
		figure = pic;
	}
	
	name = Name;
	white = clr;
}


ChPiece::~ChPiece()
{
	figure->releaseRef();
}

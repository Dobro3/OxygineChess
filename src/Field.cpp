#include "Field.h"


Field::Field()
{
	Figure = NULL;
	X = 0; 
	Y = 0;
	bckgrnd = new Sprite();
}
Field::Field(int x, int y)
{
	spSprite _bckgrnd = new Sprite;
	PiecesRes.loadXML("PiecesRes.xml");
	Vector2 pos;
	pos = Vector2(PiecesRes.getResAnim("black_box")->getHeight()*y, PiecesRes.getResAnim("black_box")->getWidth()*x);
	if (x % 2 && y % 2 || !(x % 2) && !(y % 2))
	{
		
		_bckgrnd->setResAnim(PiecesRes.getResAnim("black_box"));
		_bckgrnd->setPosition(pos);
	}
	else
	{
		_bckgrnd->setResAnim(PiecesRes.getResAnim("white_box"));
		_bckgrnd->setPosition(pos);
	}
	addChild(_bckgrnd);
	bckgrnd = _bckgrnd;
	pos += (bckgrnd->getResAnim()->getSize() / 2)-(PiecesRes.getResAnim("WPawn")->getSize()/2);


	if (y == 1)
	{
		Figure = new ChPiece("Pawn", false, pos, PiecesRes.getResAnim("BPawn"));
		addChild(Figure);
	}
	else if (y == 6)
	{
		Figure = new ChPiece("Pawn", true, pos, PiecesRes.getResAnim("WPawn"));
		addChild(Figure);
	}
	X = x;
	Y = y;
	EventCallback cb = CLOSURE(this, &Field::fieldClick);
	this->addEventListener(TouchEvent::CLICK, cb);
}
void Field::fieldClick(Event *e)
{
	makeBright();
}

void Field::makeBright()
{
	bckgrnd->setColor(Color::White);
	bckgrnd->addTween(Sprite::TweenColor(Color::Green), 2000, 1, true);
}

int Field::getXpos()
{
	return X;
}

int Field::getYpos()
{
	return Y;
}



Field::~Field()
{
}

#include "oxygine-framework.h"
#include "ChPiece.h"
#include <functional>

using namespace oxygine;

class Field : public Actor
{
public:
	Resources PiecesRes;
	int X;
	int Y;
	ChPiece *Figure;
	spSprite bckgrnd;
	
	Field();
	Field(int x, int y );
	void makeBright();
	void fieldClick(Event *e);
	int getXpos();
	int getYpos();
	~Field();
};


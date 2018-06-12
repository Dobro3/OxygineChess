#include "oxygine-framework.h"
#include <functional>
#include <string>

using namespace oxygine;


class ChPiece : public Actor
{
public:
	spSprite figure;
	bool white;
	std::string name;

	ChPiece();

	ChPiece(std::string Name, bool clr, Vector2 place, ResAnim* PiecesRes);
	~ChPiece();
};
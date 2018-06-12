#include "Field.h"
using namespace oxygine;
class Deck: public Actor
{
public:
	Field *field[8][8];
	spTextField _text;
	Deck();
	~Deck();

	void fieldClicked(Event *event);
	
	
};

typedef oxygine::intrusive_ptr<Deck> spDeck;
void Deck_update();
	void Deck_init();
#include "Deck.h"



Deck::Deck()
{

	for (int i=0; i<8; i++)
		for (int j = 0; j < 8; j++)
		{
			field[i][j] = new Field(i, j);
			addChild(field[i][j]);
			EventCallback cb = CLOSURE(this, &Deck::fieldClicked);
			field[i][j]->addEventListener(TouchEvent::CLICK, cb);
			//myEvent event(field[i][j]);
			//dispatchEvent(&event);
		}
}


Deck::~Deck()
{
}


void Deck::fieldClicked(Event *ev)
{	
	
	spTextField text = new TextField();
	//attach it as child to button
	text->attachTo(this);
	//centered in button
	text->setPosition(field[3][3]->bckgrnd->getPosition());
	TextStyle style = TextStyle(field[3][3]->PiecesRes.getResFont("main")).withColor(Color::White).alignMiddle();
	text->setStyle(style);
	text->setText(ev->currentTarget->getName());
	_text->addTween(Actor::TweenScale(1.1f), 500, 1, true);
	_text = text;
	//myEvent* event = static_cast<myEvent*>(ev);
}

void Deck_init()
{
	spDeck deck = new Deck();
	getStage()->addChild(deck);
}

void Deck_update()
{
}

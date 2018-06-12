#include "oxygine-framework.h"
#include <functional>
#include "Field.h"
using namespace oxygine;

class myEvent : public Event
{
public:
	enum { EVENT = eventID('A', 'c', 'E', 'r') };
	Field* actor;
	myEvent(Field *who) : Event(EVENT), actor(who) {};
};

#define eventID(a,b,c,d) ( ((unsigned int)a) | (((unsigned int)b)<< 8) | (((unsigned int)c)<<16) | (((unsigned int)d)<<24))
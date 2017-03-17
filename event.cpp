#include "event.h"

namespace event
{
	
Event::Event() 
{ 
	this->eventType = 0;
}

Event::~Event()
{
	
}

int Event::getEventType()
{
	return this->eventType;
}

void Event::fire()
{
	observer::fire(*this);
}
	
}
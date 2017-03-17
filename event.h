#pragma once

#include "observer.h"

namespace event
{

// Event class		
class Event
{
protected:
	int eventType;
	
public:
	Event();
	~Event();
	
	int getEventType();
	
	virtual void fire();
};

}
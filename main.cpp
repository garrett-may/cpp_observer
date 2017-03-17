#include <iostream>

#include "observer.h"
#include "event.h"

// Example of a custom event
class SpecificEvent : public event::Event
{
public:
	SpecificEvent();
	~SpecificEvent();	
	
	void fire();
};	
	
SpecificEvent::SpecificEvent() 
{ 
	this->eventType = 1;
}

SpecificEvent::~SpecificEvent()
{
	
}

void SpecificEvent::fire()
{
	observer::fire(*this);
	((Event) *this).fire();
}

// Example handlers

// Handler forint
void myHandler(int num)
{
	std::cout << "int is: " << num << std::endl;
}

// Handler for Event
void myEventHandler(event::Event event)
{
	std::cout << "Event is: " << event.getEventType() << std::endl;
}

// Handler for SpecificEvent
void mySpecificEventHandler(SpecificEvent event)
{
	std::cout << "SpecificEvent is: " << event.getEventType() << std::endl;
}

// Main function
int main()
{
	// Variables
	int integer = 42;
	SpecificEvent specificEvent;
	
	// Add handlers
	observer::addEventHandler(myHandler);
	observer::addEventHandler(myEventHandler);	
	observer::addEventHandler(mySpecificEventHandler);
	
	// Fire an int
	observer::fire(integer);
	
	// Fire a SpecificEvent
	observer::fire(specificEvent);
	
	// Fire a SpecificEvent via custom fire event
	// This method allows users to define what else to fire e.g. base class handlers
	specificEvent.fire();	
	
	return 0;
}
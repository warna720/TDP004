#include "Component.h"

#include <cmath>

Component::Component(const std::string & name, Connection & p, Connection & n) :
					 _name(name), _a(&p), _b(&n) {}


// Shut the fuck up compiler
Component::~Component() {}


double Component::getVoltage()
{
	return fabs( _a->getCharge() - _b->getCharge() );
}

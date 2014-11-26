#include "Battery.h"

Battery::Battery(const std::string & name, const float & charge, Connection & p, Connection & n) : 
		Component(name, p, n), _charge(charge) {}

void Battery::move(const float &)
{
	// Set positive point to same charge as battery
	// And negative point to null
	_a->setCharge(_charge);
	_b->setCharge(0);
}


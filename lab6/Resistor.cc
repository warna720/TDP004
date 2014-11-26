#include "Resistor.h"

Resistor::Resistor(const std::string & name, const float & ohm, Connection & p, Connection & n) : 
		Component(name, p, n), _ohm(ohm) {}

void Resistor::move(const float & timeunits)
{
	// How much to move
	double chargeToMove { (getVoltage() / _ohm) * timeunits };

	float aSide { _a->getCharge() };
	float bSide { _b->getCharge() };
	
	if ( aSide > bSide )
	{
		_a->setCharge( aSide - chargeToMove );
		_b->setCharge( bSide + chargeToMove );
	}
	else
	{
		_b->setCharge( bSide - chargeToMove );
		_a->setCharge( aSide + chargeToMove );
	}
}

float Resistor::getCurrent()
{
	return getVoltage() /_ohm;
}


#include "Capacitor.h"

Capacitor::Capacitor(const std::string & name, const float & fahrad, Connection & p, Connection & n) : 
		Component(name, p, n), _fahrad(fahrad), _charge(0) {}

void Capacitor::move(const float & timeunits)
{
	// How much to move
	double chargeToMove { _fahrad * (getVoltage() - _charge) * timeunits };

	// Add to capacitor charge
	_charge += chargeToMove;

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

float Capacitor::getCurrent()
{
	return abs(_fahrad * (getVoltage() - _charge));
}


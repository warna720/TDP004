#include <string>

#include "Connection.h"

Connection::Connection() : _charge(0) {}

void Connection::setCharge(const float & charge)
{
	_charge = charge;
}

float Connection::getCharge() const
{
	return _charge;
}

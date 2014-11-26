#include <iostream>		// IO Stream
#include <vector>		// Vector
#include <iomanip>		// cout precision

#include "Component.h"
#include "Connection.h"
#include "Battery.h"
#include "Resistor.h"
#include "Capacitor.h"

using namespace std;

void deleteComponents(vector<Component*> & net)
{
	// Memory wants to be free
	for (Component * c : net)
	{
		delete c;
	}
}

void printNames(const vector<Component*> & net)
{
	cout << "     ";
	for (Component * c : net)
	{
		cout << c->getName() << "\t      ";
	}
	cout << endl;
}

void printUnits(const int & components)
{
	for (int x = 0; x < components; ++x)
	{
		cout << "Volt" << "\t" << "Curr" << "\t";
	}
	cout << endl;
}

void simulate(vector<Component*> & net, const int & iterations, const int & outputs, const float & timeunits)
{
	printNames(net);
	printUnits(net.size());

	int p {1};

	for (int x = 0; x < iterations; ++x)
	{
		for (Component * c : net)
		{
			c->move(timeunits);
		}

		if (p == (iterations / outputs))
		{
			p = 1;
			for (Component * c : net)
			{
				cout << setprecision(2) << fixed;
				cout << c->getVoltage() << "\t";
				cout << c->getCurrent() << "\t";
			}
			cout << endl;
		}
		++p;
	}
}

void example1(float batVolt, int iterations, int prints, float timeunits)
{
	Connection p, n, R124, R23;
	vector<Component*> net;

	net.push_back(new Battery("Bat", batVolt, p, n));
	net.push_back(new Resistor("R1",  6.0, p, R124));
	net.push_back(new Resistor("R2",  4.0, R124, R23));
	net.push_back(new Resistor("R3",  8.0, R23, n));
	net.push_back(new Resistor("R4", 12.0, R124, n));

	simulate(net, iterations, prints, timeunits);

	deleteComponents(net);
}

void example2(float batVolt, int iterations, int prints, float timeunits)
{
	Connection p, n, l, r;
	vector<Component*> net;

	net.push_back(new Battery("Bat", batVolt, p, n));
	net.push_back(new Resistor("R1", 150.0, p, l));
	net.push_back(new Resistor("R2",  50.0, p, r));
	net.push_back(new Resistor("R3",  100.0, l, r));
	net.push_back(new Resistor("R4", 300.0, l, n));
	net.push_back(new Resistor("R5",  250.0, r, n));

	simulate(net, iterations, prints, timeunits);

	deleteComponents(net);
}

void example3(float batVolt, int iterations, int prints, float timeunits)
{
	Connection p, n, l, r;
	vector<Component*> net;

	net.push_back(new Battery("Bat", batVolt, p, n));
	net.push_back(new Resistor("R1", 150.0, p, l));
	net.push_back(new Resistor("R2",  50.0, p, r));
	net.push_back(new Capacitor("C3",  1.0, l, r));
	net.push_back(new Resistor("R4", 300.0, l, n));
	net.push_back(new Capacitor("C5",  0.75, r, n));

	simulate(net, iterations, prints, timeunits);

	deleteComponents(net);
}

void validateInput(char * argv [])
{
	try
	{
		stoi(argv[1]);
		stoi(argv[2]);
		stof(argv[3]);
		stof(argv[4]);
	}
	catch(...)
	{
		cout << "Params is int, int float float\nGood luck!" << endl;
		exit(1);
	}
}

int main (int argc, char * argv [])
{
	++argc; // shut up compiler
	validateInput(argv);

	int iterations	{stoi(argv[1])};
	int prints	{stoi(argv[2])};
	float timeunits {stof(argv[3])};
	float batVolt	{stof(argv[4])};

	example1(batVolt, iterations, prints, timeunits);

	cout << endl << endl;

	example2(batVolt, iterations, prints, timeunits);

	cout << endl << endl;

	example3(batVolt, iterations, prints, timeunits);

	return 0;
}

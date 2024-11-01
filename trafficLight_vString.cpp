#include "time.h"
#include "trafficLight_vString.h"
#include <iostream>
#include <cstring>
											
using namespace std;

/* Need to initialise the static attribute sleepyTownClock from TrafficLight
 * class straightaway, before it is called in any function, otherwise an
 * error will occur */

Time TrafficLight::sleepyTownClock; 

/* Constructing an instance of TrafficLight with 2 parameters.
 * lightColor is always initialised to start as "red".
 * Lights constructed with 2 parameters don't yet have a light to pair; as the
 * second light is yet to be created; hence set lightPair to null */

TrafficLight::TrafficLight(Time delayTime, char* TName) : lightDelay(delayTime),
	lightName(TName), lightColor("red")
{
	lightPair = nullptr;
}

/* Constructing an instance of TrafficLight with 3 parameters.
 * In doing so, we can now update the lightPairing of the orignal traffic 
 * light to also point to this newly constructed traffic light */

TrafficLight::TrafficLight(Time delayTime, char* TName, 
		TrafficLight& partnerLight) : TrafficLight(delayTime, TName)
{
	//pair this light with the first light created above
	lightPair = &partnerLight; 
	//update the first light to be paired with (point to) this light
	partnerLight.lightPair = this;
}

//Defining how the << operator should function for TrafficLight instances
ostream& operator << (ostream& output, TrafficLight* light)
{
	output << light->lightName << " changes colour to " << light->lightColor << 
		endl;
	return output;
}

//Defining setTheTime function
void TrafficLight::setTheTime(Time& timeUpdate)
{
	sleepyTownClock.add(timeUpdate); 
}

//Defining the carWantsToCross function
void TrafficLight::carWantsToCross()
{
	cout << "\n";
	cout << "*** at " << sleepyTownClock << " a car wants to cross light " <<
		this->lightName << ", with colour: " << this->lightColor << endl;

	//we need to loop through until the light the car is at has turned green
	while (this->lightColor != "green") 
	{
		requestColorChange(this->lightPair);
		changeColor(this);
	}
}

//Defining the requestColorChange function
void TrafficLight::requestColorChange(TrafficLight* lightPair)
{
	if (lightPair->lightColor == "green") 
	{
		lightPair->lightColor = "yellow";
		setTheTime(lightPair->lightDelay); 
		cout << "    at " << sleepyTownClock << " " << lightPair;
		return;
	}

	if (lightPair->lightColor == "yellow")
	{
		lightPair->lightColor = "red";
		setTheTime(lightPair->lightDelay);
		cout << "    at " << sleepyTownClock << " " << lightPair;
		return;
	}
}

//Defining the changeColor function
void TrafficLight::changeColor(TrafficLight* tLight)
{
	if (tLight->lightColor == "red")
	{
		tLight->lightColor = "yellow";
		setTheTime(tLight->lightDelay);
		cout << "    at " << sleepyTownClock << " " << tLight;
		return;
	}

	if (tLight->lightColor == "yellow")
	{
		tLight->lightColor = "green";
		setTheTime(tLight->lightDelay);
		cout << "    at " << sleepyTownClock << " " << tLight;
		return;
	}
}


/* Defining function displayPairStatus that I used to check light pairing 
 * was working... Not needed in final answer */
void TrafficLight::displayPairStatus()
{
	if (lightPair)
	{
		cout << this->lightName << " is paired with light " 
		<< lightPair->lightName << "\n";
	}
	else
	{
		cout << "Not paired" << "\n";
	}
}





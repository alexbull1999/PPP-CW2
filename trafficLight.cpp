#include "time.h"
#include "trafficLight.h"
#include <iostream>
											
using namespace std;

/* Initialising the static attribute sleepyTownClock from TrafficLight class */

Time TrafficLight::sleepyTownClock; 

/* Constructing an instance of TrafficLight with 2 parameters.
 * lightColor is by default  initialised to "red".
 * Lights constructed with 2 parameters don't yet have a light to pair; as the
 * second light is yet to be created; hence set lightPair to null */

TrafficLight::TrafficLight(Time delayTime, char* TName) : lightDelay(delayTime), 
	lightName(TName), lightColor(Color::RED)
{
	lightPair = nullptr;
}

/* Constructing an instance of TrafficLight with 3 parameters.
 * In doing so, we can update the lightPairing of the orignal traffic 
 * light to also point to this newly constructed traffic light */

TrafficLight::TrafficLight(Time delayTime, char* TName, 
		TrafficLight& partnerLight) : TrafficLight(delayTime, TName)
{
	//pair this traffic light with the already created traffic light 
	lightPair = &partnerLight;
	//update pairing of the first traffic light to point to this light
	partnerLight.lightPair = this; 
}

//Defining how the << operator should function for TrafficLight instances
ostream& operator << (ostream& output, TrafficLight* light)
{
	output << light->lightName << " changes colour to " << light->lightColor << 
		endl;
	return output;
}

//Defining how the << operator should function for Color instances
ostream& operator << (ostream& output, Color& color)
{
	switch (color)
	{
		case Color::RED:
			output << "red";
			break;
		case Color::YELLOW:
			output << "yellow";
			break;
		case Color::GREEN:
			output << "green";
			break;
	}
	return output;
}

//Defining how the -- operator should function for Color instances
Color& operator -- (Color& color)
{
	if (color == Color::GREEN)
	{
		color = Color::YELLOW;
	}
	else if (color == Color::YELLOW)
	{
		color = Color::RED;
	}
	return color;
}

//Defining how the ++ operator should function for Color instances
Color& operator ++ (Color& color)
{
	if (color == Color::RED)
	{
		color = Color::YELLOW;
	}
	else if (color == Color::YELLOW)
	{
		color = Color::GREEN;
	}
	return color;
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
	cout << "***  at " << sleepyTownClock << " a car wants to cross light " << 
		lightName << ", with colour: " << lightColor << endl;

	//we need to loop through until the light the car is at has turned green
	while (lightColor != Color::GREEN) 
	{
		if (lightPair->lightColor == Color::GREEN || 
				lightPair->lightColor == Color::YELLOW)
		{
			requestColorChange(lightPair);			
			changeColor(this);
		}
		else if (lightPair->lightColor == Color::RED)
		{
			changeColor(this);
		}
	}
}

//Defining the requestColorChange function which always decrements enum down
void TrafficLight::requestColorChange(TrafficLight* lightPair)
{
	--(lightPair->lightColor);
	setTheTime(lightPair->lightDelay);
	cout << "     at " << sleepyTownClock << " " << lightPair;
	return;
}

//Defining the changeColor function which always increments enum up
void TrafficLight::changeColor(TrafficLight* tLight)
{
	++(tLight->lightColor);
	setTheTime(tLight->lightDelay);
	cout << "     at " << sleepyTownClock << " " << tLight;
	return;
}



/* Defining function displayPairStatus that I used to check light pairing 
 * was working... No longer needed in final answer */
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





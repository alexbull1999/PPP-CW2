#include "time.h"
#include <iostream>

using namespace std;

Time::Time() : theHour(0), theMins(0), theSecs(0) {} // default constructor

// time constructor with parameters to assign to attributes
Time::Time(int hours, int mins, int secs) : theHour(hours), theMins(mins),
	theSecs(secs) {}

//define add function to calculate new time
void Time::add(Time& anotherTime)
{
	//we can access "this's" instance's attributes directly
	int h1 = theHour; //same as this->theHour
	int m1 = theMins;
	int s1 = theSecs;

	//Access the member attributes of the anotherTime instance
	int h2 = anotherTime.theHour;
	int m2 = anotherTime.theMins;
	int s2 = anotherTime.theSecs;

	int s3 = (s1 + s2) % 60;
	int m3 = (m1 + m2 + ((s1 + s2)/60)) % 60;
	int h3 = (h1 + h2 + (m1 + m2 + (s1 + s2)/60)/60) % 24;

	//Update "this's" instance's attributes to new time
	theHour = h3;
	theMins = m3;
	theSecs = s3;
}

//overloading << operator for objects in the Time class
ostream& operator << (ostream& output, Time& t)
{
	output << t.theHour << ":" << t.theMins << ":" << t.theSecs;
	return output;
}

/* trafficLights.h - header file for the class trafficLights */

#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "time.h"

/*********************** Class TrafficLight ***************************/

/* The class TrafficLight represents instances of the traffic lights in 
 * SleepyTown. Each traffic light has four attributes:
 * - lightColor: an enum representing the three possible color options
 * - lightDelay: an int representing the time for the light to change color
 * - lightName: a pointer to a char array holding the name of the light
 * - lightPair: a pointer to the Traffic Light the light is paired with
 * There is also a static attribute applicable to the whole class, rather
 * than to each individual instance which is:
 * - sleepyTownClock: an instance of the Time class, which keeps track
 * of the overall time in SleepyTown.  */

/*enum declaration, and signalling that we will overload the <<,
 * --, and ++ operators for the enum */
enum Color {RED, YELLOW, GREEN};
std::ostream& operator << (std::ostream&, Color&);
Color& operator -- (Color& color);
Color& operator ++ (Color& color);

class TrafficLight {

	public:
	
		TrafficLight(Time, char*); //constructor for TrafficLight with 2 parameters
		TrafficLight(Time, char*, TrafficLight&); //constructor with 3 parameters

		/* carWantsToCross is a method to signal that a car has arrived at the
		 * traffic light instance that calls the method. 
		 * As a result, the helper method requestColorChange is called to request 
		 * the partner traffic light to change color from green to red.
		 * The helper method changeColor, to change its own color from red to green.
		 * Each change of traffic light color takes a given time, and so the helper
		 * function setTheTime is also called to update the SleepyTown clock */
		void carWantsToCross();

		/* This function keeps track of the SleepyTown clock, updating it according
		 * to the time taken with each traffic light change. 
		 * Parameter: reference to an instance of the Time class
		 * As void, it does not return anything, but simply updates the value of 
		 * the Time instance passed to it by reference to the new time */
		static void setTheTime(Time&);

		/* Friend declaration to enable overloading of the << operator for the
		 * TrafficLight class */
		friend std::ostream& operator << (std::ostream&, TrafficLight*);

	private:

		/* add members and operations to complete the class yourself */

		/* This is a helper function for carWantsToCross that requests a paired 
		 * traffic light to change color by 1 color step at a time.
		 * This function always changes the color green to yellow, and the color
		 * yellow to red. 
		 * It is a static void to enable it to be called without an object 
		 * instance calling it. 
		 * Parameter: A pointer to a traffic light instance, so that it can
		 * update the light color of that traffic light appropriately */
		static void requestColorChange(TrafficLight*);

		/* This is a helper function for carWantsToCross that requests a
		 * traffic light to change color by 1 color step at a time.
		 * This function always changes the color red to yellow, and the
		 * color yellow to green. 
		 * It is a static void to enable it to be called without an object
		 * instance calling it.
		 * Parameter: A pointer to a traffic light instance, so that it can
		 * update the light color of that traffic light appropriately */
		static void changeColor(TrafficLight*);

		/* A function I used during initial coding to check whether my traffic
		 * light instance were linking correctly upon construction. 
		 * Not needed in the actual problem answer */
		void displayPairStatus(); 

		Time lightDelay;
		char* lightName;
		Color lightColor;
		TrafficLight* lightPair;

		static Time sleepyTownClock;

};

#endif

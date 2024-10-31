/* time.h - header file for the class Time */

#ifndef TIME_H
#define TIME_H

#include <iostream>

/*********************** Time Class ***************************/

/* The class Time is used to create objects to represent the time in the
 * SleepyTown scenario we are modelling. 
 * Each time object has three private attributes, all of which are of 
 * type int:
 * - theHour: which represents an hour value
 * - theMins: which represents a minute value
 * - theSecs: which represents a seconds value */

class Time {

	public:

		Time(); // default constructor declaration, to allow TrafficLight 
						// class to take unassigned instances of time

		Time(int hours, int mins, int secs);
		
		/* A function that adds two values of time together and in doing so updates
		 * the value of the object calling the method to the result of the sum. 
		 * (Adds seconds to seconds, minutes to minutes and hours to hours, 
		 * taking into account that a day has 24 hours, an hour has 60 minutes
		 * and a minute has 60 seconds)
		 * Parameter: An object of time class, passed by reference, whose value is
		 * to be added onto the calling object's time to produce the new time */
		void add(Time& anotherTime);
				
		friend std::ostream& operator << (std::ostream&, Time&);

	private:

		int theHour;
		int theMins;
		int theSecs;	
		
};

#endif


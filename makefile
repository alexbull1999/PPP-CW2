traffic: main.o time.o trafficLight.o
	g++ -g -Wall main.o time.o trafficLight.o -o traffic

main.o: main.cpp time.h trafficLight.h
	g++ -g -Wall -c main.cpp

time.o: time.cpp time.h
	g++ -g -Wall -c time.cpp

trafficLight.o: trafficLight.cpp trafficLight.h time.h
	g++ -g -Wall -c trafficLight.cpp

clean:
	rm -f *.o execute



#include <iostream>
#include <chrono>
#include <cstdlib>
#include <exception>



//_________________________UML DIAGRAM______________________________*
/*																	|
 * 							  Time  								|
 *-------------------------------------------------------------------|
 * 	-hour : long		(defaults are current time)					|
 * 															 		|
 *   -minute : long													|
 * 																	|
 * 	-second : long													|
 * 																	|
 * 	-theTime: long													|
 * 																	|
 *-------------------------------------------------------------------|
 * 	 -Time(): (System.currentTime.Millis()) 						|
 * 	 																|
 * 	 -Time(long):   												|
 * 																	|
 * 	 -Time(hour:long,min:long,second:long)							|
 * 																	|
 * 	+setTime():void													|
 *  																	|
 * 	+getHour() : long												|
 * 																	|
 * 	+getSec() : long												|
 * 																	|
 * 	+getMin() : long												|
 * 	 																|
 * 																	|
 *___________________________________________________________________|  */

/**
 * Exercise10.1 (The Time class) Design a class named Time. The class contains:
 * <p>
 * The data fields hour, minute, and second that represent a time.
 * <p>
 * A no-arg constructor that creates a Time object for the current time.
 * (The values of the data fields will represent the current time.)
 * <p>
 * A constructor that constructs a Time object with a specified elapsed time
 * since midnight, January 1, 1970, in milliseconds. (The values of the data
 * fields will represent this time.)
 * <p>
 * A constructor that constructs a Time object with the specified hour, minute, and second.
 * <p>
 * Three getter methods for the data fields hour, minute, and second, respectively.
 * <p>
 * A method named setTime(long elapseTime) that sets a new time for the object using
 * the elapsed time. For example, if the elapsed time is 555550000 milliseconds, the
 * hour is 10, the minute is 19, and the second is 10.
 * <p>
 * Draw the UML diagram for the class and then implement the class.
 * <p>
 * Write a test
 * program that creates three Time objects (using new Time(), new Time(555550000),
 * and new Time(5, 23, 55)) and displays their hour, minute, and second in the format
 * hour:minute:second.

 */

class Time {
private:
    long long hour;
    long long min;
    long long second;

public:
    // No-arg constructor creates a Time object for the current time (GMT/UTC)
    Time() {
        auto now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        long long millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
        setTime(millis);
    }

    // Constructs a Time object with a specified elapsed time in milliseconds
    Time(long long elapsedTime) {
        setTime(elapsedTime);
    }

    // Constructs a Time object with specified hour, minute, and second
    Time(long long newHour, long long newMin, long long newSec) 
        : hour(newHour), min(newMin), second(newSec) {}

    void setTime(long long elapsedTime) {
        long long totalSeconds = elapsedTime / 1000;
        second = totalSeconds % 60;

        long long totalMinutes = totalSeconds / 60;
        min = totalMinutes % 60;

        long long totalHours = totalMinutes / 60;
        hour = totalHours % 24;
    }

    long long getHour() const {
        return hour;
    }

    long long getMin() const {
        return min;
    }

    long long getSec() const {
        return second;
    }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        Time test1;
        Time test2(555550000LL);
        Time test3(5, 23, 55);
        std::cout << "The result for the no argument Time object is " << test1.getHour() << ":" << test1.getMin() << ":" << test1.getSec() << ".\n";
        std::cout << "The result for the single argument Time object is " << test2.getHour() << ":" << test2.getMin() << ":" << test2.getSec() << ".\n";
        std::cout << "The result for the three argument Time object is " << test3.getHour() << ":" << test3.getMin() << ":" << test3.getSec() << ".\n";
        return EXIT_SUCCESS;
    } 
    catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}
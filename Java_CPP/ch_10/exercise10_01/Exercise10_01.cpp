#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructs a Time object for the current time
    Time() {
        setTime(static_cast<long long>(std::time(nullptr)) * 1000);
    }

    // Constructs a Time object with a specified elapsed time in milliseconds
    Time(long long elapsedTime) {
        setTime(elapsedTime);
    }

    // Time object with specified hour, minute, and second
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}

    void setTime(long long elapsedTime) {
        long long totalSeconds = elapsedTime / 1000;
        second = static_cast<int>(totalSeconds % 60);

        long long totalMinutes = totalSeconds / 60;
        minute = static_cast<int>(totalMinutes % 60);

        long long totalHours = totalMinutes / 60;
        hour = static_cast<int>(totalHours % 24);
    }

    int getHour() const { return hour; }
    int getMin() const { return minute; }
    int getSec() const { return second; }
};

int main() {
    try {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        Time test1;
        Time test2(555550000LL);
        Time test3(5, 23, 55);

        std::cout << "The result for the no argument Time object is " 
                  << test1.getHour() << ":" << test1.getMin() << ":" 
                  << test1.getSec() << ".\n";

        std::cout << "The result for the single argument Time object is " 
                  << test2.getHour() << ":" << test2.getMin() << ":" 
                  << test2.getSec() << ".\n";

        std::cout << "The result for the three argument Time object is " 
                  << test3.getHour() << ":" << test3.getMin() << ":" 
                  << test3.getSec() << ".\n";

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
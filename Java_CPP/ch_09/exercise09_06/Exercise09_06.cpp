#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib>
#include <exception>

/**
 * 9.6 (Stopwatch) Design a class named StopWatch. The class contains:
 * ■ Private data fields startTime and endTime with getter methods.
 * ■ A no-arg constructor that initializes startTime with the current time.
 * ■ A method named start() that resets the startTime to the current time.
 * ■ A method named stop() that sets the endTime to the current time.
 * ■ A method named getElapsedTime() that returns the elapsed time for the
 * stopwatch in milliseconds.
 * <p>
 * Draw the UML diagram for the class and then implement the class.
 * <p>
 * Write a test program that measures the execution time of sorting 100,000 numbers
 * using selection sort.
 */


class StopWatch {
private:
    long long startTime;
    long long endTime;

    long long getCurrentTimeMillis() const {
        auto now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    }

public:
    StopWatch() {
        startTime = getCurrentTimeMillis();
        endTime = startTime;
    }

    void start() {
        startTime = getCurrentTimeMillis();
    }

    void stop() {
        endTime = getCurrentTimeMillis();
    }

    long long getStartTime() const {
        return startTime;
    }

    long long getEndTime() const {
        return endTime;
    }

    long long getElapsedTime() const {
        return endTime - startTime;
    }
};

void selectionSort(std::vector<int>& nums) {
    size_t n = nums.size();
    for (size_t i = 0; i < n - 1; ++i) {
        int min = nums[i];
        size_t minIdx = i;
        for (size_t k = i + 1; k < n; ++k) {
            if (nums[k] < min) {
                min = nums[k];
                minIdx = k;
            }
        }
        if (minIdx != i) {
            nums[minIdx] = nums[i];
            nums[i] = min;
        }
    }
}

int main() {
    try {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        std::vector<int> testNums(100000);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, 9999);

        for (size_t i = 0; i < testNums.size(); ++i) {
            testNums[i] = dis(gen);
        }

        StopWatch stopWatch;
        stopWatch.start();
        std::cout << "Start time: " << stopWatch.getStartTime() << " ms\n";

        selectionSort(testNums);
        stopWatch.stop();

        std::cout << "End time: " << stopWatch.getEndTime() << " ms\n";
        std::cout << "Elapsed time for selection sort: " << stopWatch.getElapsedTime() << " ms\n";

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
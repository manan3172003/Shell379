#include <iostream>
#include <chrono>
#include "runner.h"
using namespace std;

int runner() {
    // Get the current time point
    auto start = std::chrono::high_resolution_clock::now();

    cout << "Program started." <<endl;

    while (true) {
        // Get the current time point in the loop
        auto now = std::chrono::high_resolution_clock::now();

        // Calculate the duration between start and now
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - start);

        // Break the loop if the duration is 10 seconds or more
        if (duration.count() >= 10) {
            break;
        }
    }

    cout << "Program ended after 10 seconds." <<endl;

    return 0;
}
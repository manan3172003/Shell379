#include <iostream>
#include <chrono>
using namespace std;

int main() {
    // Get the current time point
    auto start = std::chrono::high_resolution_clock::now();

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
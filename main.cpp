//Eduardo Avila
//COMSC - 210 - 5293
//Lab 25 - Data Race

#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;
using namespace std::chrono;

//this will hold final time
struct TotalTimes{
    long long vectorTime;
    long long setTime;
    long long listTime;
};

//void bigRaceReading()

int main() {
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
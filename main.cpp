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

void bigRaceReading(vector<string>& readVector, list<string>& readList,
                    set<string>& readSet, TotalTimes& times);

int main() {
    vector<string> readVector;
    set<string> readSet;
    list<string> readList;

    TotalTimes readingTimes;

    bigRaceReading(readVector, readList, readSet, readingTimes);

    cout << "\n*** THE GRAND READING RACE ***\n" << endl;
    cout << "Vector's Time: " << readingTimes.vectorTime << " nanoseconds" << endl;
    cout << "Set's Time: " << readingTimes.setTime << " nanoseconds" << endl;
    cout << "List's Time: " << readingTimes.listTime << " nanoseconds" << endl;

    return 0;
}

void bigRaceReading(vector<string>& readVector, list<string>& readList,
                  set<string>& readSet, TotalTimes& times) {

    //Vector's reading race
    auto start = high_resolution_clock::now();

    ifstream finVector("codes.txt");
    string text;

    while (finVector >> text) {
        readVector.push_back(text);
    }

    finVector.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);

    times.vectorTime = duration.count();


    //List's reading race
    start = high_resolution_clock::now();

    ifstream finList("codes.txt");

    while (finList >> text) {
        readList.push_back(text);
    }

    finList.close();

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);

    times.listTime = duration.count();


    //Set's reading race
    start = high_resolution_clock::now();

    ifstream finSet("codes.txt");

    while (finSet >> text) {
        readSet.insert(text);
    }

    finSet.close();

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);

    times.setTime = duration.count();
}


/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
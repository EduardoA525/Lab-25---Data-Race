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

void bigRaceReading(vector<string> &readVector, list<string> &readList,
                    set<string> &readSet, TotalTimes &times);

void bigRaceSorting(vector<string> &sortVector, list<string> &sortList,
                    set<string> &sortSet, TotalTimes &times);

int main() {
    vector<string> mainVector;
    set<string> mainSet;
    list<string> mainList;

    TotalTimes readingTimes;

    bigRaceReading(mainVector, mainList, mainSet, readingTimes);

    cout << "\n*** THE GRAND READING RACE ***\n" << endl;
    cout << "Vector's Time: " << readingTimes.vectorTime << " nanoseconds" << endl;
    cout << "Set's Time: " << readingTimes.setTime << " nanoseconds" << endl;
    cout << "List's Time: " << readingTimes.listTime << " nanoseconds" << endl;

    TotalTimes sortingTimes;

    bigRaceSorting(mainVector, mainList, mainSet, sortingTimes);

    cout << "\n*** THE GRAND SORTING RACE ***\n" << endl;
    cout << "Vector's Time: " << sortingTimes.vectorTime << " nanoseconds" << endl;
    cout << "Set's Time: " << sortingTimes.setTime << " nanoseconds" << endl;
    cout << "List's Time: " << sortingTimes.listTime << " nanoseconds" << endl;



    return 0;
}

void bigRaceReading(vector<string> &readVector, list<string> &readList,
                  set<string> &readSet, TotalTimes &times) {

    //Vector's reading race
    auto start = high_resolution_clock::now();

    ifstream finVector("codes.txt");
    if (!finVector.is_open()){
        cout << "Vector File Error." << endl;
        return;
    }

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
    if (!finList.is_open()){
        cout << "List File Error." << endl;
        return;
    }

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
    if (!finSet.is_open()){
        cout << "Set File Error." << endl;
        return;
    }

    while (finSet >> text) {
        readSet.insert(text);
    }

    finSet.close();

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);

    times.setTime = duration.count();
}

void bigRaceSorting(vector<string> &sortVector, list<string> &sortList,
                    set<string> &sortSet, TotalTimes &times){
    //Vector's sorting
    auto start = high_resolution_clock::now();

    sort(sortVector.begin(), sortVector.end());

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end-start);

    times.vectorTime = duration.count();

    //List's sorting
    start = high_resolution_clock::now();

    sortList.sort();

    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);

    times.listTime = duration.count();

    //Set sorting
    times.setTime = -1;
}




/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
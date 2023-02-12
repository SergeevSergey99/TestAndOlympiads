#include <iostream>
#include <string>
using namespace std;


int main() {
    
    string Departure;
    cin >> Departure;
    
    string Arrive;
    cin >> Arrive;

    int diff;
    cin >> diff;

    int del = Departure.find(":");
    int DepartureH = stoi(Departure.substr(0, del));
    int DepartureM = stoi(Departure.substr(del + 1));

    del = Arrive.find(":");
    int ArriveH = stoi(Arrive.substr(0, del));
    int ArriveM = stoi(Arrive.substr(del + 1));

    int AnswerM = (ArriveM - DepartureM + 60) % 60;
    int AnswerH =  ((ArriveH - DepartureH) + (AnswerM + DepartureM >= 60 ? -1 : 0) + 48 - diff) % 24;

    cout << AnswerH << ":" << (AnswerM < 10 ? "0" : "") << AnswerM;


    return 0;
}
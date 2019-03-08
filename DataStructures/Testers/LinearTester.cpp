//
//  LinearTester.cpp
//  DataStructures
//
//  Created by James, Emily on 2/13/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "LinearTester.hpp"

void LinearTester :: testVsSTL()
{
    Timer crimeTimerSTL, crimeTimerOOP, musicSTL, musicOOP;
    
    crimeTimerSTL.startTimer();
    vector<CrimeData> crimes = FileController :: readCrimeDataToVector("/Users/ejam6898/Documents/C++/DataStructures/DataStructures/Data/crime.csv");
    crimeTimerSTL.stopTimer();
    
    crimeTimerOOP.startTimer();
    vector<CrimeData> moreCrimes = FileController :: readCrimeDataToList("/Users/ejam6898/Documents/C++/DataStructures/DataStructures/Data/crime.csv");
    crimeTimerOOP.stopTimer();
    
    cout << "This is the STL Read Time: " << endl;
    crimeTimerSTL.displayInformation();
    cout <<  "This is the OOP Node Read time: " << endl;
    crimeTimerOOP.displayInformation();
    cout << "A difference of: " << crimeTimerOOP.getTimeInMicroseconds() - crimeTimerSTL.getTimeInMicroseconds() << " microseconds" << endl;


    musicSTL.startTimer();
    vector<Music> tunez = FileController :: musicDataToVector("");
    musicSTL.stopTimer();
    
    musicOOP.startTimer();
    vector<Music> musicList = FileController :: musicDataToList("");
    musicOOP.stopTimer();
    
    cout << "This is the STL Read time: " << endl;
    musicSTL.displayInformation();
    cout <<  "This is the OOP Node Read time: " << endl;
    musicOOP.displayInformation();
    cout << "A difference of: " << musicOOP.getTimeInMicroseconds() - musicSTL.getTimeInMicroseconds() << " microseconds" << endl;
    
    crimeTimerOOP.resetTimer();
    crimeTimerSTL.resetTimer();
    musicOOP.resetTimer();
    musicSTL.resetTimer();
    
    int randomIndex = rand()% moreCrimes.getSize();
    
    crimeTimerSTL.startTimer();
    crimes[randomIndex];
    crimeTimerSTL.stopTimer();
    
    crimeTimerOOP.startTimer();
    moreCrimes.getFromIndex(randomIndex);
    crimeTimerOOP.stopTimer();
    
    cout << "This is the STL random retrieval: " << endl;
    crimeTimerSTL.displayInformation();
    cout << "This is the OOP Node random retrieval: " << endl;
    crimeTimerOOP.displayInformation();
    cout << "A difference of: " << crimeTimerOOP.getTimeInMicroseconds() - crimeTimerSTL.getTimeInMicroseconds() << " microseconds" << endl;
    
    randomIndex = rand()% musicList.getSize();
    
    musicSTL.startTimer();
    tunez[randomIndex];
    musicSTL.stopTimer();
    
    musicOOP.startTimer();
    musicList.getFromIndex(randomIndex);
    musicOOP.stopTimer();
    
    cout << "This is the STL random retrieval: " << endl;
    musicSTL.displayInformation();
    cout << "This is the OOP Node random retrieval: " << endl;
    musicOOP.displayInformation();
    cout << "A difference of: " << musicOOP.getTimeInMicroseconds() - musicSTL.getTimeInMicroSenconds() << " microseconds" << endl;
    
}

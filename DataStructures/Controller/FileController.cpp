//
//  FileController.cpp
//  DataStructures
//
//  Created by James, Emily on 2/1/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "FileController.hpp"

vector<CrimeData>FileController :: readCrimeDataToVector(string filename)
{
    std:: vector<CrimeData> crimeVector;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    //if the file exists in that path
    if(dataFile.is_open())
    {
        //keep reading until you are at end of line
        while (!dataFile.eof())
        {
            //grab each line from csv
            getline(dataFile, currentCSVLine, '\r');
            //exclude header row
            if(rowCount != 0)
            {
                if(currentCSVLine.length() != 0)
                {
                    CrimeData row(currentCSVLine);
                    crimeVector.push_back(row);
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    
    return crimeVector;
    
}

LinkedList<CrimeData> FileController :: readDataToList(string fileName)
{
    LinkedList<CrimeData>crimes;
    
    string currentCVSLine;
    int rowCount = 0;
    
    ifstream dataFile(fileName);
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            getline(dataFile,currentCVSLine, '\r');
            if(rowCount != 0)
            {
                if(currentCVSLine.length() != 0)
                {
                CrimeData row(currentCVSLine);
                crimes.add(row);
                }
            }
            
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    return crimes;
}

LinkedList<Music> FileController :: musicDataToList(string fileName)
{
    LinkedList<Music>musicList;
    
    string currentCVSLine;
    int rowCount = 0;
    
    ifstream dataFile(fileName);
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            getline(dataFile,currentCVSLine, '\r');
            if(rowCount != 0)
            {
                if(currentCVSLine.length() != 0)
                {
                   Music row(currentCVSLine);
                    musicList.add(row);
                }
            }
            
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    return musicList;
}

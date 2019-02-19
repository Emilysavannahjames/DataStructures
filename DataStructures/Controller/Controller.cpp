//
//  Controller.cpp
//  DataStructures
//
//  Created by James, Emily on 1/28/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#include "Controller.hpp"

void Controller:: start()
{
    cout << "Welcome to the Data Structures App." << endl;
    testLinear();
}

void Controller :: usingNodes()
{
    LinearNode<int> mine(5);
    LinearNode<string> wordHolder("Words can be stored too");
    cout << mine.getData() << endl;
    cout << wordHolder.getData() << endl;
    wordHolder.setData("Replaced text");
    cout << wordHolder.getData() << endl;
}

void Controller :: testLinear()
{
    LinearTester lookieHere;
    lookieHere.testVsSTL();
}

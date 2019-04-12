//
//  FileController.hpp
//  DataStructures
//
//  Created by James, Emily on 2/1/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "../Model/Linear/Array.hpp"
#include "../Model/Linear/LinkedList.hpp"
//#include "../Model/NonLinear/BinarySearchTree.hpp"

#include "../Data/CrimeData.hpp"
#include "../Data/Music/Music.hpp"


class FileController
{
public:
    static vector<CrimeData> readCrimeDataToVector(string filename);
    static vector<Music> musicDataToVector(string filename);
    
    static Array<Music> musicDataToArray(string filename);
    static LinkedList<CrimeData> readDataToList(string filename);
    static LinkedList<Music> musicDataToList(string filename);
    //static BinarySearchTree<CrimeData> readDataToTree(string filename);
    //static BinarySearchTree<Music> musicDataToTree(string filename);
};

#endif /* FileController_hpp */

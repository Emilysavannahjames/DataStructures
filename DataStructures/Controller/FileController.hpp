//
//  FileController.hpp
//  DataStructures
//
//  Created by James, Emily on 2/1/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include <stdio.h>

class FileController
{
public:
    static vector<CrimeData> readCrimeDataToVector(string filename);
    static vector<Music> musicDataToVector(string filename);
};

#endif /* FileController_hpp */

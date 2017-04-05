/*
 * Distributed under the OSI-approved Apache License, Version 2.0.  See
 * accompanying file Copyright.txt for details.
 *
 * PrintData.cpp
 *
 *  Created on: Apr 2017
 *      Author: Norbert Podhorszki
 */

#include "PrintData.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

void printData(double *xy, uint64_t *size, uint64_t *offset, int rank, int steps)
{
    std::ofstream myfile;
    std::string filename = "data." + std::to_string(rank);
    myfile.open (filename);
    double *data = xy;
    uint64_t nelems = size[0]*size[1];
    for (int step = 0; step < steps; step++)
    {
        myfile << "rank=" << rank << " size=" << size[0] << "x" << size[1] <<
                " offsets=" << offset[0] << ":" << offset[1] <<
                " step=" << step << std::endl;

        myfile << " time   row   columns " << offset[1] << "..." <<
                offset[1]+size[1]-1 << std::endl;
        myfile << "        ";
        for( int j=0; j < size[1]; j++ )
        {
            myfile << std::setw(9) << offset[1]+j;
        }
        myfile << std::endl;
        myfile << "--------------------------------------------------------------\n";
        for( int i=0; i < size[0]; i++ )
        {
            myfile << std::setw(5) << step << std::setw(5) << offset[0]+i;
            for( int j=0; j < size[1]; j++ )
            {
                myfile << std::setw(9) << std::setprecision(2) <<  data[ i*size[1]+j ];
            }
            myfile << std::endl;
        }
        data += nelems;
    }
    myfile.close();
}


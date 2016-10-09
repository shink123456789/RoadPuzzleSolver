/*
 * main.cpp
 *
 *  Created on: 2016/06/26
 *      Author: sk
 */

#include <gtest/gtest.h>
#include <cstdio>

//#define GTEST_DEBUG

#include "RoadPuzzleSolver.h"


#ifdef GTEST_DEBUG
int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
#else
int main(){
	RoadPuzzleSolver solver;
	std::cout << "RoadPuzzleSolver created." << std::endl;
	solver.solve();
	return 0;
#endif
}



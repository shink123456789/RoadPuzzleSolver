/*
 * RoadPuzzleSolver.h
 *
 *  Created on: 2016/06/26
 *      Author: sk
 */

#ifndef ROADPUZZLESOLVER_H_
#define ROADPUZZLESOLVER_H_

class RoadPuzzleSolver {
	friend class RoadPuzzleSolverTest;
public:
	RoadPuzzleSolver();
	virtual ~RoadPuzzleSolver();
	void solve();
};

#endif /* ROADPUZZLESOLVER_H_ */

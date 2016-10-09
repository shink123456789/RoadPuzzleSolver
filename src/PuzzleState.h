/*
 * PuzzleState.h
 *
 *  Created on: 2016/06/26
 *      Author: sk
 */

#ifndef PUZZLESTATE_H_
#define PUZZLESTATE_H_

#include <list>
#include <vector>

#include "PuzzlePiece.h"
#include "Position.h"
#include "PuzzleField.h"

class PuzzleStateTest;

class PuzzleState {
	friend class PuzzleStateTest;
public:
    PuzzleState(const PuzzleState&, const PuzzlePiece&, const std::vector<PuzzlePiece>&);
    PuzzleState(const PuzzlePiece&, const std::vector<PuzzlePiece>&, int, int);
    PuzzleState(const std::vector<PuzzlePiece>&, int, int);
    std::list<PuzzleState> getAllSolutions()const;
    const PuzzleField& getField()const{return field_;}
    void printPastRoads();
    const std::vector<PuzzlePiece>& getRestPieces()const{return restPieces_;}
    const std::vector<PuzzlePiece>& getUsedPieces()const{return usedPieces_;}

private:
	PuzzleField field_;
	Position currentPosition_;
	std::vector<PuzzlePiece> usedPieces_;
	const std::vector<PuzzlePiece> restPieces_;
	bool unsolvable_ = false;

	bool isSolved()const;
	bool unsolvable()const;
	bool act(const RoadAct& p);
	bool walkAlongPiece(const PuzzlePiece& startPiece);
};

std::ostream& operator<<(std::ostream&, const PuzzleState&);



#endif /* PUZZLESTATE_H_ */

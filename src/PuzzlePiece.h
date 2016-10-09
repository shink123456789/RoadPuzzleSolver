/*
 * PuzzlePiece.h
 *
 *  Created on: 2016/06/26
 *      Author: sk
 */

#ifndef PUZZLEPIECE_H_
#define PUZZLEPIECE_H_

#include "RoadAct.h"

#include <string>
#include <vector>

class PuzzlePieceTest;

class PuzzlePiece {
    friend PuzzlePieceTest;
public:
    explicit PuzzlePiece(const std::string&);
	PuzzlePiece(const std::string&, const std::string&);
	virtual ~PuzzlePiece();
	std::vector<RoadAct> strToWalk(const std::string& str);
	PuzzlePiece reverse()const;
	std::string toString()const;
	bool operator ==(const PuzzlePiece &constPuzzlePiece)const;
	const std::vector<RoadAct>& getWalk() const{
		return walk_;
	}

private:
	std::vector<RoadAct> walk_;
	std::vector<RoadAct> reverseWalk_;
};

std::ostream& operator<<(std::ostream& out, const PuzzlePiece&);

#endif /* PUZZLEPIECE_H_ */

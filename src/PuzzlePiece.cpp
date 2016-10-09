/*
 * PuzzlePiece.cpp
 *
 *  Created on: 2016/06/26
 *      Author: sk
 */

#include "PuzzlePiece.h"

#include <iostream>
#include <sstream>
#include <iterator>

std::vector<RoadAct> PuzzlePiece::strToWalk(const std::string& str){
    std::vector<RoadAct> walk;
    for(std::string::const_iterator it = str.begin();it != str.end();++it){
        switch(*it){
        case 'S': walk.push_back(RoadAct::START); break;
        case 'F': walk.push_back(RoadAct::FILL); break;
        case 'G': walk.push_back(RoadAct::GO); break;
        case 'E': walk.push_back(RoadAct::END); break;
        case 'R': walk.push_back(RoadAct::TURNRIGHT); break;
        case 'L': walk.push_back(RoadAct::TURNLEFT); break;
        case 'W': walk.push_back(RoadAct::WAIT); break;
        case 'C': walk.push_back(RoadAct::COME); break;
        }
    }
    return walk;
};

PuzzlePiece::PuzzlePiece(const std::string& normalStr){
    walk_ = strToWalk(normalStr);
    reverseWalk_ = strToWalk("");
}
PuzzlePiece::PuzzlePiece(const std::string& normalStr, const std::string& reverseStr){
    walk_ = strToWalk(normalStr);
    reverseWalk_ = strToWalk(reverseStr);
}

PuzzlePiece::~PuzzlePiece() {
}

PuzzlePiece PuzzlePiece::reverse()const{
    PuzzlePiece copy(*this);
    copy.walk_ = reverseWalk_;
    copy.reverseWalk_ = walk_;
    return copy;
}


std::ostream& operator<<(std::ostream& out, const PuzzlePiece& pp){
    for(auto& ra : pp.getWalk()){
        out << ra;
    }
    return out;
}

std::string PuzzlePiece::toString()const
{
    std::stringstream retStrS;
	for(std::vector<RoadAct>::const_iterator it = walk_.begin();it != walk_.end(); ++it){
	    retStrS << *it;
	}
	return retStrS.str();
}

bool PuzzlePiece::operator ==(const PuzzlePiece &constPuzzlePiece) const {
	if(constPuzzlePiece.walk_.size() == walk_.size()){
		for(size_t i=0;i < constPuzzlePiece.walk_.size();i++){
			if(constPuzzlePiece.walk_[i] != walk_[i]){
				return false;
			}
		}
		return true;
	}else{
		return false;
	}
}

/*
 * PuzzleState.cpp
 *
 *  Created on: 2016/06/26
 *      Author: sk
 */

#include "PuzzleState.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <list>

/* This constructor is not needed (except for unit-test) */
PuzzleState::PuzzleState(const std::vector<PuzzlePiece>& restPieces, int maxWidth, int maxHeight):
    field_(maxWidth, maxHeight),
        currentPosition_(0, 0, Direction::NORTH),
        restPieces_(restPieces)
{
}

PuzzleState::PuzzleState(const PuzzlePiece& nextPiece, const std::vector<PuzzlePiece>& restPieces, int maxWidth, int maxHeight):
        field_(maxWidth, maxHeight),
        currentPosition_(0, 0, Direction::NORTH),
        restPieces_(restPieces)
{
    if(!walkAlongPiece(nextPiece)){
        unsolvable_ = true;
    }
    usedPieces_.push_back(nextPiece);
}

PuzzleState::PuzzleState(const PuzzleState& src, const PuzzlePiece& nextPiece, const std::vector<PuzzlePiece>& restPieces):
            field_(src.field_),
            currentPosition_(src.currentPosition_),
            restPieces_(restPieces)
{
	std::copy(src.usedPieces_.begin(), src.usedPieces_.end(),std::back_inserter(usedPieces_));
	if(!walkAlongPiece(nextPiece)){
	    unsolvable_ = true;
	}
	usedPieces_.push_back(nextPiece);
}

std::ostream& operator<<(std::ostream& out, const PuzzleState& ps){
    out << "PuzzleState(";
    const std::vector<PuzzlePiece>& rest = ps.getRestPieces();
    out << " Rest(" << rest.size() << "):";
    bool flgFirst = true;
    for(auto& rp : rest){
        if(flgFirst){
            out << rp;
            flgFirst = false;
        }else{
            out << "," << rp;
        }
    }
    const std::vector<PuzzlePiece>& used = ps.getUsedPieces();
    out << " Used(" << used.size() << "):";
    flgFirst = true;
    for(auto& up : used){
        if(flgFirst){
            out << up;
            flgFirst = false;
        }else{
            out << "," << up;
        }
    }
    out << "),";
    out << std::endl;
    out << ps.getField();
    return out;
}

std::list<PuzzleState> PuzzleState::getAllSolutions() const{
    std::list<PuzzleState> result;
    if(unsolvable()){
        std::cout << "x";
        return result;
    }
    if(isSolved()){ /* end */
        /* if success, add to result */
        result.push_back(*this);
        std::cout << "!" << std::endl;
        return result;
    }
    std::vector<PuzzlePiece> copyOfRestPieces = restPieces_;
    PuzzlePiece prevp("");
	for(std::vector<PuzzlePiece>::const_iterator rpIt = copyOfRestPieces.begin();rpIt != copyOfRestPieces.end();++rpIt){
	    PuzzlePiece p = *rpIt;
	    if(p == prevp){ /* deduplicate solving */
	        continue;
	    }
//	    std::cout << "Picked : " << p << std::endl;
//	    std::cout << " Field : " << field_ << std::endl;
	    rpIt = copyOfRestPieces.erase(rpIt);
	    auto func = [&](const PuzzlePiece& p){
	        PuzzleState newps = PuzzleState(*this, p, copyOfRestPieces); /* copy */
	        std::list<PuzzleState> resultSub = newps.getAllSolutions();
	        std::cout << ".";
	        if(resultSub.size() != 0){
	            result.splice(result.end(), resultSub);
	        }
	    };
	    func(p);
	    PuzzlePiece pr = p.reverse();
	    if(pr.getWalk().size() > 0){
//	        std::cout << "Picked(Rev) : " << pr << std::endl;
//	        std::cout << " Field : " << field_ << std::endl;
	        func(pr);
	    }
        prevp = p;
	    rpIt = copyOfRestPieces.insert(rpIt, p);
	}
	std::cout << std::endl;
	return result;
}

bool PuzzleState::isSolved() const{
    if(restPieces_.size() == 0){
        return true;
    }
    /* TODO check couple block */
    return false;
}

bool PuzzleState::unsolvable() const{
    if(unsolvable_)return true;
    if(field_.outOfRange())return true;
    return false;
}

bool PuzzleState::act(const RoadAct& ra){
    switch(ra){
        case RoadAct::TURNRIGHT:
            currentPosition_.rotateRight();
            break;
        case RoadAct::TURNLEFT:
            currentPosition_.rotateLeft();
            break;
        case RoadAct::FILL:
            if(!field_.fill(currentPosition_)){
                return false; /* TODO use error class */
            }
            break;
        case RoadAct::GO:
            currentPosition_.goStraight();
            break;
        case RoadAct::START:
            break;
        case RoadAct::END:
            if(restPieces_.size() > 0){
                return false;
            }
            break;
        case RoadAct::WAIT:
            if(!field_.wait(currentPosition_)){
                return false; /* TODO use error class */
            }
            break;
        case RoadAct::COME:
            if(!field_.come(currentPosition_)){
                return false; /* TODO use error class */
            }
            break;
    }
    return true;
}

bool PuzzleState::walkAlongPiece(const PuzzlePiece& piece) {
	for(std::vector<RoadAct>::const_iterator walkIt = piece.getWalk().begin();
			walkIt != piece.getWalk().end();++walkIt){
	    if(!act(*walkIt)){
	        return false;
	    }
	}
	return true;
}

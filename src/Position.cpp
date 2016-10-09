/*
 * Position.cpp
 *
 *  Created on: 2016/06/26
 *      Author: sk
 */

#include "Position.h"

Position::Position(int x, int y, const Direction& dir):x_(x), y_(y), dir_(dir) {
}

Position::~Position() {
	// TODO Auto-generated destructor stub
}

void Position::rotateRight(){
    switch(dir_){
    case Direction::NORTH:dir_ = Direction::EAST; break;
    case Direction::EAST :dir_ = Direction::SOUTH; break;
    case Direction::SOUTH:dir_ = Direction::WEST; break;
    case Direction::WEST :dir_ = Direction::NORTH; break;
    }
}

void Position::rotateLeft(){
    switch(dir_){
    case Direction::NORTH:dir_ = Direction::WEST; break;
    case Direction::EAST :dir_ = Direction::NORTH; break;
    case Direction::SOUTH:dir_ = Direction::EAST; break;
    case Direction::WEST :dir_ = Direction::SOUTH; break;
    }
}

void Position::goStraight(){
    switch(dir_){
    case Direction::NORTH: y_ --; break;
    case Direction::EAST : x_ ++; break;
    case Direction::SOUTH: y_ ++; break;
    case Direction::WEST : x_ --; break;
    }
}

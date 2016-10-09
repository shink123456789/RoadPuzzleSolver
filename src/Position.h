/*
 * Position.h
 *
 *  Created on: 2016/06/26
 *      Author: sk
 */

#ifndef POSITION_H_
#define POSITION_H_

#include "Direction.h"

class PositionTest;

class Position {
    friend class PositionTest;
public:
	Position(int x, int y, const Direction&);
	virtual ~Position();
	void rotateRight();
	void rotateLeft();
	void goStraight();
	int getX()const { return x_;}
    int getY()const { return y_;}
    const Direction& getDirection()const{ return dir_;}
private:
	int x_;
	int y_;
	Direction dir_;
};

#endif /* POSITION_H_ */

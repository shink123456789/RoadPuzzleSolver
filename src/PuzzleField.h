/*
 * PuzzleField.h
 *
 *  Created on: 2016/10/02
 *      Author: ks
 */

#ifndef PUZZLEFIELD_H_
#define PUZZLEFIELD_H_

#include "Position.h"

#include <string>
#include <sstream>

class PuzzleFieldTest;

class PuzzleField {
    friend class PuzzleFieldTest;
    static const int MAX_X = 30;
    static const int MAX_Y = 30;
    static const int CENTER_X = 15;
    static const int CENTER_Y = 15;
    const int width_;
    const int height_;
    int right_ = 0;
    int left_ = MAX_X;
    int top_ = MAX_Y;
    int bottom_ = 0;
    int waitx_ = -100;
    int waity_ = -100;
    bool filled_[MAX_X][MAX_Y];
public :
    PuzzleField(int, int);
    PuzzleField(const PuzzleField&);
    bool fill(const Position&);
    bool wait(const Position&);
    bool come(const Position&)const;
    bool outOfRange()const;
    bool isFilled(int x, int y)const;
    void setFilled(int x, int y);
    int getMaxWidth()const{return width_;}
    int getMaxHeight()const{return height_;}
    std::string toString()const;
};

std::ostream& operator<<(std::ostream&, const PuzzleField&);

#endif /* PUZZLEFIELD_H_ */

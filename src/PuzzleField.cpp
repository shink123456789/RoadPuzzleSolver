/*
 * PuzzleField.cpp
 *
 *  Created on: 2016/10/02
 *      Author: ks
 */

#include "PuzzleField.h"

#include <iostream>

PuzzleField::PuzzleField(int width, int height):width_(width), height_(height){
    for(int x=0;x<MAX_X;x++){
        for(int y=0;y<MAX_Y;y++){
            filled_[x][y] = false;
        }
    }
}

PuzzleField::PuzzleField(const PuzzleField& p):width_(p.width_), height_(p.height_), right_(p.right_),left_(p.left_), top_(p.top_),bottom_(p.bottom_){
    for(int x=0;x<MAX_X;x++){
        for(int y=0;y<MAX_Y;y++){
            filled_[x][y] = p.filled_[x][y];
        }
    }
    waitx_ = p.waitx_;
    waity_ = p.waity_;
}

std::string PuzzleField::toString()const{
    std::stringstream ss;
    ss << "l=" << left_ << ",r=" << right_ << ",t=" << top_ << ",b=" << bottom_ << std::endl;
    for(int y=top_;y<=bottom_;y++){
        for(int x=left_;x<=right_;x++){
            ss << (isFilled(x,y)?"o":".");
        }
        ss << std::endl;
    }
    ss << "wait =(" << waitx_ << "," << waity_ << ")" <<  std::endl;
    return ss.str();
}

std::ostream& operator<<(std::ostream& out, const PuzzleField& pf){
    out << pf.toString();
    return out;
}

bool PuzzleField::fill(const Position& pos){
    if(isFilled(pos.getX(),pos.getY())){
        return false;
    }else{
        setFilled(pos.getX(), pos.getY());
        if(pos.getX() > right_ ){right_  = pos.getX();}
        if(pos.getX() < left_  ){left_   = pos.getX();}
        if(pos.getY() > bottom_){bottom_ = pos.getY();}
        if(pos.getY() < top_   ){top_    = pos.getY();}
        return true;
    }
}

bool PuzzleField::wait(const Position& pos){
    if(isFilled(pos.getX(),pos.getY())){
        return false;
    }
    waitx_ = pos.getX();
    waity_ = pos.getY();
    return true;
}

bool PuzzleField::come(const Position& pos)const{
    if(waitx_ == pos.getX() && waity_ == pos.getY()){
        return true;
    }else{
        return false;
    }
}

bool PuzzleField::outOfRange()const{
    int width = right_ - left_ + 1;
    int height = bottom_ - top_ + 1;
    if(width < 0 && height < 0){
        return false;
    }
    if( (width <= width_ && height <= height_) || (width <= height_ && height <= width_)){
        return false;
    }else{
        return true;
    }
}

bool PuzzleField::isFilled(int x, int y)const{
    return filled_[x + CENTER_X][y + CENTER_Y];
}

void PuzzleField::setFilled(int x, int y){
    filled_[x + CENTER_X][y + CENTER_Y] = true;
}

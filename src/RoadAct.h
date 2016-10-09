/*
 * RoadAct.h
 *
 *  Created on: 2016/10/2
 *      Author: sk
 */

#ifndef ROADACT_H_
#define ROADACT_H_

#include <ostream>

enum class RoadAct
{
    TURNRIGHT = 0,
    TURNLEFT = 1,
    FILL = 2,
    GO = 3,
    START = 4,
    END = 5,
    WAIT = 6,
    COME = 7,
};

std::ostream& operator<< (std::ostream&, const RoadAct&);

#endif

/*
 * RoadAct.cpp
 *
 *  Created on: 2016/10/02
 *      Author: ks
 */

#include "RoadAct.h"

std::ostream& operator<< (std::ostream& out, const RoadAct& ra){
    switch(ra){
    case RoadAct::START:    out << std::string("S");break;
    case RoadAct::FILL:     out << std::string("F");break;
    case RoadAct::GO:       out << std::string("G");break;
    case RoadAct::END:      out << std::string("E");break;
    case RoadAct::TURNRIGHT:out << std::string("R");break;
    case RoadAct::TURNLEFT: out << std::string("L");break;
    case RoadAct::WAIT:     out << std::string("W");break;
    case RoadAct::COME:     out << std::string("C");break;
    }
    return out;
}

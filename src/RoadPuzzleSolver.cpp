/*
 * RoadPuzzleSolver.cpp
 *
 *  Created on: 2016/06/26
 *      Author: sk
 */

#include "RoadPuzzleSolver.h"

#include <iostream>

#include "PuzzlePiece.h"
#include "PuzzleState.h"

RoadPuzzleSolver::RoadPuzzleSolver() {
}

RoadPuzzleSolver::~RoadPuzzleSolver() {
}

void RoadPuzzleSolver::solve(){
    std::vector<PuzzlePiece> pieces;
    pieces.push_back(PuzzlePiece("FGFLG"      ,"FRGFG"));      /* --^   */
    pieces.push_back(PuzzlePiece("FRGFLLGRG"  ,"FLGFRRGLG"));  /* |  () */
    pieces.push_back(PuzzlePiece("FGFG"));                     /* --    */
    pieces.push_back(PuzzlePiece("FGFRRGLG"   ,"FRGFLLGG"));   /* -v () */
    pieces.push_back(PuzzlePiece("FGFRRGLG"   ,"FRGFLLGG"));   /* -v () */
    pieces.push_back(PuzzlePiece("FGFRG"      ,"FLGFG"));      /* --v   */
    pieces.push_back(PuzzlePiece("FRGFRG"     ,"FLGFLG"));     /* u */
    pieces.push_back(PuzzlePiece("FRGFRG"     ,"FLGFLG"));     /* u */
    pieces.push_back(PuzzlePiece("FRGFRG"     ,"FLGFLG"));     /* u */
    pieces.push_back(PuzzlePiece("FRGFRG"     ,"FLGFLG"));     /* u */
    pieces.push_back(PuzzlePiece("FRGFRG"     ,"FLGFLG"));     /* u */
    pieces.push_back(PuzzlePiece("FRGFRG"     ,"FLGFLG"));     /* u */
    pieces.push_back(PuzzlePiece("FRGWLLGRG"  ,"FLGWRRGLG"));  /* |     # half of one piece */
    pieces.push_back(PuzzlePiece("FCG"));                      /* |     # half of one piece */
    pieces.push_back(PuzzlePiece("FGFE"));                     /* -- end piece */
    PuzzleState puzzleToSolve(PuzzlePiece("SFGFRG"), pieces, 5, 6);
    std::list<PuzzleState> results = puzzleToSolve.getAllSolutions();
    std::cout << "RoadPuzzleSolver::solved." << std::endl;
    std::cout << " result.size = " << results.size() << std::endl;
    for(auto ps : results){
        std::cout << ps << std::endl;
    }
}

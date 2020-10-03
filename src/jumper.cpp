//
// Created by victor on 02/10/2020.
//

#include "jumper.h"


int Jumper::jump()  {
    if (jumps[1][0] == -2 || jumps[0][0] == -2) {
        for (int i = lastStone; i >= 0; --i) {
            for (int gi = 0; gi <= 1; ++gi) {
                int g = gi;
                int newPos = i, jumpSize = g? bJ : sJ;
                switch (maiorPuloPossivel(i, newPos, jumpSize)) {
                    case BIG:
                        jumps[g][i] = jumps[0][newPos] + 1;
                        break;
                    case SMALL:
                        jumps[g][i] = jumps[1][newPos] + 1;
                        break;
                    default:
                        jumps[g][i] = -1;
                        break;
                }
            }
        }
    }
    if (jumps[1][0] == -1 || jumps[0][0] == -1) {
        return std::max(jumps[1][0], jumps[0][0]);
    }
    return std::min(jumps[1][0], jumps[0][0]);
}

bool Jumper::podePulo(int &newPos, int jSize) {
    int pos = newPos++;
    while (newPos < (lastStone + 1) && path[newPos] - path[pos] < jSize) { ++newPos; }
    return path[newPos] - path[pos] == jSize; //otherwise it's bigger than jSize
}
JumpType Jumper::maiorPuloPossivel(int pos, int &newPos, int jumpSize) {
    if(podePulo(newPos, jumpSize) && jumps[0][newPos] != -1) {
        if (jumpSize > sJ) {
            return BIG;
        }
        else {
            return SMALL;
        }
    }
    else {
        if (newPos != lastStone + 1) {
            newPos--;
        }
        if (newPos == pos) {
            return ERR;
        }
        else if (path[newPos] - path[pos] > sJ) {
            if (jumps[0][newPos] == -1) {
                return ERR;
            }
            return BIG;
        }
        else {
            if (jumps[1][newPos] == -1) {
                return ERR;
            }
            return SMALL;
        }
    }
}
//
// Created by victor on 02/10/2020.
//

#include "jumper.h"


bool Jumper::podePulo(int &newPos, int jSize) {
    int pos = newPos++;
    while (newPos <= (lastStone + 1) && path[newPos] - path[pos] < jSize) { ++newPos; }
    return path[newPos] - path[pos] == jSize; //otherwise it's bigger than jSize
}

bool Jumper::podePuloGrande(int &newPos) {
    int pos;
    for (int i = bJ; i > sJ; --i) {
        pos = newPos;
        if (podePulo(pos, i)) {
            newPos = pos;
            return true;
        }
    }
    return false;
}

bool Jumper::podePuloPequeno(int &newPos) {
    int pos;
    for (int i = sJ; i > 0; --i) {
        pos = newPos;
        if (podePulo(pos, i)) {
            newPos = pos;
            return true;
        }
    }
    return false;
}

int Jumper::jump(bool g, int pos) {
    if (path[pos] == END) {
        return 0;
    }
    try {
        int newPos = pos;
        if (g && podePuloGrande(newPos)) {
            if(jumps[int(g)][pos] == -1) {
                jumps[int(g)][pos] = jump(false, newPos) + 1;
            }
            return jumps[int(g)][pos];
        }
    }
    catch (std::exception &e) {}
    try {
        int newPos = pos;
        if (podePuloPequeno(newPos)) {
            if(jumps[int(g)][pos] == -1) {
                jumps[int(g)][pos] = jump(true, newPos) + 1;
            }
            return jumps[int(g)][pos];
        }
    }
    catch (std::exception &e) {}
    throw std::exception();
}

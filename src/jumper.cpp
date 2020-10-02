//
// Created by victor on 02/10/2020.
//

#include "jumper.h"


bool Jumper::podePulo(int &newPos, int jSize) {
    int pos = newPos++;
    while (path[newPos] - path[pos] < jSize && newPos <= (lastStone + 1)) { ++newPos; }
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
            return jump(false, newPos) + 1;
        }
    }
    catch (std::exception &e) {}
    try {
        int newPos = pos;
        if (podePuloPequeno(newPos)) {
            return jump(true, newPos) + 1;
        }
    }
    catch (std::exception &e) {}
    throw std::exception();
}

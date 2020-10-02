//
// Created by victor on 02/10/2020.
//

#include "jumper.h"


int Jumper::dist(int a, int b) {
    if(a < b) {
        return path[b] - path[a];
    }
    return path[a] - path[b];
}

bool Jumper::podePulo(int &newPos, int jSize) {
    int pos = newPos;
    while (dist(pos,newPos) <= jSize && newPos <= lastStone) {
        newPos++;
    }
    if (newPos <= lastStone) {
        newPos--;
    }//TODO: return false if jump is bigger than the margin distance
    return newPos != pos;
}

bool Jumper::podePuloGrande(int &newPos) {
    for (int i = bJ; i > sJ; --i) {
        if (podePulo(newPos, i)) {
            return true;
        }
    }
    return false;
}

bool Jumper::podePuloPequeno(int &newPos) {
    for (int i = sJ; i > 0; --i) {
        if (podePulo(newPos, i)) {
            return true;
        }
    }
    return false;
}

int Jumper::jump(unsigned char g, int pos) {
    if (path[pos] == END) {
        return 1;
    }
    try {
        int newPos = pos;
        if (g > 0 && podePuloGrande(newPos)) {
            return jump(g-1, newPos) + 1;
        }
    }
    catch (std::exception &e) {}
    try {
        int newPos = pos;
        if (podePuloPequeno(newPos)) {
            return jump(g, newPos) + 1;
        }
    }
    catch (std::exception &e) {}
    throw std::exception();
}

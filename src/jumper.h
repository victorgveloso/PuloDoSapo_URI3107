//
// Created by victor on 02/10/2020.
//

#ifndef PULODOSAPO_URI3107_JUMPER_H
#define PULODOSAPO_URI3107_JUMPER_H

#include <bits/stdc++.h>

class Jumper {
public:
    int *path;
    int END = 1;
    int bJ = 2;
    int sJ = 1;
    int lastStone;
    int *jumps[2] = {new int[1000002], new int[1000002]};

    Jumper() : path(new int[1000002]()) {
        for (int i = 0; i < 1000002; ++i) {
            jumps[0][i] = -1;
            jumps[1][i] = -1;
        }
    }

    Jumper(int *path,
           int END,
           int bJ,
           int sJ,
           int lastStone) : path(path), END(END), bJ(bJ), sJ(sJ), lastStone(lastStone) {
        for (int i = 0; i < 1000002; ++i) {
            jumps[0][i] = -1;
            jumps[1][i] = -1;
        }
    }

    bool podePulo(int &newPos, int jSize);

    bool podePuloGrande(int &newPos);

    bool podePuloPequeno(int &newPos);

    int jump() { return jump(true, 0); }

    int jump(bool g, int pos);
};


#endif //PULODOSAPO_URI3107_JUMPER_H

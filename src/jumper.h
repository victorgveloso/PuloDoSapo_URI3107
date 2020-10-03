//
// Created by victor on 02/10/2020.
//

#ifndef PULODOSAPO_URI3107_JUMPER_H
#define PULODOSAPO_URI3107_JUMPER_H

#include <bits/stdc++.h>
enum JumpType {BIG, SMALL, ERR};
class Jumper {
public:
    int *path;
    int bJ = 2;
    int sJ = 1;
    int lastStone;
    int *jumps[2] = {new int[1000002], new int[1000002]};

    Jumper(int *path, int bJ, int sJ, int lastStone) : path(path), bJ(bJ), sJ(sJ), lastStone(lastStone) {
        jumps[0][lastStone + 1] = 0;
        jumps[1][lastStone + 1] = 0;
        jumps[0][0] = -2;
        jumps[1][0] = -2;
    }

    bool podePulo(int &newPos, int jSize);

    int jump();

    JumpType maiorPuloPossivel(int i, int &newPos, int &jumpSize);
};


#endif //PULODOSAPO_URI3107_JUMPER_H

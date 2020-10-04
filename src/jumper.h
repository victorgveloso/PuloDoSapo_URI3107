//
// Created by victor on 02/10/2020.
//

#ifndef PULODOSAPO_URI3107_JUMPER_H
#define PULODOSAPO_URI3107_JUMPER_H

#include <bits/stdc++.h>
enum JumpType {BIG, SMALL, ERR};
class Jumper {
private:
    int *maxJump[2] = {new int[1000002](), new int[1000002]()};
    int *path;
    int bJ = 2;
    int sJ = 1;
    int lastStone;
    int *jumps[2] = {new int[1000002], new int[1000002]};

    bool podePulo(int &newPos, int jSize);

    JumpType maiorPuloPossivel(int pos, int &newPos, int jumpSize);
public:

    Jumper(int *path, int bJ, int sJ, int lastStone) : path(path), bJ(bJ), sJ(sJ), lastStone(lastStone) {
        int newPos = 1;
        nextPossibleJump(sJ,newPos,0);
        writeCache(sJ, newPos, 0);
        nextPossibleJump(bJ,newPos,0);
        writeCache(bJ, newPos, 0);
        for (int i = 1; i < lastStone + 1; ++i) {
            newPos = maxJump[0][i-1];
            nextPossibleJump(sJ,newPos,i);
            writeCache(sJ, newPos, i);
            nextPossibleJump(bJ,newPos,i);
            writeCache(bJ, newPos, i);
        }
        maxJump[0][lastStone+1] = lastStone+1;
        maxJump[1][lastStone+1] = lastStone+1;
        jumps[0][lastStone + 1] = 0;
        jumps[1][lastStone + 1] = 0;
        jumps[0][0] = -2;
        jumps[1][0] = -2;
    }

    void writeCache(int jumpSize, int &newPos, int pos) {
        if (path[newPos] - path[pos] == jumpSize) {
            maxJump[jumpSize==bJ][pos] = newPos;
        }
        else {
            maxJump[jumpSize==bJ][pos] = --newPos;
        }
    }

    int readCache(int jSize, int newPos) {
        if (jSize == bJ) {
            return maxJump[1][newPos];
        }
        else if (jSize >= sJ) {
            return maxJump[0][newPos];
        }
        else {
            return newPos + 1;
        }
    }

    void nextPossibleJump(int jumpSize, int &newPos, int pos) {
        while (newPos < (lastStone + 1) && path[newPos] - path[pos] < jumpSize) { ++newPos; }
    }

    int jump();
};


#endif //PULODOSAPO_URI3107_JUMPER_H

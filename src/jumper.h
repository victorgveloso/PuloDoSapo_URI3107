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

    Jumper():path(new int[2000000]){}

    Jumper( int *path,
            int END,
            int bJ,
            int sJ,
            int lastStone):path(path),END(END),bJ(bJ),sJ(sJ),lastStone(lastStone){}

    bool podePulo(int &newPos, int jSize);

    bool podePuloGrande(int &newPos);

    bool podePuloPequeno(int &newPos);

    int jump(){return jump(true,0);}
    int jump(bool g, int pos);
};


#endif //PULODOSAPO_URI3107_JUMPER_H

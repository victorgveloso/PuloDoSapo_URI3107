#include <bits/stdc++.h>
std::set<int> pedras;

bool contains(std::set<int> set, int key) {
    return set.find(key) != set.end();
}

bool isJumpPossible(int i, int j) {
    return i < j && contains(pedras,i) && contains(pedras,j);
}

int main() {
    int locStone, marginDist;
    int sJump, bJump;
    std::cin >> locStone >> marginDist;
    pedras.insert(1);
    pedras.insert(marginDist);
    for (int i = 0; i < locStone; ++i) {
        int pedra;
        std::cin >> pedra;
        pedras.insert(pedra);    
    }
    std::cin >> sJump >> bJump;
    int nPulos = 0;
    int pulosGrandesRestantes = 2;
    while (marginDist != 1) {
        int alcancePequeno = (marginDist - sJump) % marginDist;
        int alcanceGrande = (marginDist - bJump) % marginDist;
        if(isJumpPossible(marginDist, alcancePequeno)) {
            ++nPulos;
        } else if (pulosGrandesRestantes > 0 && isJumpPossible(marginDist, alcanceGrande)) {
            ++nPulos;
            --pulosGrandesRestantes;
        }
        else {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    std::cout << nPulos << std::endl;
    return 0;
}

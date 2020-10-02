#include "jumper.h"
int main() {
    Jumper j;
    std::cin >> j.lastStone >> j.END;
    j.path[0] = 1;
    j.path[j.lastStone + 1] = j.END;
    for (int stone = 1; stone <= j.lastStone; ++stone) {
        int dist;
        std::cin >> dist;
        j.path[stone] = dist;
    }
    std::cin >> j.sJ >> j.bJ;
    try {
        std::cout << j.jump() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << -1 << std::endl;
    }
    return 0;
}
#include "jumper.h"
int main() {
    std::ostream::sync_with_stdio(false);
    int lastStone, END, sJ, bJ;
    int *path = {new int[1000002]};
    std::cin >> lastStone >> END;
    path[0] = 1;
    path[lastStone + 1] = END;
    for (int stone = 1; stone <= lastStone; ++stone) {
        int dist;
        std::cin >> dist;
        path[stone] = dist;
    }
    std::cin >> sJ >> bJ;
    Jumper j(path, bJ, sJ, lastStone);
    std::cout << j.jump() << std::endl;
    return 0;
}
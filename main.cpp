#include "classes.hpp"

#include <iostream>

int main() {
    Cube c{7};

    std::cout << "Side  : " << c.side() << '\n' << "Volume: " << c.volume() << '\n';

    std::cout << "Done.\n";
}

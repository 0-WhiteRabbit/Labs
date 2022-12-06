#include <iostream>
#include "vector/Vector.h"

int main() {
    Vector<int> t;

    t.push_back(122);
    t.push_back(23);
    t.erase(0);

    std::cout << t.size() << " " << t[0] << std::endl;
    return 0;
}

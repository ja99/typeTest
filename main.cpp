#include <iostream>
#include <array>
#include "Field.h"


int main() {
    Field<3> field(8);
    std::cout << field.toString() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

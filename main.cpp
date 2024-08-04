#include <iostream>
#include <array>
#include "Field.h"
#include "Messages/ExampleMessage.h"


int main() {
    Field<3> field(5);
    std::cout << field.toString() << std::endl;
    std::cout << "Hello, World!" << std::endl;

    auto msg = ExampleMessage(0, 2, 3, 1);
    std::cout << msg.toString() << std::endl;
    return 0;
}

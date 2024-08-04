#include <iostream>
#include <array>
#include "Field.h"
#include "Messages/ExampleMessage.h"


int main() {
    std::cout << "Valid Field init:" << std::endl;
    Field<3> field(7);
    std::cout << field.toString() << std::endl;

    std::cout << std::endl << "Invalid Field init:" << std::endl;
    try {
        Field<3> field2(8);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "Valid ExampleMessage init:" << std::endl;
    auto msg = ExampleMessage(0, 2, 3, 1);
    std::cout << msg.toString() << std::endl;
    auto bytes = msg.toBits();

    // ToDo: use either big or little endian
    std::cout << "currently inconsistent in regards to little and big endian" << std::endl;
    for (int i = 0; i < bytes.size(); ++i) {
        std::cout << bytes[i];
        if (i % 8 == 7) {
            std::cout << " ";
        }
    }


    return 0;
}

//
// Created by janis on 04.08.24.
//

#ifndef TYPETEST_EXAMPLEMESSAGE_H
#define TYPETEST_EXAMPLEMESSAGE_H

#include "../Field.h"

struct ExampleMessage{
    Field<4> id = Field<4>(0, "ID", "The ID of the message");
    Field<3> length = Field<3>(0, "Length", "The length of the message");
    Field<8> data = Field<8>(0, "Data", "The data of the message");
    Field<1> parity = Field<1>(0, "Parity", "The parity of the message");

    explicit ExampleMessage(int id, int length, int data, int parity) {
        this->id = Field<4>(id, "ID", "The ID of the message");
        this->length = Field<3>(length, "Length", "The length of the message");
        this->data = Field<8>(data, "Data", "The data of the message");
        this->parity = Field<1>(parity, "Parity", "The parity of the message");
    }

    std::string toString() {
        auto result = std::string();
        result += "ID: " + id.toString() + "\n";
        result += "Length: " + length.toString() + "\n";
        result += "Data: " + data.toString() + "\n";
        result += "Parity: " + parity.toString() + "\n";
        return result;
    }

    std::array<bool, 16> toBits() {
        std::array<bool, 16> bits{};
        for (int i = 0; i < 4; ++i) {
            bits[i] = id.bits[i];
        }
        for (int i = 0; i < 3; ++i) {
            bits[i + 4] = length.bits[i];
        }
        for (int i = 0; i < 8; ++i) {
            bits[i + 7] = data.bits[i];
        }
        bits[15] = parity.bits[0];
        return bits;
    }


};


#endif //TYPETEST_EXAMPLEMESSAGE_H

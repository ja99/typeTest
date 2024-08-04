//
// Created by janis on 04.08.24.
//

#ifndef TYPETEST_EXAMPLEMESSAGE_H
#define TYPETEST_EXAMPLEMESSAGE_H

#include "../Field.h"
#include "../Message.h"

struct ExampleMessage: Message{
    Field<4> id = Field<4>(0, "ID", "The ID of the message");
    Field<3> length = Field<3>(0, "Length", "The length of the message");
    Field<8> data = Field<8>(0, "Data", "The data of the message");
    Field<1> parity = Field<1>(0, "Parity", "The parity of the message");

    explicit ExampleMessage(int id, int length, int data, int parity) {
        this->id = Field<4>(id, "ID", "The ID of the message");
        this->length = Field<3>(length, "Length", "The length of the message");
        this->data = Field<8>(data, "Data", "The data of the message");
        this->parity = Field<1>(parity, "Parity", "The parity of the message");

        this->fields.emplace_back(&this->id);
        this->fields.emplace_back(&this->length);
        this->fields.emplace_back(&this->data);
        this->fields.emplace_back(&this->parity);
    }

    explicit ExampleMessage (std::array<bool, 16> bits) {
        for (int i = 0; i < 4; ++i) {
            this->id.bits[i] = bits[i];
        }
        for (int i = 0; i < 3; ++i) {
            this->length.bits[i] = bits[i + 4];
        }
        for (int i = 0; i < 8; ++i) {
            this->data.bits[i] = bits[i + 7];
        }
        this->parity.bits[0] = bits[15];

        this->fields.emplace_back(&this->id);
        this->fields.emplace_back(&this->length);
        this->fields.emplace_back(&this->data);
        this->fields.emplace_back(&this->parity);
    }


};


#endif //TYPETEST_EXAMPLEMESSAGE_H

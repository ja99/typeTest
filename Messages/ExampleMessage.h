//
// Created by janis on 04.08.24.
//

#ifndef TYPETEST_EXAMPLEMESSAGE_H
#define TYPETEST_EXAMPLEMESSAGE_H

#include "../Field.h"
#include "../Message.h"

struct ExampleMessage: Message {
    Field<4> id = Field<4>(0, "ID", "The ID of the message");
    Field<3> length = Field<3>(0, "Length", "The length of the message");
    Field<8> data = Field<8>(0, "Data", "The data of the message");
    Field<1> parity = Field<1>(0, "Parity", "The parity of the message");

    ExampleMessage(int idValue, int lengthValue, int dataValue, int parityValue)
    : id(idValue), length(lengthValue), data(dataValue), parity(parityValue) {
        addField(&id);
        addField(&length);
        addField(&data);
        addField(&parity);
    }

};


#endif //TYPETEST_EXAMPLEMESSAGE_H

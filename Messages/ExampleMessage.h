//
// Created by janis on 04.08.24.
//

#ifndef TYPETEST_EXAMPLEMESSAGE_H
#define TYPETEST_EXAMPLEMESSAGE_H

#include "../Field.h"
#include "../Message.h"

struct ExampleMessage: public Message {
    Field<4> id = Field<4>(0, "ID", "The ID of the message");
    Field<3> length = Field<3>(5, "Length", "The length of the message");
    Field<8> data = Field<8>(8, "Data", "The data of the message");
    Field<1> parity = Field<1>(1, "Parity", "The parity of the message");


};


#endif //TYPETEST_EXAMPLEMESSAGE_H

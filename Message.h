//
// Created by janis on 04.08.24.
//

#ifndef TYPETEST_MESSAGE_H
#define TYPETEST_MESSAGE_H


#include <string>
#include <array>
#include <vector>
#include "Field.h"
#include <tuple>


template <std::size_t NumOfFields, std::size_t ArraySize>
struct Message {
    std::tuple<> fields;

    std::string toString(){
        std::string result;
        for (int i = 0; i < ArraySize; ++i) {
            result += fields[i].toString();
        }
        return result;
    }
};


#endif //TYPETEST_MESSAGE_H

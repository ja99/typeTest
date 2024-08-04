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



struct Message {
    std::vector<void*> fields;

    template <std::size_t ArraySize>
    void addField(Field<ArraySize>* field){
        fields.push_back(static_cast<void*>(field));
    }

    template <std::size_t ArraySize>
    std::string toString(){
        std::string result;
        for (auto field : fields) {
            result += ((Field<ArraySize>*)field)->toString();
        }
        return result;
    }
};


#endif //TYPETEST_MESSAGE_H

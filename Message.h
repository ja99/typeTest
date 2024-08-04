//
// Created by janis on 04.08.24.
//

#ifndef TYPETEST_MESSAGE_H
#define TYPETEST_MESSAGE_H


#include <vector>
#include <any>
#include <string>
#include <iostream>
#include "Field.h"

struct Message {
    std::vector<std::any> fields = {};

private:
    template<std::size_t N>
    std::string fieldToString(Field<N>* field) {
        return field->name + ": " + field->toString() + " (" + field->description + ")\n";
    }

public:
    std::string toString() {
        std::string result;

        for (auto field: fields) {
            if (field.type() == typeid(Field<1>*)) {
                result += fieldToString(std::any_cast<Field<1> *>(field));
            } else if (field.type() == typeid(Field<2>*)) {
                result += fieldToString(std::any_cast<Field<2> *>(field));
            } else if (field.type() == typeid(Field<3>*)) {
                result += fieldToString(std::any_cast<Field<3> *>(field));
            } else if (field.type() == typeid(Field<4>*)) {
                result += fieldToString(std::any_cast<Field<4> *>(field));
            } else if (field.type() == typeid(Field<5>*)) {
                result += fieldToString(std::any_cast<Field<5> *>(field));
            } else if (field.type() == typeid(Field<6>*)) {
                result += fieldToString(std::any_cast<Field<6> *>(field));
            } else if (field.type() == typeid(Field<7>*)) {
                result += fieldToString(std::any_cast<Field<7> *>(field));
            } else if (field.type() == typeid(Field<8>*)) {
                result += fieldToString(std::any_cast<Field<8> *>(field));
            } else {
                result += "Unknown Field Type\n";
            }
        }

        return result;
    };

};
#endif //TYPETEST_MESSAGE_H

//
// Created by janis on 04.08.24.
//

#ifndef TYPETEST_FIELD_H
#define TYPETEST_FIELD_H

#include <array>
#include <vector>

template<std::size_t BitsInValue>
std::array<bool,BitsInValue> getBits(int value){
    std::array<bool,BitsInValue> bits{};
    for (int i = 0; i < BitsInValue; ++i) {
        bits[i] = value & (1 << i);
    }
    return bits;
}


template<std::size_t ArraySize>
struct Field {
    std::string name = "No Name Given";
    std::string description = "No Description Given";
    std::array<bool, ArraySize> bits{};

    // Check if a bits Array specifies a number that is too large
    template<std::size_t BitsInValue>
    void sizeCheck(std::array<bool, BitsInValue>& otherBits) {
        for (int i = bits.size(); i < otherBits.size(); i++) {
            if (otherBits[i]) {
                throw std::invalid_argument("Number is too large");
            }
        }
    }

    std::string toString() {
        std::string result;
        for (int i = ArraySize - 1; i >= 0; --i) {
            result += bits[i] ? "1" : "0";
        }
        return result;
    }

    template<std::size_t BitsInValue>
    void setBits(std::array<bool, BitsInValue> newBits) {
        for (int i = 0; i < bits.size(); ++i) {
            bits[i] = newBits[i];
        }

    }

    explicit Field(int value) {
        auto newBits = getBits<sizeof(value)*8>(value);
        sizeCheck(newBits);
        setBits(newBits);
    }


    explicit Field(int value, const std::string& name, const std::string& description) {
        auto newBits = getBits<sizeof(value)*8>(value);
        sizeCheck(newBits);
        setBits(newBits);
        this->name = name;
        this->description = description;
    }

    //ToDo: fromBytestream
    //static Field fromBytestream([ByteStream& stream], int startBit, int endBit);

    //ToDo: insertIntoBytestream
    //void insertIntoBytestream([ByteStream& stream], int startBit, int endBit);
};


#endif //TYPETEST_FIELD_H

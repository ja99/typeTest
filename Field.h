//
// Created by janis on 04.08.24.
//

#ifndef TYPETEST_FIELD_H
#define TYPETEST_FIELD_H

#include <array>

template<std::size_t ArraySize>
std::array<bool,ArraySize> getBits(int value){
    std::array<bool,ArraySize> bits{};
    for (int i = 0; i < ArraySize; ++i) {
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
    void sizeCheck(std::array<bool, ArraySize>& otherBits) {
        for (int i = ArraySize - 1; i >= 0; --i) {
            if (otherBits[i]) {
                return;
            }
        }
        throw std::invalid_argument("Number is too large");
    }

    std::string toString() {
        std::string result;
        for (int i = ArraySize - 1; i >= 0; --i) {
            result += bits[i] ? "1" : "0";
        }
        return result;
    }

    explicit Field(int value) {
        auto newBits = getBits<ArraySize>(value);
        sizeCheck(newBits);
        bits = newBits;
    }

    explicit Field(const std::array<bool, ArraySize>& newBits) {
        sizeCheck(newBits);
        bits = newBits;
    }

    explicit Field(int value, const std::string& name, const std::string& description) {
        auto newBits = getBits<ArraySize>(value);
        sizeCheck(newBits);
        bits = newBits;
        this->name = name;
        this->description = description;
    }

    //ToDo: fromBytestream
    //static Field fromBytestream([ByteStream& stream], int startBit, int endBit);

    //ToDo: insertIntoBytestream
    //void insertIntoBytestream([ByteStream& stream], int startBit, int endBit);
};


#endif //TYPETEST_FIELD_H

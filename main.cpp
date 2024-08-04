#include <iostream>
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
};





int main() {
    Field<3> field(8);
    std::cout << field.toString() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

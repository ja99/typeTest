#include <iostream>
#include <array>
#include <vector>



void getBitsFromBuffer(const char * buffer, size_t startBit, size_t endBit, std::vector<bool> & bits) {
    if (startBit >= endBit) {
        throw std::invalid_argument("startBit must be smaller than endBit");
    }
    auto nBits = endBit+1 - startBit;
    if (nBits > bits.size()) {
        throw std::invalid_argument("nBits must be smaller than the size of the bits vector");
    }

    for (size_t i = 0; i < nBits; ++i) {
        size_t bitPosition = startBit + i;
        size_t byteIndex = bitPosition / 8; // Calculate the byte index in the buffer
        size_t bitIndex = bitPosition % 8;  // Calculate the bit index in the byte

        // Extract the bit using bitwise operations (big endian)
        bool bit = (buffer[byteIndex] >> (bitIndex)) & 1;

        // Store the bit in the bits vector
        bits[endBit - i] = bit;
    }
}


int main() {
    auto bits = std::vector<bool>(3);

    char * buffer = new char[2];
    buffer[0] = 0b00010110;

    //print buffer bits
    for (size_t i = 0; i < sizeof(buffer)*2; ++i) {
        std::cout << ((buffer[0] & (1 << i)) != 0);
    }
    std::cout << std::endl;

    getBitsFromBuffer(buffer, 0, 2, bits);

    for (auto bit : bits) {
        std::cout << bit;
    }


    delete[] buffer;
    return 0;
}

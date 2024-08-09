#include <iostream>
#include <array>
#include <vector>
#include <cstring>


void getBitsFromBuffer(
        const char * buffer,
        size_t startBit, //inclusive
        size_t endBit, //exclusive
        std::vector<bool> & bits)
        {
    if (startBit >= endBit) {
        throw std::invalid_argument("startBit must be smaller than endBit");
    }
    auto nBits = endBit - startBit;
    if (nBits > bits.size()) {
        throw std::invalid_argument("nBits must be smaller than the size of the bits vector");
    }
    if (endBit > 8 * sizeof(char) * strlen(buffer)) {
        throw std::invalid_argument("endBit must be smaller than the size of the buffer");
    }

    for (size_t i = 0; i < nBits; ++i) {
        size_t bitPosition = startBit + i;
        size_t byteIndex = bitPosition / 8; // Calculate the byte index in the buffer
        size_t bitIndex = bitPosition % 8;  // Calculate the bit index in the byte

        char byte = buffer[byteIndex];

        // reading least to most significant bit
//        bool bit = (byte >> (bitIndex)) & 1;

        //reading most to least significant bit
        bool bit = (byte >> (7 - bitIndex)) & 1;

        // Store the bit in the bits vector
        bits[i] = bit;
    }
}

void print_bits(char c) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
}

void print_char_buffer_bits(const char *buffer, size_t size) {
    for (size_t i = 0; i < size; i++) {
        print_bits(buffer[i]);
        printf(" "); // Add a space between characters for clarity
    }
    printf("\n");
}


int main() {
    auto bits = std::vector<bool>(10);
    int startBit = 5;
    int endBit = startBit + bits.size();

    char * buffer = new char[2];
    buffer[0] = 0b00000111;
    buffer[1] = 0b00001111;

    print_char_buffer_bits(buffer, 2);

    getBitsFromBuffer(buffer, startBit, endBit, bits);

    for (int i =0; i<startBit; i++) {
        std::cout << " ";
    }
    for (int i = 0; i<bits.size(); i++) {
        std::cout << bits[i];
        if (i % 8 == 7) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;


    delete[] buffer;
    return 0;
}

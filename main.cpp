#include <iostream>
#include <array>
#include <vector>
#include <cstring>
#include <valarray>

struct SafeBuffer {
    char *buffer;
    size_t size;

    SafeBuffer(size_t size) : size(size) {
        buffer = new char[size];
    }

    void setByte(size_t index, char value) {
        if (index >= size) {
            throw std::invalid_argument("index must be smaller than the size of the buffer");
        }
        buffer[index] = value;
    }

    void setBit(size_t bitPosition, bool value) {
        size_t byteIndex = bitPosition / 8; // Calculate the byte index in the buffer
        size_t bitIndex = bitPosition % 8;  // Calculate the bit index in the byte

        char byte = buffer[byteIndex];

        // Clear the bit at the bitIndex position
        byte &= ~(1 << (7 - bitIndex));

        // Set the bit at the bitIndex position
        byte |= (value << (7 - bitIndex));

        // Store the byte back in the buffer
        buffer[byteIndex] = byte;
    }

    void setFromSafeBitset(const std::vector<bool> &bitset, int startBit, int endBit) {
        auto nBits = endBit - startBit;

        for (size_t i = 0; i < nBits; ++i) {
            size_t bitPosition = startBit + i;
            size_t byteIndex = bitPosition / 8; // Calculate the byte index in the buffer
            size_t bitIndex = bitPosition % 8;  // Calculate the bit index in the byte

            char byte = buffer[byteIndex];

            // Clear the bit at the bitIndex position
            byte &= ~(1 << (7 - bitIndex));

            // Set the bit at the bitIndex position
            byte |= (bitset[i] << (7 - bitIndex));

            // Store the byte back in the buffer
            buffer[byteIndex] = byte;
        }
    }

    std::vector<bool> getBits(int startBit, int endBit) {
        std::vector<bool> bits(endBit - startBit);
        for (size_t i = 0; i < bits.size(); ++i) {
            size_t bitPosition = startBit + i;
            size_t byteIndex = bitPosition / 8; // Calculate the byte index in the buffer
            size_t bitIndex = bitPosition % 8;  // Calculate the bit index in the byte

            char byte = buffer[byteIndex];

            // reading most to least significant bit
            bool bit = (byte >> (7 - bitIndex)) & 1;

            // Store the bit in the bits vector
            bits[i] = bit;
        }
        return bits;
    }

    [[nodiscard]] std::string toString(){
        std::string s = "";

        for (size_t i = 0; i < this->size; i++) {
            for (int j = 7; j >= 0; j--) {
                s += ((buffer[i] >> j) & 1) ? '1' : '0'; // Append '1' or '0' as characters
            }
            s+=" "; // Add a space between characters for clarity
        }
        s+="\n";
        return s;
    }
};


void print_bool_vector(const std::vector<bool> &bits, int startBit = 0) {
    for (int i = 0; i < startBit; i++) {
        std::cout << " ";
    }
    for (int i = 0; i < bits.size(); i++) {
        std::cout << bits[i];
        if (i % 8 == 7) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}


int main() {
//    auto bits = std::vector<bool>(10);
//    int startBit = 5;
//    int endBit = startBit + bits.size();
//
//    auto receivedBuffer = SafeBuffer(2);
//    receivedBuffer.buffer[0] = 0b00000111;
//    receivedBuffer.buffer[1] = 0b00001111;
//
//    std::cout << receivedBuffer.toString() << std::endl;
//
//    auto receivedVec = receivedBuffer.getBits(startBit, endBit);
//
//    print_bool_vector(receivedVec, startBit);
//
//    auto bufferToSend = SafeBuffer(3);
//
//    bufferToSend.setFromSafeBitset(receivedVec, 0, receivedVec.size());
//
//    std::cout << bufferToSend.toString() << std::endl;
//
//
//    delete[] receivedBuffer;
//    delete[] bufferToSend;

    size_t nBits = 10;
    size_t nBytes = nBits / 8 + (nBits % 8 != 0);

    std::cout << "nBits: " << nBits << std::endl;
    std::cout << "nBytes: " << nBytes << std::endl;

    char * buffer = new char[nBytes];
    buffer[0] = 0b00000111;
    buffer[1] = 0b00001111;
    buffer[2] = 0b00000100;

    uint16_t val = 0;
    memccpy(&val, &buffer[1], 2, 2);

    std::cout << "val: " << val << std::endl;

    uint16_t masked = val & uint16_t(pow(2, nBits) - 1);

    std::cout << "masked: " << masked << std::endl;



    return 0;
}

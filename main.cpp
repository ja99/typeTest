#include <iostream>
#include <array>
#include <vector>
#include <cstring>

void safetyChecks(
        const char *buffer,
        size_t startBit, //inclusive
        size_t endBit, //exclusive,
        std::vector<bool> &bits
) {
    if (startBit >= endBit) {
        throw std::invalid_argument("startBit must be smaller than endBit");
    }
    auto nBits = endBit - startBit;
    if (nBits > bits.size()) {
        throw std::invalid_argument("nBits must be smaller than the size of the bits vector");
    }
    int lenBuffer= strlen(buffer)*sizeof(char)*8;
    if (endBit >lenBuffer) {
        throw std::invalid_argument("endBit must be smaller than the size of the buffer");
    }
}

void getBitsFromBuffer(
        const char *buffer,
        size_t startBit, //inclusive
        size_t endBit, //exclusive
        std::vector<bool> &bits) {

    safetyChecks(buffer, startBit, endBit, bits);

    auto nBits = endBit - startBit;

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

void insertBitsIntoBuffer(
        char *buffer,
        size_t startBit, //inclusive
        size_t endBit, //exclusive
        std::vector<bool> &bits) {

    safetyChecks(buffer, startBit, endBit, bits);

    auto nBits = endBit - startBit;

    for(size_t i = 0; i < nBits; ++i) {
        size_t bitPosition = startBit + i;
        size_t byteIndex = bitPosition / 8; // Calculate the byte index in the buffer
        size_t bitIndex = bitPosition % 8;  // Calculate the bit index in the byte

        char byte = buffer[byteIndex];

        // Clear the bit at the bitIndex position
        byte &= ~(1 << (7 - bitIndex));

        // Set the bit at the bitIndex position
        byte |= (bits[i] << (7 - bitIndex));

        // Store the byte back in the buffer
        buffer[byteIndex] = byte;
    }

}


void print_bits(char c) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
}

void print_char_buffer_bits(const char *buffer) {
    for (size_t i = 0; i < strlen(buffer); i++) {
        print_bits(buffer[i]);
        printf(" "); // Add a space between characters for clarity
    }
    printf("\n");
}

void print_bool_vector(const std::vector<bool> &bits, int startBit=0) {
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
    auto bits = std::vector<bool>(10);
    int startBit = 5;
    int endBit = startBit + bits.size();

    char *receivedBuffer = new char[2];
    receivedBuffer[0] = 0b00000111;
    receivedBuffer[1] = 0b00001111;

    print_char_buffer_bits(receivedBuffer);

    getBitsFromBuffer(receivedBuffer, startBit, endBit, bits);

    print_bool_vector(bits, startBit);


    char *bufferToSend = new char[3];
    bufferToSend[0] = 'A';            // Set first character to a non-zero value
    bufferToSend[1] = 'A';     // Still setting to zero
    bufferToSend[2] = 'A';     // Still setting to zero
    bufferToSend[3] = '\0';           // Explicitly add null terminator

    std::cout << strlen(bufferToSend) << std::endl;

    insertBitsIntoBuffer(bufferToSend, 0, bits.size(), bits);

    print_char_buffer_bits(bufferToSend);


    delete[] receivedBuffer;
    delete[] bufferToSend;
    return 0;
}

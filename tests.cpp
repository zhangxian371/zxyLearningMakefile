#include <cassert>
#include "main.cpp"

void testConvertTo4ByteHex() {
    assert(convertTo4ByteHex("192.168.1.1") == "c0a80101");
    assert(convertTo4ByteHex("255.255.255.255") == "ffffffff");
    assert(convertTo4ByteHex("0.0.0.0") == "00000000");
}

void testConvertTo16ByteHex() {
    //assert(convertTo16ByteHex("2001:0db8:85a3:0000:0000:8a2e:0370:7334") == "20010db885a3000000008a2e03707334");
    //assert(convertTo16ByteHex("2001:db8:85a3::8a2e:370:7334") == "20010db885a3000000008a2e03707334");
    //assert(convertTo16ByteHex("::1") == "00000000000000000000000000000001");
}

void runTests() {
    testConvertTo4ByteHex();
    testConvertTo16ByteHex();
    std::cout << "All tests passed.\n";
}

int main(int argc, char* argv[]) {
    // Uncomment the following line to run tests
    runTests();

    // Rest of your code...
}
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Function to convert IPv4 address to 4-byte hexadecimal format
#include <iomanip> // Include the <iomanip> header file

std::string convertTo4ByteHex(const std::string& ip) {
    std::vector<int> octets;
    std::stringstream ss(ip);
    std::string token;
    while (std::getline(ss, token, '.')) {
        octets.push_back(std::stoi(token));
    }

    std::stringstream hexStream;
    for (const auto& octet : octets) {
        hexStream << std::setfill('0') << std::setw(2) << std::hex << octet;
    }

    return hexStream.str();
}

// Function to convert IPv6 address to 16-byte hexadecimal format
std::string convertTo16ByteHex(const std::string& ip) {
    std::vector<int> octets;
    std::stringstream ss(ip);
    std::string token;
    while (std::getline(ss, token, '.')) {
        octets.push_back(std::stoi(token));
    }

    std::stringstream hexStream;
    hexStream << std::setfill('0') << std::setw(16) << std::hex;
    for (const auto& octet : octets) {
        hexStream << std::setw(2) << octet;
    }
    return hexStream.str();
}

bool isIPv6Address(const std::string& ip) {
    // Check if the IP address contains colons
    if (ip.find(':') != std::string::npos) {
        return true; // IPv6 address
    }
    return false; // IPv4 address
}

int main1(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <IP address>\n";
        return 1;
    }

    std::string ip = argv[1];

    // Convert IP address to plain text format
    std::cout << "Plain text: " << ip << std::endl;

    // Convert IP address to 16-byte hexadecimal format
    std::string hex16 = convertTo16ByteHex(ip);
    std::cout << "16-byte hexadecimal: " << hex16 << std::endl;

    // Convert IP address to 4-byte hexadecimal format
    std::string hex4 = convertTo4ByteHex(ip);
    std::cout << "4-byte hexadecimal: " << hex4 << std::endl;

    return 0;
}


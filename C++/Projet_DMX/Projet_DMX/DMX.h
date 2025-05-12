#pragma once
#include <array>

class DMX {
public:
    void sendTrame(const std::array<unsigned char, 512>& trame);
};
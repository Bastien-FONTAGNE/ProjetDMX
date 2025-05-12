#pragma once

#include "Equipment.h"

class ConfigurationTrame {
public:

    ConfigurationTrame(Equipment* equipment = nullptr, int dmxStartAddress = 0);
    Equipment* getEquipment() const;
    int getDmxStartAddress() const;
    void setEquipment(Equipment* equipment);
    void setDmxStartAddress(int address);
    bool isValid() const;

private:
    Equipment* equipment;
    int dmxStartAddress;
};


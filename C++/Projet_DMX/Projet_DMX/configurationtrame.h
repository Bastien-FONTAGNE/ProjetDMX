#pragma once
#ifndef CONFIGURATIONTRAME_H
#define CONFIGURATIONTRAME_H




class ConfigurationTrame {
private:
    Equipment* equipment;
    int dmxStartAddress;


public:
    // Constructeur
    ConfigurationTrame(Equipment* equip = nullptr, int startAddr = 1)
        : equipment(equip), dmxStartAddress(startAddr) {
        // Validation de l'adresse DMX (1-512)
        if (dmxStartAddress < 1 || dmxStartAddress > 512) {
            dmxStartAddress = 1; // Valeur par défaut si hors limites
        }
    }


    // Destructeur
    ~ConfigurationTrame() {
        // Note: Ne pas delete equipment ici car la ConfigurationTrame n'en est pas propriétaire
    }


    // Getters
    Equipment* getEquipment() const { return equipment; }
    int getDmxStartAddress() const { return dmxStartAddress; }


    // Setters
    void setEquipment(Equipment* equip) { equipment = equip; }

    void setDmxStartAddress(int addr) {
        if (addr >= 1 && addr <= 512) {
            dmxStartAddress = addr;
        }
        // Sinon, ignorer la valeur invalide
    }


    // Méthode pour vérifier si la configuration est valide
    bool isValid() const {
        return (equipment != nullptr) && (dmxStartAddress >= 1) && (dmxStartAddress <= 512);
    }
};


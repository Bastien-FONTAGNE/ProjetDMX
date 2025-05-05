#pragma once
#ifndef CONFIGURATIONTRAME_H
#define CONFIGURATIONTRAME_H
#include <QtSql/qsqldatabase.h>
#include "Equipment.h"




class ConfigurationTrame {
private:
    Equipement* equipement;
    int dmxStartAddress;


public:
    // Constructeur
    ConfigurationTrame(Equipement* equip = nullptr, int startAddr = 1)
        : equipement(equip), dmxStartAddress(startAddr) {
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
    Equipement* getEquipement() const { return equipement; }
    int getDmxStartAddress() const { return dmxStartAddress; }


    // Setters
    void setEquipement(Equipement* equip) { equipement = equip; }

    void setDmxStartAddress(int addr) {
        if (addr >= 1 && addr <= 512) {
            dmxStartAddress = addr;
        }
        // Sinon, ignorer la valeur invalide
    }


    // Méthode pour vérifier si la configuration est valide
    bool isValid() const {
        return (equipement != nullptr) && (dmxStartAddress >= 1) && (dmxStartAddress <= 512);
    }
};


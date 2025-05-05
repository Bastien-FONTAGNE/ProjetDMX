
#ifndef DMX_H
#define DMX_H

#include <cstdint> 
#include <vector>

class DMX {
public:
    // Constructeur
    DMX() {
        // Initialisation du port s�rie ou interface DMX
        initializeDmxInterface();
    }

    // Destructeur
    ~DMX() {
        // Nettoyage de l'interface DMX
        closeDmxInterface();
    }

    // Envoie une trame DMX de 512 canaux
    void sendTrame(const uint8_t trame[512]) {
        // V�rification de la trame
        if (!trame) {
            throw std::invalid_argument("La trame ne peut pas �tre nulle");
        }

        // Envoi du break et du start byte
        sendBreak();
        sendStartByte();

        // Envoi des donn�es DMX
        for (int i = 0; i < 512; ++i) {
            sendByte(trame[i]);
        }

        // Finalisation de la transmission
        finalizeTransmission();
    }



private:
    // M�thodes priv�es pour l'impl�mentation sp�cifique au mat�riel
    void initializeDmxInterface() {
        // Initialisation du port s�rie ou interface DMX sp�cifique
        // � adapter selon votre mat�riel
    }

    void closeDmxInterface() {
        // Fermeture propre de l'interface
    }

    void sendBreak() {
        // Envoi du break DMX (au moins 88�s � niveau bas)
        // Impl�mentation d�pendante du mat�riel
    }

    void sendStartByte() {
        // Envoi du start byte (0x00)
        sendByte(0x00);
    }

    void sendByte(uint8_t value) {
        // Envoi d'un octet sur l'interface DMX
        // Impl�mentation d�pendante du mat�riel
    }

    void finalizeTransmission() {
        // Finalisation de la transmission
        // Peut inclure une temporisation si n�cessaire
    }
};


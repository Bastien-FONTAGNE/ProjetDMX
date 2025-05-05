
#ifndef DMX_H
#define DMX_H

#include <cstdint> 
#include <vector>

class DMX {
public:
    // Constructeur
    DMX() {
        // Initialisation du port série ou interface DMX
        initializeDmxInterface();
    }

    // Destructeur
    ~DMX() {
        // Nettoyage de l'interface DMX
        closeDmxInterface();
    }

    // Envoie une trame DMX de 512 canaux
    void sendTrame(const uint8_t trame[512]) {
        // Vérification de la trame
        if (!trame) {
            throw std::invalid_argument("La trame ne peut pas être nulle");
        }

        // Envoi du break et du start byte
        sendBreak();
        sendStartByte();

        // Envoi des données DMX
        for (int i = 0; i < 512; ++i) {
            sendByte(trame[i]);
        }

        // Finalisation de la transmission
        finalizeTransmission();
    }



private:
    // Méthodes privées pour l'implémentation spécifique au matériel
    void initializeDmxInterface() {
        // Initialisation du port série ou interface DMX spécifique
        // À adapter selon votre matériel
    }

    void closeDmxInterface() {
        // Fermeture propre de l'interface
    }

    void sendBreak() {
        // Envoi du break DMX (au moins 88µs à niveau bas)
        // Implémentation dépendante du matériel
    }

    void sendStartByte() {
        // Envoi du start byte (0x00)
        sendByte(0x00);
    }

    void sendByte(uint8_t value) {
        // Envoi d'un octet sur l'interface DMX
        // Implémentation dépendante du matériel
    }

    void finalizeTransmission() {
        // Finalisation de la transmission
        // Peut inclure une temporisation si nécessaire
    }
};


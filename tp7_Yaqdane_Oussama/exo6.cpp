#include <iostream>
#include <fstream>
#include <string>

class Fichier {
private:
    std::fstream* flux;

public:
    Fichier() : flux(nullptr) {}

    ~Fichier() {
        if (flux) {
            flux->close();
            delete flux;
        }
    }

    void sauvegarder(const std::string& filename, const std::string& data) {
        if (flux) {
            flux->close();
            delete flux;
            flux = nullptr;
        }

        flux = new std::fstream(filename, std::ios::out);
        if (flux->is_open()) {
            *flux << data;
            flux->close();
        }

        delete flux;
        flux = nullptr;
    }

    std::string charger(const std::string& filename) {
        if (flux) {
            flux->close();
            delete flux;
            flux = nullptr;
        }

        flux = new std::fstream(filename, std::ios::in);
        std::string content;

        if (flux->is_open()) {
            std::string line;
            while (std::getline(*flux, line)) {
                content += line + "\n";
            }
            flux->close();
        }

        delete flux;
        flux = nullptr;

        return content;
    }
};

int main() {
    Fichier fichier;

    std::cout << "Sauvegarde des données..." << std::endl;
    fichier.sauvegarder("test.txt", "Bonjour, ceci est un test.");

    std::cout << "Lecture des données..." << std::endl;
    std::string contenu = fichier.charger("test.txt");

    std::cout << "Contenu du fichier :" << std::endl;
    std::cout << contenu;

    std::cout << "Mémoire du flux libérée." << std::endl;

    return 0;
}
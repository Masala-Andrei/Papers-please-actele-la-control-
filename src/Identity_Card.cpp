#include "../headers/Identity_Card.h"
#include "../headers/Game.h"
#include "random"
#include "fstream"

Identity_Card::Identity_Card(const std::string &name,
                             const std::string &sex,
                             const std::string &expiry_date,
                             const std::string &zone) : Document(name, expiry_date, sex),
                                                              zone(zone) {}

void Identity_Card::setZone(const std::string &_zone) {
    Identity_Card::zone = _zone;
}

void Identity_Card::alter() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> _chance(1, 3);
    int chance = _chance(gen);
    if (chance == 1) {
        alter_zone();
    }
}
void Identity_Card::alter_zone() {
    std::ifstream Z("Zones.txt");
    std::random_device rd;
    Game::MISTAKES++;
    std::mt19937 gen(rd());
    Z.seekg(0);
    int l, line;
    std::uniform_int_distribution<int> _z(0, 9);
    do {
        line = _z(gen);
        l = 0;
        while (l < line) {
            std::getline(Z, zone);
            l++;
        }
        std::getline(Z, zone);
    } while (zone == this->zone);
    setZone(zone);
}

std::ostream &operator<<(std::ostream &os, const Identity_Card &card) {
    os << "Identity Card" << std::endl
        << "Name: " << card.name << std::endl
        << "Sex: " << card.sex << std::endl
        << "Expiry date: " << card.expiry_date << std::endl
        << "Provenience zone: " << card.zone << std::endl;
    return os;
}


Identity_Card::~Identity_Card() = default;



#include "Entry_Permit.h"
#include "Game.h"
#include "random"
#include "fstream"
#include "algorithm"

Entry_Permit::Entry_Permit(const std::string &name, const std::string &expiryDate, const std::string &sex,
                           const std::string &reason)
        : Document(name, expiryDate, sex), reason(reason) {
    std::ifstream Z("Zones.txt");
    std::random_device rd;
    std::mt19937 gen(rd());
    Z.seekg(0);
    std::string zone;
    this->permission.emplace_back("Dobrogea");
    for (int i = 0; i < 2; i++) {
        do {
            zone = "";
            Z.seekg(0);
            int l, line;
            std::uniform_int_distribution<int> _z(0, 9);
            line = _z(gen);
            l = 0;
            while (l < line) {
                std::getline(Z, zone);
                l++;
            }
            std::getline(Z, zone);
        } while (find(this->permission.begin(), this->permission.end(), zone) != this->permission.end());
        this->permission.emplace_back(zone);
    }
    Z.close();
}

void Entry_Permit::alter() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> _chance(1, 13);
    int chance = _chance(gen);
    if (chance == 1) {
        alter_date();
    } else if (chance == 2 || chance == 4) {
        alter_permission();
    } else if (chance == 3) {
        alter_date();
        alter_permission();
    }
}

void Entry_Permit::alter_date() {
    std::random_device rd;
    std::mt19937 gen(rd());
    Game::MISTAKES++;
    std::uniform_int_distribution<int> _a(0, 4);
    std::uniform_int_distribution<int> _b(0, 4);
    int b = _b(gen);
    int a = _a(gen);
    if (a == 0 || b == 2) {
        std::uniform_int_distribution<int> wrong_day(0, Game::day - 1);
        Game::s_day = std::to_string(wrong_day(gen));
        std::uniform_int_distribution<int> wrong_month(1, Game::month - 1);
        Game::s_month = std::to_string(wrong_month(gen));
        std::uniform_int_distribution<int> wrong_year(2200, Game::year - 1);
        Game::s_year = std::to_string(wrong_year(gen));
    }
    if (a == 1 || b == 2) {
        std::uniform_int_distribution<int> wrong_month(1, Game::month - 1);
        Game::s_month = std::to_string(wrong_month(gen));
        std::uniform_int_distribution<int> wrong_year(2200, Game::year - 1);
        Game::s_year = std::to_string(wrong_year(gen));
    }
    if (a % 2 == 0 && a != 0 || b % 2 == 1) {
        std::uniform_int_distribution<int> wrong_year(2200, Game::year - 1);
        Game::s_year = std::to_string(wrong_year(gen));
    } ///Generate a wrong date
    Game::s_date = "";
    Game::s_date.append(Game::s_day);
    Game::s_date.append("-");
    Game::s_date.append(Game::s_month);
    Game::s_date.append("-");
    Game::s_date.append(Game::s_year);
    this->setExpiryDate(Game::s_date);
}

void Entry_Permit::alter_permission() {
    this->permission.erase(this->permission.begin());
    Game::MISTAKES++;
    std::ifstream Z("Zones.txt");
    std::random_device rd;
    std::mt19937 gen(rd());
    Z.seekg(0);
    std::string zone;
    do {
        int l, line;
        std::uniform_int_distribution<int> _z(0, 9);
        line = _z(gen);
        l = 0;
        while (l < line) {
            std::getline(Z, zone);
            l++;
        }
        std::getline(Z, zone);
    } while (zone == "Dobrogea");
    this->permission.emplace_back(zone);
    Z.close();
}

std::ostream &operator<<(std::ostream &os, const Entry_Permit &permit) {
    os << "Entry_Permit" << std::endl
       << "Name: " << permit.name << std::endl
       << "Expiry date: " << permit.expiry_date << std::endl
       << "Reason: " << permit.reason << std::endl
       << "Permissions: " << permit.permission[0] << " "
       << permit.permission[1] << " "
       << permit.permission[2] << " " << std::endl;
    return os;
}


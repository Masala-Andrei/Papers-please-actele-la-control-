#include "../headers/Passport.h"
#include "../headers/Game.h"
#include "thread"
#include "random"
#include "fstream"

Passport::Passport(const std::string &name,
                   const std::string &sex,
                   const std::string &code,
                   const std::string &zone,
                   const std::string &city,
                   const std::string &expiry_date) : Document(name, expiry_date, sex),
                                                     zone(zone),
                                                     code(code),
                                                     city(city) {}

[[maybe_unused]] Passport::Passport(const Passport &other) : Document(other.name, other.expiry_date, other.sex),
                                                             zone(other.zone),
                                                             code(other.code),
                                                             city(other.city) {}

Passport::~Passport() {
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl
              << std::endl << std::endl
              << std::endl << std::endl << std::endl << std::endl << std::endl
              << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << "Next Passport";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
}

std::ostream &operator<<(std::ostream &out, const Passport &passport) {
    out << "Passport" << std::endl
        << "Name: " << passport.name << std::endl
        << "Sex: " << passport.sex << std::endl
        << "Code: " << passport.code << std::endl
        << "Zone: " << passport.zone << std::endl
        << "City: " << passport.city << std::endl
        << "Expr_date.: " << passport.expiry_date << std::endl;
    return out;
}


Passport &Passport::operator=(const Passport &passport1) {
    this->name = passport1.name;
    this->sex = passport1.sex;
    this->expiry_date = passport1.expiry_date;
    this->zone = passport1.zone;
    this->code = passport1.code;
    this->city = passport1.city;
    return *this;
}

void Passport::alter() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> _chance(1, 13);

    int chance = _chance(gen);
    if (chance == 1) {
        alter_date();
    } else if (chance == 2) {
        alter_zone();
    } else if (chance == 3){
        alter_date();
        alter_zone();
    }
}

void Passport::generate_Passport(std::string &code, std::string &zone, std::string &city) {
    Passport::generate_city_zone(city, zone);
    Passport::generate_code(code);
}

void Passport::generate_code(std::string &code) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> _c(65, 90);
    int l;
    l = 0;
    while (l < 7) {
        char c = char(_c(gen));
        code.append(1, c);
        l++;
    }
}

void Passport::generate_city_zone(std::string &city, std::string &zone) {
    std::ifstream O("Cities.txt");
    std::ifstream Z("Zones.txt");
    std::random_device rd;
    std::mt19937 gen(rd());
    O.seekg(0);
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
    l = 0;
    while (l < line) {
        std::getline(O, city);
        std::getline(O, city);
        std::getline(O, city);
        l++;
    }
    std::uniform_int_distribution<int> _o(0, 2);
    int aux_city = _o(gen);
    l = 0;
    while (l < aux_city) {
        std::getline(O, city);
        l++;
    }
    std::getline(O, city);
    O.close();
    Z.close();
}

void Passport::alter_date() {
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
    std::cout<< "Merge Data";

}

void Passport::alter_zone() {
    std::ifstream Z("Zones.txt");
    std::random_device rd;
    Game::MISTAKES++;
    std::mt19937 gen(rd());
    Z.seekg(0);
    int l, line;
    std::string alt_zone;

    std::uniform_int_distribution<int> _z(0, 9);
    do {
        alt_zone = "";
        line = _z(gen);
        l = 0;
        while (l < line) {
            std::getline(Z, alt_zone);
            l++;
        }
        std::getline(Z, alt_zone);
    } while (alt_zone == this->zone);
    setZone(alt_zone);
}

void Passport::setZone(const std::string &zone_) {
    this->zone = zone_;
}

const std::string &Passport::getZone() const {
    return zone;
}

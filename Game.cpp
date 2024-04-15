#include "Game.h"
#include <iostream>
#include <ostream>
#include <random>


#include "Immigrant.h"
#include "Statistics.h"
#include "Passport.h"
#include "Entry_Permit.h"
#include "Identity_Card.h"

int Game::MISTAKES;
std::string Game::s_day;
std::string Game::s_month;
std::string Game::s_year;
std::string Game::s_date;
int Game::day;
int Game::month;
int Game::year;

void Game::game() {
    std::string input;
    std::cout << "Difficulty"
              << std::endl
              << "1. Easy"
              << std::endl
              << "2. Medium"
              << std::endl
              << "3. Hard"
                << std::endl;
    getline(std::cin, input);
    while (!(input != "1" || input != "2" || input != "3"))
        getline(std::cin, input);
    if (input == "1")
        game1();
    if (input == "2")
        game2();
    if (input == "3")
        game3();
}

void Game::game1() {
    std::random_device rd;
    std::mt19937 gen(rd());


    std::string Current_Date = "1-4-2231";
    std::cout << "Current Date: " << Current_Date << std::endl << std::endl;

    Statistics stat(0, 0, 0);

    while (true) {
        MISTAKES = 0;
        std::uniform_int_distribution<int> _g(50, 140);
        std::uniform_int_distribution<int> _i(150, 215);
        Immigrant person(_i(gen), _g(gen));
        operator<<(std::cout, person);

        std::string Name, City, Zone, Sex, Code, Expiry_date;

        Document::generate_name(Name, Sex);

        Passport::generate_Passport(Code, Zone, City);


        day = stoi(Current_Date.substr(0, 1));
        month = stoi(Current_Date.substr(2, 1));
        year = stoi(Current_Date.substr(4, 4));
        std::cout << std::endl;

        std::uniform_int_distribution<int> _day(day, 30);
        std::uniform_int_distribution<int> _month(month, 12);
        std::uniform_int_distribution<int> _year(year, 2240);

        s_day = std::to_string(_day(gen));
        s_month = std::to_string(_month(gen));
        s_year = std::to_string(_year(gen));

        s_date = "";
        s_date.append(s_day);
        s_date.append("-");
        s_date.append(s_month);
        s_date.append("-");
        s_date.append(s_year);

        Document *passport = new Passport(Name, Sex, Code, Zone, City, s_date);
        Passport *p1;
        p1 = dynamic_cast<Passport *>(passport);
        p1->alter();
        operator<<(std::cout, *p1);

        std::string input;
        std::cout << "Write 'Accept' to accept, 'Deny' to deny or 'Exit' to exit the game"
                  << std::endl;
        getline(std::cin, input);
        while (!(input != "Exit" || input != "Accept" || input != "Deny"))
            getline(std::cin, input);

        if (input == "Exit")
            break;
        if (input == "Accept") {
            if (MISTAKES == 0) {
                std::cout << "Correct!" << std::endl;
                stat.correct();

            } else {
                std::cout << "Wrong!" << std::endl;
                stat.wrong();
            }
        } else if (input == "Deny") {
            if (MISTAKES > 0) {
                std::cout << "Correct!" << std::endl;
                stat.correct();

            } else {
                std::cout << "Wrong!" << std::endl;
                stat.wrong();

            }
        }
        std::cout << "Write 'Enter' to continue or 'Exit' to leave" << std::endl;
        getline(std::cin, input);
        while (!(input != "Enter" || input != "Exit"))
            getline(std::cin, input);

        if (input == "Exit")
            break;
        delete p1;
    }
    operator<<(std::cout, stat);
}

void Game::game2() {
    std::random_device rd;
    std::mt19937 gen(rd()); ///Set a generator


    std::string Current_Date = "1-4-2231";
    std::cout << "Current Date: " << Current_Date << std::endl << std::endl;

    Statistics stat(0, 0, 0);

    while (true) {
        MISTAKES = 0;
        std::uniform_int_distribution<int> _g(50, 140);
        std::uniform_int_distribution<int> _i(150, 215);
        Immigrant person(_i(gen), _g(gen));
        operator<<(std::cout, person);

        std::string Name, City, Zone, Sex, Code, Expiry_date;

        Document::generate_name(Name, Sex);

        Passport::generate_Passport(Code, Zone, City);

        day = stoi(Current_Date.substr(0, 1));
        month = stoi(Current_Date.substr(2, 1));
        year = stoi(Current_Date.substr(4, 4));
        std::cout << std::endl;

        std::uniform_int_distribution<int> _day(day, 30);
        std::uniform_int_distribution<int> _month(month, 12);
        std::uniform_int_distribution<int> _year(year, 2240);

        s_day = std::to_string(_day(gen));
        s_month = std::to_string(_month(gen));
        s_year = std::to_string(_year(gen));

        s_date = "";
        s_date.append(s_day);
        s_date.append("-");
        s_date.append(s_month);
        s_date.append("-");
        s_date.append(s_year);


        std::string aux_s_date = s_date;
        Document *passport = new Passport(Name, Sex, Code, Zone, City, s_date);
        Passport *p1;
        p1 = dynamic_cast<Passport *>(passport);
        p1->alter();
        operator<<(std::cout, *p1);

        std::cout << std::endl << std::endl;

        s_date = aux_s_date;
        Document *entry_permit = new Entry_Permit(Name, s_date, Sex, "Travel");
        Entry_Permit *p2;
        p2 = dynamic_cast<Entry_Permit *>(entry_permit);
        p2->alter();
        operator<<(std::cout, *p2);

        std::string input;
        std::cout << "Write 'Accept' to accept, 'Deny' to deny or 'Exit' to exit the game"
                  << std::endl;
        getline(std::cin, input);
        while (!(input != "Exit" || input != "Accept" || input != "Deny"))
            getline(std::cin, input);

        if (input == "Exit")
            break;
        if (input == "Accept") {
            if (MISTAKES == 0) {
                std::cout << "Correct!" << std::endl;
                stat.correct();

            } else {
                std::cout << "Wrong!" << std::endl;
                stat.wrong();
            }
        } else if (input == "Deny") {
            if (MISTAKES > 0) {
                std::cout << "Correct!" << std::endl;
                stat.correct();

            } else {
                std::cout << "Wrong!" << std::endl;
                stat.wrong();

            }
        }
        std::cout << "Write 'Enter' to continue or 'Exit' to leave" << std::endl;
        getline(std::cin, input);
        while (!(input != "Enter" || input != "Exit"))
            getline(std::cin, input);
        delete p1;
        delete p2;
        if (input == "Exit")
            break;
    }
    operator<<(std::cout, stat);
}

void Game::game3() {
    std::random_device rd;
    std::mt19937 gen(rd()); ///Set a generator


    std::string Current_Date = "1-4-2231";
    std::cout << "Current Date: " << Current_Date << std::endl << std::endl;

    Statistics stat(0, 0, 0);

    while (true) {
        MISTAKES = 0;
        std::uniform_int_distribution<int> _g(50, 140);
        std::uniform_int_distribution<int> _i(150, 215);
        Immigrant person(_i(gen), _g(gen));
        operator<<(std::cout, person);

        std::string Name, City, Zone, Sex, Code, Expiry_date;

        Document::generate_name(Name, Sex);

        Passport::generate_Passport(Code, Zone, City);


        day = stoi(Current_Date.substr(0, 1));
        month = stoi(Current_Date.substr(2, 1));
        year = stoi(Current_Date.substr(4, 4));
        std::cout << std::endl;

        std::uniform_int_distribution<int> _day(day, 30);
        std::uniform_int_distribution<int> _month(month, 12);
        std::uniform_int_distribution<int> _year(year, 2240);

        s_day = std::to_string(_day(gen));
        s_month = std::to_string(_month(gen));
        s_year = std::to_string(_year(gen));

        s_date = "";
        s_date.append(s_day);
        s_date.append("-");
        s_date.append(s_month);
        s_date.append("-");
        s_date.append(s_year);

        std::string aux_s_date, aux_s_day, aux_s_month, aux_s_year;
        aux_s_date = s_date;
        aux_s_day = s_day;
        aux_s_month = s_month;
        aux_s_year = s_year;
        Document *passport = new Passport(Name, Sex, Code, Zone, City, s_date);
        Passport *p1;
        p1 = dynamic_cast<Passport *>(passport);
        std::string aux_zone = p1->getZone();
        p1->alter();
        operator<<(std::cout, *p1);

        std::cout << std::endl << std::endl;
        s_date = aux_s_date;
        s_day = aux_s_day;
        s_month = aux_s_month;
        s_year = aux_s_year;
        Document *entry_permit = new Entry_Permit(Name, s_date, Sex, "Travel");
        Entry_Permit *p2;
        p2 = dynamic_cast<Entry_Permit *>(entry_permit);
        p2->alter();
        operator<<(std::cout, *p2);

        s_date = aux_s_date;
        s_day = aux_s_day;
        s_month = aux_s_month;
        s_year = aux_s_year;

        if (aux_zone == "Dobrogea") {
            Document *identity_card = new Identity_Card(Name, Sex, s_date, aux_zone);
            Identity_Card *p3;
            p3 = dynamic_cast<Identity_Card *>(identity_card);

            p3->alter();
            std::cout << std::endl << std::endl;
            operator<<(std::cout, *p3);
        }

        std::string input;
        std::cout << "Write 'Accept' to accept, 'Deny' to deny or 'Exit' to exit the game"
                  << std::endl;
        getline(std::cin, input);
        while (!(input != "Exit" || input != "Accept" || input != "Deny"))
            getline(std::cin, input);

        if (input == "Exit")
            break;
        if (input == "Accept") {
            if (MISTAKES == 0) {
                std::cout << "Correct!" << std::endl;
                stat.correct();

            } else {
                std::cout << "Wrong!" << std::endl;
                stat.wrong();
            }
        } else if (input == "Deny") {
            if (MISTAKES > 0) {
                std::cout << "Correct!" << std::endl;
                stat.correct();

            } else {
                std::cout << "Wrong!" << std::endl;
                stat.wrong();

            }
        }
        std::cout << "Write 'Enter' to continue or 'Exit' to leave" << std::endl;
        getline(std::cin, input);
        while (!(input != "Enter" || input != "Exit"))
            getline(std::cin, input);
        delete p1;
        delete p2;
        if (input == "Exit")
            break;
    }
    operator<<(std::cout, stat);

}

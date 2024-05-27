#include "../headers/Game.h"
#include <iostream>
#include <ostream>
#include <random>

#include "../headers/DocumentFactory.h"
#include "../headers/Immigrant.h"
#include "../headers/Statistics.h"
#include "../headers/Passport.h"
#include "../headers/Entry_Permit.h"
#include "../headers/Identity_Card.h"

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
    int choice;
    while (true) {
        try {
            system("color 07");
            std::cout << "Difficulty" << std::endl
                      << "1. Easy" << std::endl
                      << "2. Medium" << std::endl
                      << "3. Hard" << std::endl;
            std::getline(std::cin, input);
            choice = std::stoi(input);
            switch (choice) {
                case 1:
                    game1();
                    return;
                case 2:
                    game2();
                    return;
                case 3:
                    game3();
                    return;
                default:
                    throw choice;
            }
        } catch (const std::invalid_argument &e) {
            std::cout << "Invalid input. Please enter a number.\n";
        } catch (const std::out_of_range &e) {
            std::cout << "Number out of range. Please enter a valid number.\n";
        } catch (int choice) {
            std::cout << "Invalid choice. Please select a number between 1 and 3.\n";
        } catch (...) {
            std::cout << "An unexpected error occurred.\n";
        }
    }
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

        Document *document = DocumentFactory::createDocument("Passport", Name, Sex, s_date, Code, Zone, City);
        Passport *passport = dynamic_cast<Passport *>(document);
        if (passport) {
            passport->alter();
            operator<<(std::cout, *passport);
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

        if (input == "Exit")
            break;
        delete passport;
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
        Document *document = DocumentFactory::createDocument("Passport", Name, Sex, s_date, Code, Zone, City);
        Passport *passport = dynamic_cast<Passport *>(document);
        if (passport) {
            passport->alter();
            operator<<(std::cout, *passport);
        }

        std::cout << std::endl << std::endl;

        s_date = aux_s_date;
        Document *document1 = DocumentFactory::createDocument("Entry_Permit", Name, Sex, s_date, Code, Zone, City);
        Entry_Permit *entryPermit = dynamic_cast<Entry_Permit *>(document1);
        if (entryPermit) {
            entryPermit->alter();
            operator<<(std::cout, *entryPermit);
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
        delete passport;
        delete entryPermit;
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

        Document *document = DocumentFactory::createDocument("Passport", Name, Sex, s_date, Code, Zone, City);
        Passport *passport = dynamic_cast<Passport *>(document);
        std::string aux_zone = passport->getZone();
        if (passport) {
            passport->alter();
            operator<<(std::cout, *passport);
        }
        std::cout << std::endl << std::endl;
        s_date = aux_s_date;
        s_day = aux_s_day;
        s_month = aux_s_month;
        s_year = aux_s_year;
        Document *document1 = DocumentFactory::createDocument("Entry_Permit", Name, Sex, s_date, Code, Zone, City);
        Entry_Permit *entryPermit = dynamic_cast<Entry_Permit *>(document1);
        if (entryPermit) {
            entryPermit->alter();
            operator<<(std::cout, *entryPermit);
        }

        s_date = aux_s_date;
        s_day = aux_s_day;
        s_month = aux_s_month;
        s_year = aux_s_year;

        Document *document2 = DocumentFactory::createDocument("Identity_Card", Name, Sex, s_date, Code, Zone, City);
        Identity_Card *identityCard = dynamic_cast<Identity_Card *>(document2);
        if (identityCard) {
            if (aux_zone == "Dobrogea") {
                identityCard->alter();
                std::cout << "\n" << "\n";
                operator<<(std::cout, *identityCard);
            }
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
        delete passport;
        delete entryPermit;
        delete identityCard;
        if (input == "Exit")
            break;
    }
    operator<<(std::cout, stat);

}

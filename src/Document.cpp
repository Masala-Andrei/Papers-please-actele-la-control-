#include "../headers/Document.h"
#include "fstream"
#include "random"

Document::~Document() = default;

Document::Document(const std::string &name, const std::string &expiry_date, const std::string &sex) : name(name),
                                                                                                      expiry_date(expiry_date),
                                                                                                      sex(sex) {}


void Document::generate_name(std::string &name, std::string &sex) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::ifstream N("Names.txt");
    int l, line;
    N.seekg(0);
    std::uniform_int_distribution<int> _n(0, 248);
    line = _n(gen);
    l = 0;
    while (l < line) {
        std::getline(N, name);
        l++;
    }
    std::getline(N, name);
    sex.assign(name.substr(name.length() - 1, 1));
    name.erase(name.length() - 2, name.length());
    N.close();
}

void Document::setExpiryDate(const std::string &expiryDate) {
    expiry_date = expiryDate;
}





#include "iostream"
#include "../headers/Immigrant.h"

Immigrant::Immigrant(int height, int weight) : height(height),weight(weight){}

std::ostream &operator<<(std::ostream &out, const Immigrant &immigrant) {
    out << "Data about person"<< std::endl << "Height:" << immigrant.height << std::endl << "Weight:" << immigrant.weight << std::endl;
    return out;
}

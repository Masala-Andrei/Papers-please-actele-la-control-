#ifndef UNTITLED_IMMIGRANT_H
#define UNTITLED_IMMIGRANT_H

#include "iostream"

class Immigrant
{
private:
    int height, weight;

public:
    Immigrant(int height,int weight);

    ~Immigrant() = default;

    friend std::ostream &operator<<(std::ostream &out, const Immigrant &immigrant);
};

#endif //UNTITLED_IMMIGRANT_H

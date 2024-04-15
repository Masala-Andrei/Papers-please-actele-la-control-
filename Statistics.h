#ifndef UNTITLED_STATISTICS_H
#define UNTITLED_STATISTICS_H

#include "iostream"

class Statistics {
private:
    int correct_answers, wrong_answers, credit;

public:
    Statistics(int correct_answers, int wrong_answers, int credit);

    void correct();

    void wrong();

    friend std::ostream &operator<<(std::ostream &out, const Statistics &stat);

};


#endif //UNTITLED_STATISTICS_H

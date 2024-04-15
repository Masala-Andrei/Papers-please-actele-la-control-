#include "Statistics.h"
#include "iostream"

Statistics::Statistics(int correct_answers, int wrong_answers, int credit) : correct_answers(correct_answers), wrong_answers(wrong_answers), credit(credit) {}

void Statistics::correct() {
    this->correct_answers++;
    this->credit = this->credit + 5;
}

void Statistics::wrong() {
    this->wrong_answers--;
    this->credit = this->credit - 7;
}

std::ostream &operator<<(std::ostream &out, const Statistics &stat) {
    out << "Round Statistics:" << std::endl
        << "Mistakes: " << stat.wrong_answers << std::endl
        << "Correct Admissions/Denials: " << stat.correct_answers << std::endl
        << "Score: " << stat.credit << std::endl;
    return out;
}

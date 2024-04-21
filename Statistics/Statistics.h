
#ifndef STATISTICS_STATISTICS_H
#define STATISTICS_STATISTICS_H
#include <iostream>
#include <string>
//#include "Voter.h"
#include <fstream>
#include "nlohmann/json.hpp"
using namespace std;
using json= nlohmann::json;


class Statistics{
    static Statistics* Instance;
    Statistics();
public:
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    static Statistics* getInstance();
void isEligible(string DOB);
void get_gender_info();
};

#endif //STATISTICS_STATISTICS_H

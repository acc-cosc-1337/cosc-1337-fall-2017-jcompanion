#ifndef PAYROLL_H_INCLUDED
#define PAYROLL_H_INCLUDED
#include <string>
using namespace std;

const int EMPLOYEES = 3;
const double MAX_HOURS = 40.0;
const double MULTIPLIER = 1.5;
const double FIT = .15;
const double FICA_SS = .062;
const double FICA_MED = .0145;
bool isValidSalaryAmount(int a_sal);
bool isValidPayRate(int hours);
bool isValidHoursWorked(int pay_rate);

#endif // PAYROLL_H_INCLUDED

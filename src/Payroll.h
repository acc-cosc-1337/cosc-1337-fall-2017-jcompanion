#ifndef _PAYROLL_H
#define _PAYROLL_H

bool isValidSalaryAmount(int a_sal);
bool isValidHourlyAmount(int hours);
bool isValidAmountWorked(int pay_rate);
double getGrossPay(double hours, double ot_hours, double pay_rate);


#endif

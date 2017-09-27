#include "Payroll.h"
#include "stdafx.h"



bool isValidSalaryAmount(int a_sal)

{
	return a_sal >= 20000 && a_sal <= 100000;
}

bool isValidPayRate(int pay_rate)
{
	return pay_rate >= 0 && pay_rate <= 60;

}
bool isValidHoursWorked(int hours)
{

	return hours >= 0 && hours <= 50;
}

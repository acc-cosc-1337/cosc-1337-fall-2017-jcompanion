#include "Payroll.h"
#include <math.h>

#include "Payroll.h"


bool isValidSalaryAmount(int a_sal)

{
	return a_sal >= 20000 && a_sal <= 100000;
}

bool isValidHourlyAmount(int pay_rate)
{
	return pay_rate >= 0 && pay_rate <= 60;

}
bool isValidAmountWorked(int hours)
{

	return hours >= 0 && hours <= 50;
}


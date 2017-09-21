#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Payroll.h"


using namespace std;
const double MAX_HOURS = 40.0;
const double MULTIPLIER = 1.5;
const double FIT = .15;
const double FICA_SS = .062;
const double FICA_MED = .0145;

int _main

{
	

		enum selection { hourly = 1, salary = 2 };
		string name;
		double hours = 0.0;
		double pay_rate = 0.0;
		double net_pay = 0.0;
		double a_sal = 0.0;
		double fit = 0.0;
		double fica_ss = 0.0;
		double fica_med = 0.0;
		double gross_pay = 0.0;
		double ot_pay = 0.0;
		double sal_net = 0.0;
		double sal_fit = 0.0;
		double sal_ficass = 0.0;
		double sal_ficamed = 0.0;
		int selection;
		stringstream ss;


		for (int i = 0; i < 3; i++)
		{


			cout << "Enter your name: ";
			cin >> name;
			cout << "Are you hourly (1) or salary (2): ";
			cin >> selection;

			if (selection == hourly)
			{
				cout << "Enter pay rate: ";
				cin >> pay_rate;
				cout << "Enter hours worked:  ";
				cin >> hours;
				while (!(isValidHourlyAmount(pay_rate)));
				while (!(isValidAmountWorked(hours)));



				if (hours <= MAX_HOURS)
				{
					gross_pay = hours * pay_rate;
					fica_ss = gross_pay * FICA_SS;
					fica_med = gross_pay * FICA_MED;
				}
				else
				{
					ot_pay = (hours - MAX_HOURS) * MULTIPLIER * pay_rate;
					gross_pay = MAX_HOURS * pay_rate + ot_pay;
					fica_ss = gross_pay * FICA_SS;
					fica_med = gross_pay * FICA_MED;
				}
				fit = gross_pay * FIT;

				net_pay = (gross_pay + ot_pay) - (fit + fica_med + fica_ss);


				/*cout << "Thanks " << name << ", the number of hours you have worked is: " << hours << endl;
				cout << "Pay rate: " << pay_rate << endl;
				cout << "Gross pay: " << gross_pay << endl;
				cout << "OT pay: " << ot_pay << endl;
				cout << "Fedaral Income Tax: " << fit << endl;
				cout << "FICA SS tax: " << fica_ss << endl;
				cout << "FICA medicare: " << fica_med << endl;
				cout << "Net Pay: " << net_pay << endl;
				*/
			}

			if (selection == salary)
			{
				
				cout << "What did you make this year: ";
				cin >> a_sal;
				while (!(isValidSalaryAmount(a_sal)));
				sal_net = a_sal - (a_sal * (FICA_MED + FICA_SS + FIT));
				sal_fit = a_sal * FIT;
				sal_ficass = a_sal * FICA_SS;
				sal_ficamed = a_sal * FICA_MED;
				/*cout << "Thanks " << name << endl;
				cout << "Annual income: " << sal_net << endl;
				cout << "Fedaral Income tax: " << sal_fit << endl;
				cout << "FICA SS tax: " << sal_ficass << endl;
				cout << "FICA medicare: " << sal_ficamed << endl;
				cout << "Net pay: " << sal_net << endl;
				*/

			}

			ss << setw(10) << name << setw(10) << hours << setw(10) << a_sal << setw(10) << pay_rate << setw(10) << fit << setw(10) << fica_ss << setw(10) << fica_med << setw(10) << gross_pay << setw(10) << sal_fit << setw(10) << sal_ficass << setw(10) << sal_ficamed << setw(10) << sal_net << setw(10) << net_pay << endl;
		}
		cout << setw(10) << "Name" << setw(10) << "Hours" << setw(10) << "Salary" << setw(10) << "PayRate" << setw(10) << "FITHour" << setw(10) << "FICAHour" << setw(10) << "MedicareHour" << setw(10) << "HourlyPay" << setw(10) << "FITSalary" << setw(10) << "FICASalary" << setw(10) << "MedicareSalary" << setw(10) << "NetPaySalary" << setw(10) << "NetPayHour" << endl;
		cout << ss.str();
	

	return 0;
}

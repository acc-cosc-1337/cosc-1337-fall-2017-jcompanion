#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Payroll.h"


using namespace std;


int _main()

{
	

		enum selection { hourly = 1, salary = 2 };
		string name[EMPLOYEES];
		double hours[EMPLOYEES] = { 0 };
		double pay_rate[EMPLOYEES] = { 0 };
		double net_pay[EMPLOYEES] = { 0 };
		double a_sal[EMPLOYEES] = { 0 };
		double fit[EMPLOYEES] = { 0 };
		double fica_ss[EMPLOYEES] = { 0 };
		double fica_med[EMPLOYEES] = { 0 };
		double gross_pay[EMPLOYEES] = { 0 };
		double ot_pay[EMPLOYEES] = { 0 };
		double sal_net[EMPLOYEES] = { 0 };
		double sal_fit[EMPLOYEES] = { 0 };
		double sal_ficass[EMPLOYEES] = { 0 };
		double sal_ficamed[EMPLOYEES] = { 0 };
		int selection;
		stringstream ss;



		for (int i = 0; i < EMPLOYEES; i++)
		{


			cout << "Enter your name: ";
			cin >> name[i];
			cout << "Are you hourly (1) or salary (2): ";
			cin >> selection;

			if (selection == hourly)
			{
				cout << "Enter pay rate: ";
				cin >> pay_rate[i];
				while (!(isValidPayRate(pay_rate[i])))
				{
					cout << "Please enter valid hours worked..." << endl;
					cout << "Enter pay rate: ";
					cin >> pay_rate[i];
				}
				cout << "Enter hours worked:  ";
				cin >> hours[i];
				while (!(isValidHoursWorked(hours[i])))
				{
					cout << "Please enter a valid hourly wage..." << endl;
					cout << "Enter hours worked:  ";
					cin >> hours[i];
				}




				if (hours[i] <= MAX_HOURS)
				{
					gross_pay[i] = hours[i] * pay_rate[i];
					fica_ss[i] = gross_pay[i] * FICA_SS;
					fica_med[i] = gross_pay[i] * FICA_MED;
				}
				else
				{
					ot_pay[i] = (hours[i] - MAX_HOURS) * MULTIPLIER * pay_rate[i];
					gross_pay[i] = MAX_HOURS * pay_rate[i] + ot_pay[i];
					fica_ss[i] = gross_pay[i] * FICA_SS;
					fica_med[i] = gross_pay[i] * FICA_MED;
				}
				fit[i] = gross_pay[i] * FIT;

				net_pay[i] = (gross_pay[i] + ot_pay[i]) - (fit[i] + fica_med[i] + fica_ss[i]);


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
				cin >> a_sal[i];
				while (!(isValidSalaryAmount(a_sal[i])))
				{
					cout << "Please enter a valid salary..." << endl;
					cout << "What did you make this year: ";
					cin >> a_sal[i];
				}

					sal_net[i] = a_sal[i] - (a_sal[i] * (FICA_MED + FICA_SS + FIT));
					sal_fit[i] = a_sal[i] * FIT;
					sal_ficass[i] = a_sal[i] * FICA_SS;
					sal_ficamed[i] = a_sal[i] * FICA_MED;
					/*cout << "Thanks " << name << endl;
					cout << "Annual income: " << sal_net << endl;
					cout << "Fedaral Income tax: " << sal_fit << endl;
					cout << "FICA SS tax: " << sal_ficass << endl;
					cout << "FICA medicare: " << sal_ficamed << endl;
					cout << "Net pay: " << sal_net << endl;
					*/
				
			}

			ss << setw(10) << name[i] << setw(10) << hours[i] << setw(10) << a_sal[i] << setw(10) << pay_rate[i] << setw(10) << fit[i] << setw(10) << fica_ss[i] << setw(10) << fica_med[i] << setw(10) << gross_pay[i] << setw(10) << sal_fit[i] << setw(10) << sal_ficass[i] << setw(10) << sal_ficamed[i] << setw(10) << sal_net[i] << setw(10) << net_pay[i] << endl;
		}
		cout << setw(10) << "Name" << setw(10) << "Hours" << setw(10) << "Salary" << setw(10) << "PayRate" << setw(10) << "FITHour" << setw(10) << "FICAHour" << setw(10) << "MedicareHour" << setw(10) << "HourlyPay" << setw(10) << "FITSalary" << setw(10) << "FICASalary" << setw(10) << "MedicareSalary" << setw(10) << "NetPaySalary" << setw(10) << "NetPayHour" << endl;
		cout << ss.str();
	

	return 0;
}

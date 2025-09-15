
//Assignment 4 - Pay Report
//Jordan Klotz
//10/13/2025

#include <iostream>
#include <conio.h>

using namespace std;

struct Employee
{
	int ID;
	string FirstName;
	string LastName;
	float HoursWorked;
	float HourlyRate;
};

float CalculateWeeklyPay(Employee* pE)
{
	return pE->HoursWorked * pE->HourlyRate;
}

void PrintWeeklyPay(Employee* employees, int size)
{
	float totalPay = 0;
	float weeklyPay = 0;

	cout << "Pay Report\n";
	cout << "----------\n";

	for (int i = 0; i < size; i++)
	{
		float weeklyPay = CalculateWeeklyPay(&employees[i]);

		cout << employees[i].ID << ". " << employees[i].FirstName << " " << employees[i].LastName << ": $" << weeklyPay << "\n";
		totalPay += weeklyPay;

	}
	cout << "\n";
	cout << "Total Pay: $" << totalPay;

}

Employee* GetEmployeeInfo(int i)
{
	Employee* pEmployee = new Employee;
	cout << "Enter the ID for Employee " << i <<": ";
	cin >> pEmployee->ID;
	cout << "Enter the First Name for Employee " << i << ": ";
	cin >> pEmployee->FirstName;
	cout << "Enter the Last Name for Employee " << i << ": ";
	cin >> pEmployee->LastName;
	cout << "Enter the Hours Worked for Employee " << i << ": ";
	cin >> pEmployee->HoursWorked;
	cout << "Enter the Hourly Rate for Employee " << i << ": ";
	cin >> pEmployee->HourlyRate;
	cout << "\n";

	return pEmployee;
}

int main()
{
	int size = 0;
	while (size < 1)
	{
		cout << "Enter the number of employees: ";
		cin >> size;
		cout << "\n";
	}

	Employee* employees = new Employee[size];

	for (int i = 0; i < size; i++)
	{
		int emCount = (i+1);
		employees[i] = *GetEmployeeInfo(emCount);
	}

	PrintWeeklyPay(employees, size);




	(void)_getch();
	return 0;
}
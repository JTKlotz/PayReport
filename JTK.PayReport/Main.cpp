
//Assignment 4 - Pay Report
//Jordan Klotz
//10/13/2025

#include <iostream>
#include <conio.h>

using namespace std;

//employee struct
struct Employee
{
	int ID;
	string FirstName;
	string LastName;
	float HoursWorked;
	float HourlyRate;
};

//function to calculate weekly pay
float CalculateWeeklyPay(Employee* pE)
{
	//hours * hourly rate
	return pE->HoursWorked * pE->HourlyRate;
}

//function to print weekly pay report
void PrintWeeklyPay(Employee* employees, int size)
{
	//variables to store total and weekly pay
	float totalPay = 0;
	float weeklyPay = 0;

	//display report heading
	cout << "Pay Report\n";
	cout << "----------\n";

	for (int i = 0; i < size; i++)
	{
		//set weekly pay for each employee
		float weeklyPay = CalculateWeeklyPay(&employees[i]);

		//display each employee's pay
		cout << employees[i].ID << ". " << employees[i].FirstName << " " << employees[i].LastName << ": $" << weeklyPay << "\n";
		//add employees weekly pay to total pay
		totalPay += weeklyPay;

	}
	//display total pay
	cout << "\n";
	cout << "Total Pay: $" << totalPay;

}

//function to get employee info
Employee* GetEmployeeInfo(int i)
{
	//dynamically allocate memory for employee
	Employee* pEmployee = new Employee;
	//get employee info from user
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
	//variable to store number of employees
	int size = 0;
	while (size < 1)
	{
		//get number of employees from user
		cout << "Enter the number of employees: ";
		cin >> size;
		cout << "\n";
	}

	//dynamically allocate array of employees
	Employee* employees = new Employee[size];

	for (int i = 0; i < size; i++)
	{
		//variable to store employee number
		int emCount = (i+1);
		//get employee info and store in array
		employees[i] = *GetEmployeeInfo(emCount);
	}

	//print weekly pay report
	PrintWeeklyPay(employees, size);




	(void)_getch();
	return 0;
}
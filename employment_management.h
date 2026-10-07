#ifndef EMPLOYMENT_MANAGEMENT_H
#define EMPLOYMENT_MANAGEMENT_H

#define MAX_EMPLOYEES 100

extern int employeeCount;
extern double basicSalary[MAX_EMPLOYEES];
extern double housingAllowance[MAX_EMPLOYEES];
extern double transportAllowance[MAX_EMPLOYEES];
extern double otherAllowance[MAX_EMPLOYEES];

void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);

#endif

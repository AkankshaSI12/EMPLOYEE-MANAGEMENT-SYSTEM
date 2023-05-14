#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[50];
    int employee_id;
    float salary;
    char job_title[50];
};

struct Employee employees[MAX_EMPLOYEES];
int num_employees = 0;

void add_employee() {
    if (num_employees >= MAX_EMPLOYEES) {
        printf("Error: Maximum number of employees reached.\n");
        return;
    }
    
    struct Employee emp;
    printf("Enter employee name: ");
    scanf("%s", &emp.name);
    printf("Enter employee ID: ");
    scanf("%d", &emp.employee_id);
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);
    printf("Enter employee job title: ");
    scanf("%s", &emp.job_title);
    
    employees[num_employees] = emp;
    num_employees++;
    printf("Employee added successfully.\n");
}

void list_employees() {
    if (num_employees == 0) {
        printf("No employees to display.\n");
        return;
    }
    
    printf("Employees:\n");
    for (int i = 0; i < num_employees; i++) {
        struct Employee emp = employees[i];
        printf("%s (ID: %d)\n", emp.name, emp.employee_id);
        printf("Salary: $%f\n", emp.salary);
        printf("Job Title: %s\n", emp.job_title);
    }
}

int main() {
    int choice;
    
    do {
        printf("Employee Management System\n");
        printf("1. Add employee\n");
        printf("2. List employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                list_employees();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\n");
    } while (choice != 3);
    
    return 0;
}
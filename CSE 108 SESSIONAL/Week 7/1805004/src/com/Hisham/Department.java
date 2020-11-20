package com.Hisham;

public class Department {

    private int id;
    private String name;
    private Employee[] employees;
    private int employeeCount;
    // add your code here
    // there can be at most 20 departments
    private static int deptCount = 0;
    private static final Department[] depts = new Department[20];

    // you are not allowed to write any other constructor
    public Department(int id, String name) {
        this.id = id;
        this.name = name;
        this.employees = new Employee[10];
        // add your code here
        this.employeeCount = 0;
        depts[deptCount++] = this;
    }

    // add your code here
    public void addEmployee(Employee e) {
        this.employees[employeeCount++] = e;
    }

    public double getDepartmentSalary() {
        double total_Salary = 0.0;
        for (int i = 0; i < this.employeeCount; i++) {
            total_Salary += employees[i].getSalary();
        }
        return total_Salary;
    }

    public Employee getMaxSalaryEmployee() {
        double max = -1.0;
        Employee employee = null;
        for (int i = 0; i < this.employeeCount; i++) {
            if (max == -1.0 || max < this.employees[i].getSalary()) {
                max = this.employees[i].getSalary();
                employee = this.employees[i];
            }
        }
        return employee;
    }

    public static double getTotalSalary() {
        double sum = 0.0;
        for (int i = 0; i < deptCount; i++) {
            sum += depts[i].getDepartmentSalary();
        }
        return sum;
    }
}
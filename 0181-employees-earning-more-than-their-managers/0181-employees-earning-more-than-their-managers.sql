SELECT Emp.name as Employee FROM Employee Emp,Employee Manager WHERE Emp.managerId=Manager.id AND Emp.salary>Manager.salary;

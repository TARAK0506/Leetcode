SELECT employee_id FROM Employees WHERE SALARY < 30000 AND manager_id NOT IN(SELECT employee_id FROM Employees) ORDER BY employee_id;


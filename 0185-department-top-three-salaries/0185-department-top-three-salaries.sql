# Write your MySQL query statement below
WITH CTE AS (
      SELECT d.name AS 'Department',
      e.name AS 'Employee', 
      e.salary AS 'Salary' , 
      DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) AS  'top_three'
FROM Employee e JOIN Department d ON e.departmentId = d.id)

SELECT  Employee, Salary, Department FROM CTE WHERE top_three < 4; 


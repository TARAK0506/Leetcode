# Write your MySQL query statement below
SELECT (SELECT DISTINCT SALARY FROM EMPLOYEE order by Salary Desc limit 1 OFFSET 1) as SecondHighestSalary
# Write your MySQL query statement below
SELECT MAX(num) as num FROM MyNumbers WHERE num NOT IN (SELECT num FROM MyNumbers GROUP BY num HAVING COUNT(num)>1)
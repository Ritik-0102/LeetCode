-- Write your PostgreSQL query statement below
WITH FindHighestSalary AS (
    SELECT MAX(salary) AS highestSalary
    FROM Employee
)

SELECT MAX(salary) AS SecondHighestSalary 
FROM Employee
WHERE salary != (
    SELECT highestSalary
    FROM FindHighestSalary
);
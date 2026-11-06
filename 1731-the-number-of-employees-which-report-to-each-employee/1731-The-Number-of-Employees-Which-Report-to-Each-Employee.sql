-- Write your PostgreSQL query statement below
SELECT a.reports_to AS employee_id , 
b.name , 
COUNT(a.reports_to) AS reports_count , CAST(AVG(a.age) AS NUMERIC(2)) AS average_age
FROM Employees AS a JOIN Employees AS b
ON a.reports_to = b.employee_id
GROUP BY a.reports_to , b.name
ORDER BY employee_id;
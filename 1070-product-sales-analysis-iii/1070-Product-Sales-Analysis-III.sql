-- Write your PostgreSQL query statement below
SELECT product_id, year AS first_year, quantity , price
FROM Sales AS a
WHERE year = (
    SELECT MIN(year) FROM Sales 
    WHERE product_id = a.product_id
    );
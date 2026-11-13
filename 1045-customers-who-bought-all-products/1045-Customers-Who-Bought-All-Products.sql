-- Write your PostgreSQL query statement below
SELECT DISTINCT customer_id 
FROM Customer 
GROUP BY customer_id 
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(*) FROM Product
);
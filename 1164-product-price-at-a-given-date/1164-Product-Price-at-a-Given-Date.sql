-- Write your PostgreSQL query statement below

-- find the latest changed price of products on OR before 2019-08-16
SELECT product_id , new_price AS price
FROM Products
WHERE (product_id , change_date) IN (
    SELECT product_id , MAX(change_date)
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
)

UNION

-- find the products changed after 2019-08-16 (default 10)
SELECT DISTINCT product_id , 10 AS price
FROM Products
WHERE (product_id) NOT IN (
    SELECT product_id
    FROM Products 
    WHERE change_date <= '2019-08-16'
);
-- Write your PostgreSQL query statement below

-- Step 1: Combine multiple customer visits on the same day into a single daily total
WITH DailyTotals AS (
    SELECT 
        visited_on, 
        SUM(amount) AS daily_amount
    FROM Customer
    GROUP BY visited_on
)

-- Step 2: Calculate the 7-day rolling sum and average
SELECT a.visited_on,
    SUM(b.daily_amount) AS amount,
    ROUND(AVG(b.daily_amount), 2) AS average_amount
FROM DailyTotals a JOIN DailyTotals b 
-- Join every day with itself and the 6 preceding days
ON a.visited_on - b.visited_on BETWEEN 0 AND 6

GROUP BY a.visited_on
-- Step 3: Ensure we only output rows that have a full 7-day window
HAVING COUNT(a.visited_on) = 7
ORDER BY a.visited_on;
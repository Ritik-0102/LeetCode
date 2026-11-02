-- Write your PostgreSQL query statement below
SELECT ROUND(
    COUNT(DISTINCT a.player_id) :: numeric
        / (SELECT COUNT(DISTINCT player_id) FROM Activity) , 2
    ) AS fraction
FROM Activity AS a
JOIN (
    SELECT player_id , MIN(event_date) AS first_login
    FROM Activity
    GROUP By player_id
) AS f
ON a.player_id = f.player_id
AND a.event_date = first_login + 1;
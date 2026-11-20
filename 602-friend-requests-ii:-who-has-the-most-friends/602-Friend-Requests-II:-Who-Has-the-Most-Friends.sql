-- Write your PostgreSQL query statement below
WITH AllFriends AS (
    SELECT requester_id AS id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS id FROM RequestAccepted
),
FriendsCount AS (
    SELECT id , COUNT(id) AS num
    FROM AllFriends
    GROUP BY id
)

SELECT id , num
FROM FriendsCount
WHERE num = (SELECT MAX(num) FROM FriendsCount);
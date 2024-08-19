SELECT R.contest_id, ROUND(((COUNT(*) / total_users) * 100),2) AS percentage
FROM Register AS R
JOIN Users AS U ON R.user_id = U.user_id
CROSS JOIN (SELECT COUNT(*) AS total_users FROM Users) AS T
GROUP BY R.contest_id
ORDER BY percentage DESC, R.contest_id ASC;

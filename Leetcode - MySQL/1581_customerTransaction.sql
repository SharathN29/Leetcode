# https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/

SELECT customer_id, Count(*) as count_no_trans
FROM Visits
WHERE visit_id NOT IN(SELECT DISTINCT visit_id from Transactions)
GROUP BY customer_id
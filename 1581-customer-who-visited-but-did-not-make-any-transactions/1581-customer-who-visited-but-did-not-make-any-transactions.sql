# Write your MySQL query statement below
select v.customer_id , count(v.visit_id) AS count_no_trans FROM Transactions t
right join visits as v on t.visit_id = v.visit_id where t.transaction_id is NULL group BY v.customer_id
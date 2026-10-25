# Write your MySQL query statement below
select product_id , year as first_year , quantity , price
from Sales where
(Product_id , year) in (select product_id , min(year) from Sales group by product_id)
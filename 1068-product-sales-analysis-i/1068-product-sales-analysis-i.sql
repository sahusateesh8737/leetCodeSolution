# Write your MySQL query statement belowS
select product_name , year , price from Sales
inner join Product
on Sales.product_id =Product.product_id

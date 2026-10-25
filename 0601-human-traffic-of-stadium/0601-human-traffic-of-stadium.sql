# Write your MySQL query statement below
with grouped as (
    select id ,
    visit_date , 
    people ,
    id - row_number() over (order by id) as grp
    from Stadium 
    where people >= 100
),
Counted as (select id , visit_date , people, count(*) over (partition by grp) as cnt
from Grouped
)
select id , visit_date, people from Counted where cnt >= 3 order by visit_date asc;
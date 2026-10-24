# Write your MySQL query statement below
with PolicyCounts as (
    select tiv_2016,
    count(*) over(partition by tiv_2015) as tiv_2015_cnt,
    count(*) over(partition by lat , lon) as loc_cnt
    from Insurance
)

select
    round(sum(tiv_2016), 2) as tiv_2016
    from PolicyCounts
    where tiv_2015_cnt > 1
    and loc_cnt  = 1;
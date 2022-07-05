# Write your MySQL query statement below
with first_order as (
                select customer_id
                from Delivery
                group by customer_id
                having min(order_date) = min(customer_pref_delivery_date)
)
select round( cast(count( distinct customer_id) as decimal) /
            (select count(distinct customer_id) from Delivery) * 100
            , 2) as immediate_percentage
from first_order;
                
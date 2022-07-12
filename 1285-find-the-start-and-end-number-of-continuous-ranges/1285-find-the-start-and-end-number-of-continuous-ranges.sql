# Write your MySQL query statement below
select min(log_id) as start_id, max(log_id) as end_id
from (select log_id, row_number() over(order by log_id) as row_num from Logs) a 
group by log_id - row_num;
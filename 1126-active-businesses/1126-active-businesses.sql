# Write your MySQL query statement below
with agged as (
    select business_id
    , if(occurences > avg(occurences) over (partition by event_type), 1, 0) bool_flag
    from events
) select business_id
from agged
group by business_id
having sum(bool_flag) > 1

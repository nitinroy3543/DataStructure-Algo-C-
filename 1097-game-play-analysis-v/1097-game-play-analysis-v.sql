# Write your MySQL query statement below
select install_dt,count(distinct player_id) installs,
    round(sum(case when datediff(install_dt,next_dt)=-1 then 1 else 0 end)/count(distinct player_id),2) as Day1_retention
      from  (select player_id,event_date,
             min(event_date) over (partition by player_id order by event_date) as install_dt,
             lead(event_date) over (partition by player_id order by event_date) as next_dt
            from activity) ba

        group by 1;

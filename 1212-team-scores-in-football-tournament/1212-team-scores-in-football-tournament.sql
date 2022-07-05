# Write your MySQL query statement below
select t.team_id 

, 

t.team_name , 

sum(case when t.team_id = m.host_team AND m.guest_goals < m.host_goals then 3 
   when t.team_id =m.guest_team AND m.host_goals < m.guest_goals then 3 
    when t.team_id = m.guest_team  AND m.host_goals = m.guest_goals then 1 
    
    when t.team_id = m.host_team AND m.host_goals = m.guest_goals then 1 
    else 0 end 
   
   ) AS num_points 
   
   from teams t 
   left join matches m 
   on m.host_team = t.team_id or m.guest_team = t.team_id 
   group by 1,2
   order by num_points desc , team_id asc 

# Write your MySQL query statement below
select distinct a.id, name 
from( select id,
    datediff(lead(login_date,4) over(partition by id order by login_date), login_date) gap
    from
    (select distinct id, login_date from Logins) ded_a
    ) a 
join Accounts on a.id=Accounts.id
where gap=4
order by a.id

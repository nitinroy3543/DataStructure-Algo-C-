# Write your MySQL query statement below
SELECT firstName, lastName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId
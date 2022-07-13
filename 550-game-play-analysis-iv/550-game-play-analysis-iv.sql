# Write your MySQL query statement below
WITH temp AS(
	SELECT player_id,
	event_date - LAG(event_date, 1) OVER (PARTITION BY player_id ORDER BY event_date) AS difference, 
	RANK() OVER (PARTITION BY player_id ORDER BY event_date) as rn
	FROM activity
),

tp AS
(
	SELECT count(distinct(player_id)) as all_players
	FROM activity
)

SELECT ROUND(count(t.player_id)/tp.all_players,2) AS fraction

	FROM temp t
	JOIN tp

WHERE t.rn = 2
AND t.difference = 1


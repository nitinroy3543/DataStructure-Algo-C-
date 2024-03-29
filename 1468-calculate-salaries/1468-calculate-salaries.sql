# Write your MySQL query statement below
SELECT 
T.COMPANY_ID,
S.EMPLOYEE_ID,
S.EMPLOYEE_NAME,
ROUND(S.SALARY - S.SALARY * T.PERCENTAGE,0) AS SALARY 
FROM SALARIES AS S 
JOIN 
(
    SELECT 
    COMPANY_ID,
    CASE 
        WHEN MAX(SALARY) < 1000 THEN 0
        WHEN MAX(SALARY) >= 1000 AND MAX(SALARY) <= 10000 THEN 0.24
        ELSE 0.49
    END AS PERCENTAGE
    FROM SALARIES 
    GROUP BY COMPANY_ID
) AS T
ON S.COMPANY_ID = T.COMPANY_ID 

SELECT 
    d.name AS Department, 
    e.name AS Employee,
    e.salary AS Salary
FROM Employee e
JOIN Department d ON e.departmentId = d.id  -- Fixed alias from 's' to 'd'
WHERE (e.departmentId, e.salary) IN (       -- Added 'e.salary' and 'IN ('
    SELECT departmentId, MAX(salary)        -- Added 'SELECT departmentId,'
    FROM Employee
    GROUP BY departmentId
);

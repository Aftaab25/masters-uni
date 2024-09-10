SHOW TABLES;

SELECT * FROM employees;
SELECT * FROM salaries;

SELECT TITLE, COUNT(EMP_NO) FROM titles  WHERE TITLE IN ('ASSISTANT ENGINEER', 'ENGINEER') GROUP BY TITLE;




























SELECT * FROM departments WHERE dept_no = 'd004' OR dept_no = 'd005';


SELECT AVG(SALARY), COUNT(EMP_NO) FROM salaries;

    #
# desc employees;
# desc departments;
# desc current_dept_emp;

# select * from titles;

SELECT TITLE, COUNT(EMP_NO) FROM titles WHERE TITLE IN ('ASSISTANT ENGINEER', 'ENGINEER') GROUP BY TITLE;

SELECT `salaries`.`emp_no`, `salaries`.`salary`, `employees`.`first_name`,
`employees`.`last_name`, `employees`.`gender`, `employees`.`hire_date`,
`departments`.`dept_name`
FROM `salaries`
    INNER JOIN `employees` ON `salaries`.`emp_no` = `employees`.`emp_no`
    INNER JOIN `dept_emp` ON `salaries`.`emp_no` = `dept_emp`.`emp_no`
    INNER JOIN `departments` ON `departments`.`dept_no` = `dept_emp`.`dept_no`
ORDER BY `salaries`.`salary` DESC;

SELECT `salaries`.`emp_no`, `salaries`.`salary`, `employees`.`first_name`, `employees`.`last_name`, `employees`.`gender`, `employees`.`hire_date`
FROM `salaries`
    INNER JOIN `employees` ON `salaries`.`emp_no` =`employees`.`emp_no`
ORDER BY `salaries`.`salary` DESC;
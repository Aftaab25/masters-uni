USE employees;
# ============================== To Drop Indexes =========================================================== #
ALTER TABLE dept_emp DROP FOREIGN KEY dept_emp_ibfk_2;
DROP INDEX idx_deptno ON dept_emp;
ALTER TABLE dept_emp ADD CONSTRAINT dept_emp_ibfk_2 FOREIGN KEY (dept_no) REFERENCES departments(dept_no);
# ========================================================================================================== #


# ========================================================================================================== #
# 1. Count the number of employees in each department
SELECT dept_no, COUNT(emp_no) AS employee_count
FROM dept_emp
GROUP BY dept_no;

EXPLAIN SELECT dept_no, COUNT(emp_no) AS employee_count
FROM dept_emp
GROUP BY dept_no;

CREATE INDEX idx_deptno ON dept_emp(dept_no);

SELECT dept_no, COUNT(emp_no) AS employee_count
FROM dept_emp
GROUP BY dept_no;

EXPLAIN SELECT dept_no, COUNT(emp_no) AS employee_count
FROM dept_emp
GROUP BY dept_no;

# Drop Index
ALTER TABLE dept_emp DROP FOREIGN KEY dept_emp_ibfk_2;
DROP INDEX idx_deptno ON dept_emp;
ALTER TABLE dept_emp ADD CONSTRAINT dept_emp_ibfk_2 FOREIGN KEY (dept_no) REFERENCES departments(dept_no);

# ========================================================================================================== #
# 2. Join employees and salaries to get the current salary of each employee
SELECT e.emp_no, e.first_name, e.last_name, s.salary
FROM employees e
JOIN salaries s ON e.emp_no = s.emp_no
WHERE s.to_date = '9999-01-01';

EXPLAIN SELECT e.emp_no, e.first_name, e.last_name, s.salary
FROM employees e
JOIN salaries s ON e.emp_no = s.emp_no
WHERE s.to_date = '9999-01-01';

CREATE INDEX idx_empno ON salaries(emp_no);

SELECT e.emp_no, e.first_name, e.last_name, s.salary
FROM employees e
JOIN salaries s ON e.emp_no = s.emp_no
WHERE s.to_date = '9999-01-01';

EXPLAIN SELECT e.emp_no, e.first_name, e.last_name, s.salary
FROM employees e
JOIN salaries s ON e.emp_no = s.emp_no
WHERE s.to_date = '9999-01-01';

# Drop Index
# ALTER TABLE dept_emp DROP FOREIGN KEY dept_emp_ibfk_2;
DROP INDEX idx_empno ON salaries;
# ALTER TABLE dept_emp ADD CONSTRAINT dept_emp_ibfk_2 FOREIGN KEY (dept_no) REFERENCES departments(dept_no);

# ========================================================================================================== #

# ========================================================================================================== #
# 3. Select employees who were hired after 1995
SELECT emp_no, first_name, last_name
FROM employees
WHERE hire_date > '1995-01-01';

EXPLAIN SELECT emp_no, first_name, last_name
FROM employees
WHERE hire_date > '1995-01-01';

CREATE INDEX idx_hiredate ON employees(hire_date);

SELECT emp_no, first_name, last_name
FROM employees
WHERE hire_date > '1995-01-01';

EXPLAIN SELECT emp_no, first_name, last_name
FROM employees
WHERE hire_date > '1995-01-01';

# Drop Index
# ALTER TABLE dept_emp DROP FOREIGN KEY dept_emp_ibfk_2;
DROP INDEX idx_hiredate ON employees;
# ALTER TABLE dept_emp ADD CONSTRAINT dept_emp_ibfk_2 FOREIGN KEY (dept_no) REFERENCES departments(dept_no);

# ========================================================================================================== #

# ========================================================================================================== #
# 4.
# Get a list of employees along with their department and current salary, where salary is greater than 80,000
SELECT e.emp_no, e.first_name, e.last_name, d.dept_name, s.salary
FROM employees e
JOIN dept_emp de ON e.emp_no = de.emp_no
JOIN departments d ON de.dept_no = d.dept_no
JOIN salaries s ON e.emp_no = s.emp_no
WHERE s.to_date = '9999-01-01' AND s.salary > 80000;

EXPLAIN SELECT e.emp_no, e.first_name, e.last_name, d.dept_name, s.salary
FROM employees e
JOIN dept_emp de ON e.emp_no = de.emp_no
JOIN departments d ON de.dept_no = d.dept_no
JOIN salaries s ON e.emp_no = s.emp_no
WHERE s.to_date = '9999-01-01' AND s.salary > 80000;

CREATE INDEX idx_salary ON salaries(salary);
CREATE INDEX idx_deptno ON dept_emp(dept_no);

SELECT e.emp_no, e.first_name, e.last_name, d.dept_name, s.salary
FROM employees e
JOIN dept_emp de ON e.emp_no = de.emp_no
JOIN departments d ON de.dept_no = d.dept_no
JOIN salaries s ON e.emp_no = s.emp_no
WHERE s.to_date = '9999-01-01' AND s.salary > 80000;

EXPLAIN SELECT e.emp_no, e.first_name, e.last_name, d.dept_name, s.salary
FROM employees e
JOIN dept_emp de ON e.emp_no = de.emp_no
JOIN departments d ON de.dept_no = d.dept_no
JOIN salaries s ON e.emp_no = s.emp_no
WHERE s.to_date = '9999-01-01' AND s.salary > 80000;

# Drop Index
# ALTER TABLE dept_emp DROP FOREIGN KEY dept_emp_ibfk_2;
DROP INDEX idx_salary ON salaries;
DROP INDEX idx_deptno ON dept_emp;
# ALTER TABLE dept_emp ADD CONSTRAINT dept_emp_ibfk_2 FOREIGN KEY (dept_no) REFERENCES departments(dept_no);

# ========================================================================================================== #

# ========================================================================================================== #
# 5. Querying Employees by Last Name and Department Number
SELECT e.emp_no, e.first_name, e.last_name, de.dept_no
FROM employees e
JOIN dept_emp de ON e.emp_no = de.emp_no
WHERE e.last_name = 'Doe' AND de.dept_no = 'd005';

EXPLAIN SELECT e.emp_no, e.first_name, e.last_name, de.dept_no
FROM employees e
JOIN dept_emp de ON e.emp_no = de.emp_no
WHERE e.last_name = 'Doe' AND de.dept_no = 'd005';

CREATE INDEX idx_lastname_deptno ON employees(last_name, emp_no);

SELECT e.emp_no, e.first_name, e.last_name, de.dept_no
FROM employees e
JOIN dept_emp de ON e.emp_no = de.emp_no
WHERE e.last_name = 'Doe' AND de.dept_no = 'd005';

EXPLAIN SELECT e.emp_no, e.first_name, e.last_name, de.dept_no
FROM employees e
JOIN dept_emp de ON e.emp_no = de.emp_no
WHERE e.last_name = 'Doe' AND de.dept_no = 'd005';

# Drop Index
# ALTER TABLE dept_emp DROP FOREIGN KEY dept_emp_ibfk_2;
    DROP INDEX idx_lastname_deptno ON employees;
# ALTER TABLE dept_emp ADD CONSTRAINT dept_emp_ibfk_2 FOREIGN KEY (dept_no) REFERENCES departments(dept_no);

# ========================================================================================================== #
    
-- Get a list of employees who have changed departments and their current salary
SELECT e.emp_no, e.first_name, e.last_name, s.salary
FROM employees e
JOIN salaries s ON e.emp_no = s.emp_no
JOIN dept_emp de1 ON e.emp_no = de1.emp_no
JOIN dept_emp de2 ON e.emp_no = de2.emp_no
WHERE de1.dept_no != de2.dept_no AND s.to_date = '9999-01-01';

CREATE INDEX idx_emp_dept ON dept_emp(emp_no, dept_no);

SELECT e.emp_no, e.first_name, e.last_name, s.salary
FROM employees e
JOIN salaries s ON e.emp_no = s.emp_no
JOIN dept_emp de1 ON e.emp_no =     de1.emp_no
JOIN dept_emp de2 ON e.emp_no = de2.emp_no
WHERE de1.dept_no != de2.dept_no AND s.to_date = '9999-01-01';

DROP INDEX idx_emp_dept ON dept_emp;

DESC employees;

SELECT * FROM employees WHERE emp_no = 10001;
EXPLAIN SELECT * FROM employees WHERE emp_no = 10001;

SELECT
    table_name,
    constraint_name,
    column_name,
    referenced_table_name,
    referenced_column_name
FROM
    information_schema.key_column_usage
WHERE
    referenced_table_name = 'employees'
    AND referenced_column_name = 'emp_no';

ALTER TABLE dept_emp ADD FOREIGN KEY dept_emp_ibfk_1;
ALTER TABLE dept_manager ADD FOREIGN KEY dept_manager_ibfk_1;

ALTER TABLE dept_emp ADD CONSTRAINT dept_emp_ibfk_1 FOREIGN KEY (emp_no) REFERENCES employees(emp_no);
ALTER TABLE dept_manager ADD CONSTRAINT dept_manager_ibfk_1 FOREIGN KEY (emp_no) REFERENCES employees(emp_no);



ALTER TABLE employees DROP PRIMARY KEY;

EXPLAIN SELECT * FROM employees WHERE emp_no = 10001;
ALTER TABLE employees DROP PRIMARY KEY;
EXPLAIN SELECT * FROM employees WHERE emp_no = 10001;
SELECT * FROM employees WHERE emp_no = 10001;

ALTER TABLE employees ADD PRIMARY KEY (emp_no);

SELECT * FROM employees WHERE last_name = 'Smith';
CREATE INDEX idx_last_name ON employees (last_name);
EXPLAIN SELECT * FROM employees WHERE last_name = 'Smith';
DROP INDEX idx_last_name ON employees;

desc salaries;
ALTER TABLE salaries DROP PRIMARY KEY;
EXPLAIN SELECT * FROM salaries WHERE emp_no = 10001 AND from_date = '1996-06-23';
ALTER TABLE salaries ADD PRIMARY KEY (emp_no, from_date);



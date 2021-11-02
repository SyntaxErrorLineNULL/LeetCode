/**
  Combine Two Tables
  */
Create table If Not Exists Person (personId int, firstName varchar(255), lastName varchar(255))
Create table If Not Exists Address (addressId int, personId int, city varchar(255), state varchar(255))
Truncate table Person
insert into Person (personId, lastName, firstName) values ('1', 'Wang', 'Allen')
insert into Person (personId, lastName, firstName) values ('2', 'Alice', 'Bob')
Truncate table Address
insert into Address (addressId, personId, city, state) values ('1', '2', 'New York City', 'New York')
insert into Address (addressId, personId, city, state) values ('2', '3', 'Leetcode', 'California')

SELECT firstname, lastname, city, state
    FROM Person LEFT JOIN Address ON Person.personid = Address.personid

/**
  Employees Earning More Than Their Managers
 */
Create table If Not Exists Employee (id int, name varchar(255), salary int, managerId int)
Truncate table Employee
insert into Employee (id, name, salary, managerId) values ('1', 'Joe', '70000', '3')
insert into Employee (id, name, salary, managerId) values ('2', 'Henry', '80000', '4')
insert into Employee (id, name, salary, managerId) values ('3', 'Sam', '60000', 'None')
insert into Employee (id, name, salary, managerId) values ('4', 'Max', '90000', 'None')

select a.Name as 'Employee'
    from Employee as a, Employee as b
         where a.ManagerId = b.Id and a.Salary > b.Salary

/** Use join */
select a.Name as 'Employee'
    from Employee as a join Employee as b
        on a.ManagerId = b.Id and a.Salary > b.Salary

/**
    Duplicate Emails
 */
Create table If Not Exists Person (id int, email varchar(255))
Truncate table Person
insert into Person (id, email) values ('1', 'a@b.com')
insert into Person (id, email) values ('2', 'c@d.com')
insert into Person (id, email) values ('3', 'a@b.com')

select Email
    from Person
        group by Email
            having count(Email) > 1

/**
  Not Boring Movies
 */
Create table If Not Exists cinema (id int, movie varchar(255), description varchar(255), rating float(2, 1))
Truncate table cinema
insert into cinema (id, movie, description, rating) values ('1', 'War', 'great 3D', '8.9')
insert into cinema (id, movie, description, rating) values ('2', 'Science', 'fiction', '8.5')
insert into cinema (id, movie, description, rating) values ('3', 'irish', 'boring', '6.2')
insert into cinema (id, movie, description, rating) values ('4', 'Ice song', 'Fantacy', '8.6')
insert into cinema (id, movie, description, rating) values ('5', 'House card', 'Interesting', '9.1')

select *
    from cinema
        where description <> 'boring' and id % 2
        #where id % 2 and description != 'boring'
            order by rating DESC

/**
  Big Countries
 */

Create table If Not Exists World (name varchar(255), continent varchar(255), area int, population int, gdp int)
Truncate table World
insert into World (name, continent, area, population, gdp) values ('Afghanistan', 'Asia', '652230', '25500100', '20343000000')
insert into World (name, continent, area, population, gdp) values ('Albania', 'Europe', '28748', '2831741', '12960000000')
insert into World (name, continent, area, population, gdp) values ('Algeria', 'Africa', '2381741', '37100000', '188681000000')
insert into World (name, continent, area, population, gdp) values ('Andorra', 'Europe', '468', '78115', '3712000000')
insert into World (name, continent, area, population, gdp) values ('Angola', 'Africa', '1246700', '20609294', '100990000000')

select name, population, area
    from World
        where area > 3000000 or population > 25000000

/**
  Swap Salary
 */
Create table If Not Exists Salary (id int, name varchar(100), sex char(1), salary int)
Truncate table salary
insert into salary (id, name, sex, salary) values ('1', 'A', 'm', '2500')
insert into salary (id, name, sex, salary) values ('2', 'B', 'f', '1500')
insert into salary (id, name, sex, salary) values ('3', 'C', 'm', '5500')
insert into salary (id, name, sex, salary) values ('4', 'D', 'f', '500')

update salary
set sex = CASE sex
      when 'm' then 'f' else 'm'
end;

/**
  Second Highest Salary
 */

Create table If Not Exists Employee (id int, salary int)
Truncate table Employee
insert into Employee (id, salary) values ('1', '100')
insert into Employee (id, salary) values ('2', '200')
insert into Employee (id, salary) values ('3', '300')

select max(Salary) as SecondHighestSalary
    from employee
        where Salary < (select max(Salary) from Employee)


-- 177. Nth Highest Salary (PL/SQL)
Create table If Not Exists Employee (Id int, Salary int)
Truncate table Employee
insert into Employee (id, salary) values ('1', '100')
insert into Employee (id, salary) values ('2', '200')
insert into Employee (id, salary) values ('3', '300')

CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS result NUMBER;
BEGIN
SELECT x.Salary
    INTO result FROM(
        SELECT Salary, ROWNUM rr
            FROM (SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC)
    ) x WHERE x.rr = n;
    RETURN result;
Exception
            WHEN NO_DATA_FOUND THEN
        result := NULL;
END;
-- -- 177. Nth Highest Salary (MySQL)
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N -1;
RETURN (
        # Write your MySQL query statement below.
      SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT N, 1
    );
END

-- 178. Rank Scores

/* Write your PL/SQL query statement below */
SELECT score, DENSE_RANK() OVER (ORDER BY score DESC) AS Rank FROM scores ORDER BY score DESC;
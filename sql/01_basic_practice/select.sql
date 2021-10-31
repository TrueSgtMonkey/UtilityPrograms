/* 
SELECT statements retrieve data from a database.
* Referred to as queries.
* We want to:
    - specify what data we are looking for
    - where to find it in database
    - (OPTIONAL) How to transform it before it is returned 

Think of a table like a class.
* Then, think of each row like an instance of that class.

SELECTING SPECIFIC COLUMNS
*/

--SELECT id, name FROM test;

/*
We are essentially returning a copy of the table, but only with the columns that we selected.

SELECTING ALL COLUMNS
 */
--SELECT * FROM test;

/*
Simple way to get all data all at once.
 */

--DECLARE @Msg VARCHAR(50)='SELECT title FROM movies;';
--PRINT @Msg;

--find title of each film
SELECT title FROM movies;

--find director of each film
SELECT director FROM movies;

--find title and director of each film
SELECT title, director FROM movies;

--find title and year of each film
SELECT title, year FROM movies;

--find all info about each film
SELECT * FROM movies;

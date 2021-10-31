/*
We don't want to read through all of the rows all of the time.

We are going to use a WHERE clause.
* Clause applied to each row of data to determine whether or not it should be included in the results or not.
 */

SELECT director, title FROM movies WHERE (id >= 4 AND id <= 6);
SELECT * FROM movies WHERE id=0;
/*
OPERATORS:
=             (checks if they are equal)
!=            (unequal)
<, <=, >, >=  (checks less than, greater than, equal to)
BETWEEN       (checks if between num1 AND num2)
AND           (can be used to check for multiple conditionals that need to be true)
NOT           (gets the opposite of whatever you are trying to find the condition of)
IN            (checks if number exists in a list)
 */

--Can allow the query to run faster due to less data returned

--find th movie with a row id of 6
SELECT * FROM movies WHERE id=6;
SELECT * FROM movies WHERE id=0;

SELECT * FROM movies WHERE year >= 2000 AND year <= 2010;
SELECT * FROM movies WHERE id=0;

SELECT * FROM movies WHERE year < 2000 OR year > 2010;
SELECT * FROM movies WHERE id=0;

SELECT * FROM movies WHERE id <= 5;
SELECT * FROM movies WHERE id=0;














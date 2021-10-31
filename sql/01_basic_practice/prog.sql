DROP TABLE movies;

CREATE TABLE movies
(
    id NUMBER PRIMARY KEY,
    title TEXT,
    director NUMBER,
    year NUMBER,
    length_minutes NUMBER
);

INSERT INTO movies VALUES(1, 'Toy Story', 'John Lasseter', 1995, 81);
INSERT INTO movies VALUES(2, 'A Bugs Life', 'John Lasseter', 1998, 95);
INSERT INTO movies VALUES(3, 'Toy Story 2', 'John Lasseter', 1999, 93);
INSERT INTO movies VALUES(4, 'Monsters, Inc', 'Pete Docter', 2001, 92);
INSERT INTO movies VALUES(5, 'Finding Nemo', 'Andrew Stanton', 2003, 107);
INSERT INTO movies VALUES(6, 'The Incredibles', 'Brad Bird', 2004, 116);
INSERT INTO movies VALUES(7, 'Cars', 'John Lasseter', 2006, 117);
INSERT INTO movies VALUES(8, 'Ratatouille', 'Brad Bird', 2007, 115);
INSERT INTO movies VALUES(9, 'WALL-E', 'Andrew Stanton', 2008, 104);

SELECT * FROM movies;

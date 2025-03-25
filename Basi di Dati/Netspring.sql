DROP DATABASE IF EXISTS Netspring;
CREATE DATABASE Netspring;
USE Netspring;

CREATE TABLE IF NOT EXISTS movies (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    release_year INT,
    language VARCHAR(50),
    rental_duration INT,
    rating VARCHAR(10)
);

CREATE TABLE IF NOT EXISTS actor (
    id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    birth_date DATE,
    gender ENUM('M', 'F')
);

CREATE TABLE IF NOT EXISTS film_actor (
    film_id INT,
    actor_id INT,
    PRIMARY KEY (film_id, actor_id),
    FOREIGN KEY (film_id) REFERENCES movies(id),
    FOREIGN KEY (actor_id) REFERENCES actor(id)
);

INSERT INTO movies (title, release_year, language, rental_duration, rating) VALUES
('The Dark Knight', 2008, 'English', 7, 'PG-13'),
('Inception', 2010, 'English', 7, 'PG-13'),
('The Matrix', 1999, 'English', 7, 'R');

INSERT INTO actor (first_name, last_name, birth_date, gender) VALUES
('Christian', 'Bale', '1974-01-30', 'M'),
('Heath', 'Ledger', '1979-04-04', 'M'),
('Leonardo', 'DiCaprio', '1974-11-11', 'M'),
('Keanu', 'Reeves', '1964-09-02', 'M');

INSERT INTO film_actor (film_id, actor_id) VALUES
(1, 1), 
(1, 2), 
(2, 3), 
(3, 4);










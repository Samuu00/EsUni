DROP DATABASE IF EXISTS ReteInternet;
CREATE DATABASE ReteInternet;
USE ReteInternet;

CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    email VARCHAR(100) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS accessPoint(
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    location VARCHAR(100) NOT NULL,
    max_users INT NOT NULL
);

CREATE TABLE IF NOT EXISTS connections(
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    access_point_id INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (access_point_id) REFERENCES accessPoint(id)
);




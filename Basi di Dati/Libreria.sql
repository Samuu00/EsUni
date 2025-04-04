DROP DATABASE IF EXISTS Libreria;
CREATE DATABASE Libreria;
USE Libreria;

CREATE TABLE IF NOT EXISTS Libri(
    id INT AUTO_INCREMENT PRIMARY KEY,
    titolo VARCHAR(100) NOT NULL,
    autore VARCHAR(100) NOT NULL,
    annoPubblicazione INT NOT NULL
);

CREATE TABLE IF NOT EXISTS Prestiti(
    id INT AUTO_INCREMENT PRIMARY KEY,
    idLibro INT NOT NULL,
    dataPrestito DATE NOT NULL,
    dataRestituzione DATE,
    FOREIGN KEY (idLibro) REFERENCES Libri(id)
);


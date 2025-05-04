DROP DATABASE IF EXISTS AgenziaViaggi;
CREATE DATABASE AgenziaViaggi;
USE AgenziaViaggi;

CREATE TABLE Clienti(
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    cognome VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL,
    telefono VARCHAR(20)
);

CREATE TABLE Destinazioni(
    id INT AUTO_INCREMENT PRIMARY KEY,
    paese VARCHAR(50) NOT NULL,
    citta VARCHAR(50) NOT NULL,
    prezzoBase INT NOT NULL
);

CREATE TABLE Prenotazioni(
    id INT AUTO_INCREMENT PRIMARY KEY,
    idCliente INT NOT NULL,
    idDestinazione INT NOT NULL,
    dataPartenza DATE NOT NULL,
    numeroPersone INT NOT NULL,
    prezzoTotale INT NOT NULL,
    FOREIGN KEY (idCliente) REFERENCES Clienti(id),
    FOREIGN KEY (idDestinazione) REFERENCES Destinazioni(id)
);


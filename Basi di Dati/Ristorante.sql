DROP DATABASE IF EXISTS Ristorante;
CREATE DATABASE Ristorante;
USE Ristorante;

CREATE TABLE IF NOT EXISTS Clienti(
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cognome VARCHAR(100) NOT NULL,
    telefono VARCHAR(15) NOT NULL
);
CREATE TABLE IF NOT EXISTS Prenotazioni(
    id INT AUTO_INCREMENT PRIMARY KEY,
    idCliente INT NOT NULL,
    dataPrenotazione DATE NOT NULL,
    numeroPersone INT NOT NULL,
    FOREIGN KEY (idCliente) REFERENCES Clienti(id)
);
CREATE TABLE IF NOT EXISTS Piatti(
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    categoria VARCHAR(50) NOT NULL,
    prezzo DECIMAL(10, 2) NOT NULL
);
CREATE TABLE IF NOT EXISTS Ordini(
    id INT AUTO_INCREMENT PRIMARY KEY,
    idPrenotazione INT NOT NULL,
    idPiatto INT NOT NULL,
    quantita INT NOT NULL,
    FOREIGN KEY (idPrenotazione) REFERENCES Prenotazioni(id),
    FOREIGN KEY (idPiatto) REFERENCES Piatti(id)
);
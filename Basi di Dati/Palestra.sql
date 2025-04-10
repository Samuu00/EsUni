DROP DATABASE IF EXISTS Palestra;
CREATE DATABASE Palestra;
USE Palestra;

CREATE TABLE IF NOT EXISTS Clienti(
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cognome VARCHAR(100) NOT NULL,
    data_Iscrizione DATE NOT NULL,
    tipo_Abbonamento ENUM('Mensile', 'Trimestrale', 'Annuale') NOT NULL
);

CREATE TABLE IF NOT EXISTS Istruttori(
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cognome VARCHAR(100) NOT NULL,
    specializzazione VARCHAR(100) NOT NULL
);
CREATE TABLE IF NOT EXISTS Corsi(
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome_corso VARCHAR(100) NOT NULL,
    giorno_settimana ENUM('Lunedi', 'Martedi', 'Mercoledi', 'Giovedi', 'Venerdi', 'Sabato', 'Domenica') NOT NULL,
    orario TIME NOT NULL,
    idIstruttore INT NOT NULL,
    FOREIGN KEY (idIstruttore) REFERENCES Istruttori(id)
);
CREATE TABLE IF NOT EXISTS Partecipazioni(
    id INT AUTO_INCREMENT PRIMARY KEY,
    idCorso INT NOT NULL,
    idCliente INT NOT NULL,
    idstruttore INT NOT NULL,
    data_Participazione DATE NOT NULL,
    FOREIGN KEY (idstruttore) REFERENCES Istruttori(id),
    FOREIGN KEY (idCorso) REFERENCES Corsi(id),
    FOREIGN KEY (idCliente) REFERENCES Clienti(id)
);

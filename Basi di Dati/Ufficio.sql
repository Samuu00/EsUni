DROP DATABASE IF EXISTS Ufficio;
CREATE DATABASE Ufficio;
USE Ufficio;

CREATE TABLE IF NOT EXISTS capi_ufficio (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    cognome VARCHAR(50) NOT NULL,
    dipendente_nome VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS dipendenti (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    cognome VARCHAR(50) NOT NULL,
    data_assunzione DATE NOT NULL,
    stipendio DECIMAL(10, 2) NOT NULL,
    capo_ufficio_name INT,
    FOREIGN KEY (capo_ufficio_name) REFERENCES capi_ufficio(id)
);

CREATE TABLE IF NOT EXISTS sedi (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    dipendente_id INT,
    FOREIGN KEY (dipendente_id) REFERENCES dipendenti(id)
);




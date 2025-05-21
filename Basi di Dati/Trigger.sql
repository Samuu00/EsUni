CREATE TRIGGER controllo_email
BEFORE UPDATE ON utenti
FOR EACH ROW
BEGIN 
    DECLARE email_count INT;

    SELECT COUNT(*) INTO email_count
    FROM utenti
    WHERE email = NEW.email AND id <> OLD.id;

    IF email_count > 0 THEN 
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'ERRORE EMAIL PRESENTE';
    END IF;
END;


CREATE TRIGGER insert_utente
AFTER INSERT ON utenti
FOR EACH ROW
BEGIN
    INSERT INTO log_utenti(id_utente, email, data_inserimento)
    VALUES (NEW.id, NEW.email, CURRENT_TIMESTAMP); 
END;


CREATE TRIGGER delete_utente
BEFORE DELETE ON utenti
FOR EACH ROW
BEGIN
    IF OLD.ruolo = 'admin' THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'BLOCCO CANCELLAZIONE';
    END IF;
END;


/* 1 */
CREATE TRIGGER blockPrezzo
BEFORE UPDATE ON prodotti
FOR EACH ROW
BEGIN
    IF NEW.prezzo <= 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'PREZZO INFERIORE O UGUALE A 0';
    END IF;
END;


/* 2 */
CREATE TRIGGER add_log_ordini
AFTER INSERT ON ordini
FOR EACH ROW
BEGIN
    INSERT INTO log_ordini(id_ordine, id_cliente, data_ordine)
    VALUES (NEW.id, NEW.id_cliente, CURRENT_TIMESTAMP);
END;


/* 3 */
CREATE TRIGGER blockDelete
BEFORE DELETE ON dipendenti
FOR EACH ROW
BEGIN
    DECLARE progInCorso INT;

    SELECT COUNT(*) INTO progInCorso
    FROM progetti
    WHERE id_dipendente = OLD.id AND stato = 'in_corso';

    IF progInCorso > 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'DIPENDENTE IN CORSO DI PROGETTO';
    END IF;

END;


/* 1 */
CREATE TRIGGER aggStock
AFTER INSERT ON ordini
FOR EACH ROW
BEGIN
    UPDATE prodotti
    SET quantita_disponibile = quantita_disponibile - NEW.quantita_acquistata
    WHERE id = NEW.id_prodotto;
END;

/* 2 */
CREATE TRIGGER impedDoppio
BEFORE INSERT ON utenti
FOR EACH ROW
BEGIN
    DECLARE usernameEsist INT;

    SELECT COUNT(*) INTO usernameEsist
    FROM utenti
    WHERE username = NEW.username;

    IF usernameEsist > 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'USERNAME GIA ESISTENTE';
    END IF;
END;


/* 3 */
CREATE TRIGGER cambiaRuolo
BEFORE UPDATE ON dipendenti
FOR EACH ROW
BEGIN
    IF OLD.ruolo <> NEW.ruolo THEN
        INSERT INTO cambiaRuolo(id_dipendente, vecchio_ruolo, nuovo_ruolo, data_cambio)
        VALUES(NEW.id, OLD.ruolo, NEW.ruolo, CURRENT_TIMESTAMP);
    END IF;

END;



    

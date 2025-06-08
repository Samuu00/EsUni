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


/* 1 */
CREATE TRIGGER addPoint
AFTER INSERT ON ordini
FOR EACH ROW
BEGIN
    UPDATE clienti
    SET punti_fedelta = punti_fedelta + FLOOR(NEW.importo / 10);
    WHERE id_cliente = NEW_id_cliente;
END;


/* 2 */
CREATE TRIGGER blockModify
BEFORE UPDATE ON dipendenti
FOR EACH ROW
BEGIN
    IF OLD.email != NEW.email THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'NON AMMESSA MODIFICA';
    END IF;
END;


/* 3 */
CREATE TRIGGER changeLog
AFTER UPDATE ON impiegati
FOR EACH ROW
BEGIN
    IF OLD.stipendio != NEW.stipendio THEN
        INSERT INTO log_stipendi(id_impiegato, stipendio_vecchio, stipendio_nuovo, data_modifica)
        VALUES(NEW.id, OLD.stipendio, NEW.stipendio, CURRENT_TIMESTAMP);
END;
    

/* 1 */
CREATE TRIGGER archivioDipe
AFTER DELETE ON dipendenti
FOR EACH ROW
BEGIN
    INSERT INTO archivio_dipendenti(id_dipendente, nome, cognome, ruolo, data_eliminazione)
    VALUES(OLD.id, OLD.nome, OLD.cognome, OLD.ruolo, CURRENT_TIMESTAMP);
END;


/* 2 */
CREATE TRIGGER journey
BEFORE INSERT ON prenotazioni
FOR EACH ROW
BEGIN
    IF NEW.data_partenza < CURRENT_DATE THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'NON AMMESSA PRENOTAZIONE';
    END IF;
END;


/* 1 */
CREATE TRIGGER email
BEFORE INSERT ON utenti
FOR EACH ROW
BEGIN
    DECLARE email_count INT;
    
    SELECT COUNT(*) INTO email_count
    FROM utenti
    WHERE email = NEW.email;

    IF email_count > 0 THEN 
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'EMAIL GIÀ REGISTRATA';
    END IF;
END;

/* 2 */
CREATE TRIGGER log
AFTER DELETE ON dipendenti
FOR EACH ROW
BEGIN
    INSERT INTO archivio_dipendenti(id_dipendente, nome, cognome, ruolo, data_eliminazione)
    VALUES(OLD.id, OLD.nome, OLD.cognome, OLD.ruolo, CURRENT_TIMESTAMP);
END;


/* 1 */
CREATE TRIGGER aggSaldo
AFTER INSERT ON pagamenti
FOR EACH ROW
BEGIN
    DECLARE new_saldo DECIMAL(10, 2);

    UPDATE conti WHERE id = NEW.id_conto SET saldo = saldo - NEW.importo;

    SELECT saldo INTO new_saldo FROM conti WHERE id = NEW.id_conto;

    IF new_saldo < 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'SALDO INSUFFICENTE';
    END IF;
END;


/* 1 */
CREATE TRIGGER ordini
BEFORE INSERT ON ordini
FOR EACH ROW
BEGIN
    DECLARE ordine_count INT;

    SELECT COUNT(*) INTO ordine_count FROM ordini
    WHERE id_cliente = NEW.id_cliente AND stato_pagamento = 'non pagato';

    IF ordine_count >= 3 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'ORDINI MAX 3 NON PAGATI';
    END IF;

END;


/* 4 */
CREATE TRIGGER ordini
BEFORE INSERT ON ordini
FOR EACH ROW
BEGIN
    DECLARE num_ordini INT;

    SELECT COUNT(*) INTO num_ordini FROM ordini 
    WHERE id_cliente = NEW.id_cliente AND stato_ordine = 'in lavorazione';

    IF num_ordini >= 2 THEN
        SQLSTATE SIGNAL '45000'
        SET MESSAGE_TEXT = 'ORDINI MAX 2 IN LAVORAZIONE';
    END IF;
END;


/* 4 */
CREATE TRIGGER recensioni
BEFORE INSERT ON recensioni
FOR EACH ROW
BEGIN
    DECLARE num_rec INT;
    DECLARE id_cliente INT;

    SELECT COUNT(*) INTO num_rec FROM recensioni
    WHERE ordini.id_ordine = NEW.id_ordine

    IF num_rec > 0 THEN
        SQLSTATE SIGNAL '45000'
        SET MESSAGE_TEXT = 'RECENSIONE PER ORDINE GIA PRESENTE';
    ELSE
        SELECT id_cliente INTO id_cliente FROM ordini
        WHERE id_ordine = NEW.id_ordine;
    
        UPDATE clienti SET num_recensioni = num_recensioni + 1 WHERE id = id_cliente;
    
    END IF;
END;


/* 4 */
CREATE TRIGGER ordini
BEFORE INSERT ON ordini_dettagli
FOR EACH ROW
BEGIN
    DECLARE disp INT;

    SELECT quantita INTO disp FROM prodotti 
    WHERE id_prodotto = NEW.id_prodotto;

    IF disp < NEW.quantita THEN
        SQLSTATE SIGNAL '45000'
        SET MESSAGE_TEXT = 'QUANTITA PRODOTTO INSUFFICIENTE';
    ELSE
        UPDATE prodotti SET quantita = quantita - NEW.quantita 
        WHERE id_prodotto = NEW.id_prodotto;
    END IF;

END;


/* 4 */
CREATE TRIGGER spedizione
BEFORE INSERT ON spedizioni
FOR EACH ROW
BEGIN
    IF NEW.stato != 'spedito' THEN
        SET NEW.stato = 'spedito'
    ELSE
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'SPEDIZIONE GIA SPEDITA';
    END IF;
END;    


/* 2 */
CREATE TRIGGER block_order
BEFORE INSERT ON ordini
FOR EACH ROW
BEGIN
    DECLARE NumOrd INT;

    SELECT COUNT(*) INTO NumOrd FROM ordini 
    WHERE id_cliente = NEW.id_cliente AND stato = 'sospeso';

    IF NumOrd > 0 THEN
        SQLSTATE SIGNAL '45000'
        SET MESSAGE_TEXT = 'UN ORDINE GIA IN SOSPESO';
    END IF;
END;

/* 1 */
CREATE EVENT elimina_log_accessi
ON SCHEDULE EVERY 1 WEEK
DO
    DELETE FROM log_accessi WHERE data_accesso < NOW() - INTERVAL 90 DAY;


/* 2 */
CREATE EVENT scadenza_abbonamento
ON SCHEDULE EVERY 1 DAY AT 02:00:00
DO
    UPDATE abbonamento 
    SET stato = 'scaduto' WHERE data_scadenza <= NOW() AND stato = 'attivo';


/* 3 */
CREATE EVENT archivia
ON SCHEDULE EVERY 1 MONTH
DO
    INSERT INTO ordini_archivio(id_ordine, data_ordine, stato_ordine, totale_ordine)
    SELECT id_ordine, data_ordine, stato_ordine, totale_ordine FROM ordini WHERE data_ordine < NOW() - INTERVAL 6 MONTH AND stato_ordine = 'consegnato';

    DELETE FROM ordini WHERE data_ordine < NOW() - INTERVAL 6 MONTH AND stato_ordine = 'consegnato';


/* 4 */
CREATE EVENT crediti
ON SCHEDULE EVERY 1 YEAR 
STARTS '01-01 00:00:00'
DO
    UPDATE utente 
    SET credito = credito + 100;


/* 5 */
CREATE EVENT tentativi
ON SCHEDULE EVERY 1 DAY AT 00:00:00
DO
    UPDATE utenti
    SET tentativi = 0;


/* 1 */
CREATE EVENT statistiche
ON SCHEDULE EVERY 1 MONTH AT 00:00:00
DO
    UPDATE utenti_attivi
    SET statistiche_mesi = 0;


/* 2 */
CREATE EVENT notifiche
ON SCHEDULE EVERY 1 DAY AT 03:00:00
DO
    DELETE FROM notifiche WHERE data_notifica <= NOW() - INTERVAL 60 DAY;


/* 3 */
CREATE EVENT fatture
ON SCHEDULE EVERY 1 MONTH
DO
    INSERT INTO fatture_archiviate(id_fattura, data_fattura, totale_fattura)
    SELECT id_fattura, data_fattura, totale_fattura FROM fatture WHERE data_fattura <= NOW() - INTERVAL 1 YEAR AND stato_fattura = 'pagata';

    DELETE FROM fatture WHERE data_fattura <= NOW() - INTERVAL 1 YEAR AND stato_fattura = 'pagata';


/* 4 */
CREATE EVENT bonus
ON SCHEDULE EVERY 1 MONTH
DO
    UPDATE clienti
    SET crediti_bonus = crediti_bonus + 50 WHERE data_ultimo_ordine <= NOW() - INTERVAL 90 DAY;


/* 5 */
CREATE EVENT log_settimanali
ON SCHEDULE EVERY 1 WEEK AT 00:00:00
DO
    INSERT INTO log_settimanali(data_log, tipo_log, descrizione_log)
    SELECT data_log, tipo_log, descrizione_log FROM log_utenti WHERE data_log BETWEEN NOW() - INTERVAL 7 DAY AND NOW();

/* 1 */
CREATE EVENT log_access
ON SCHEDULE EVERY 1 WEEK
STARTS TIMESTAMP(CURRENT_DATE + INTERVAL 1 WEEK + INTERVAL '03:00:00' HOUR_SECOND)
DO 
    DELETE FROM log_accessi WHERE data_accesso <= NOW() - INTERVAL 90 DAY;


/* 1 */
CREATE EVENT archivia_fatture
ON SCHEDULE EVERY 1 MONTH
STARTS TIMESTAMP(INTERVAL '02:00:00' HOUR_SECOND)
DO
BEGIN

    INSERT INTO fatture_archiviate(id_fattura, data_fattura, totale_fattura, stato_fattura)
    SELECT id_fattura, data_fattura, totale_fattura, stato_fattura FROM fatture WHERE data_fattura <= NOW() - INTERVAL 1 YEAR AND stato_fattura = 'pagata';

    DELETE FROM fatture WHERE data_fattura <= NOW() - INTERVAL 1 YEAR AND stato_fattura = 'pagata';

END;


/* 5 */
CREATE EVENT archivia_prodotti
ON SCHEDULE EVERY 15 DAY
DO 
BEGIN
    INSERT INTO prodotti_archiviati(id_prodotto, nome_prodotto, prezzo, descrizione_prodotto, ultima_venduta)
    SELECT id_prodotto, nome_prodotto, prezzo, descrizione_prodotto, ultima_venduta FROM prodotti WHERE ultima_venduta <= NOW() - INTERVAL 6 MONTH;

    DELETE FROM prodotti WHERE ultima_venduta <= NOW() - INTERVAL 6 MONTH;
END;


/* 5 */
CREATE EVENT archivia_utenti
ON SCHEDULE EVERY 10 DAY
DO 
BEGIN 
    INSERT INTO utenti_archiviati(id_utente, nome_utente, cognome_utente, email_utente, ultima_attivita)
    SELECT id_utente, nome_utente, cognome_utente, email_utente, ultima_attivita 
    FROM utenti
    WHERE ultima_attivita <= NOW() - INTERVAL 180 DAY;

    DELETE FROM utenti WHERE ultima_attivita <= NOW() - INTERVAL 180 DAY;
END;


/* 5 */
CREATE EVENT premium
ON SCHEDULE EVERY 2 MONTH
DO
BEGIN
    UPDATE clienti SET stato_cliente = 'premium' 
    WHERE num_ordini >= 10 AND data_abbonamento BETWEEN NOW() - INTERVAL 6 MONTH AND NOW();
END;


/* 5 */
DELIMITER $$
CREATE EVENT notifiche
ON SCHEDULE EVERY 1 WEEK
DO
BEGIN
    DELETE FROM notifiche WHERE data_notifica <= NOW() - INTERVAL 30 DAY AND stato_notifica = 'letta';
END;
DELIMITER;

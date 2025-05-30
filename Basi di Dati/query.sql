SELECT nome FROM clienti
JOIN ordini ON clienti.id = ordini.id_cliente 
GROUP BY clienti.nome HAVING COUNT(*) >= 3;


SELECT nome FROM clienti
JOIN ordini ON clienti.id = ordini.id_cliente
GROUP BY clienti.nome HAVING SUM(ordini.tot_ordine) > (SELECT AVG(tot_ordine) FROM ordini);


SELECT nome FROM clienti 
JOIN ordini ON clienti.id = ordini.id_cliente
GROUP BY clienti.nome HAVING COUNT(*) > (SELECT AVG(num_ordini) FROM (SELECT COUNT(*) AS num_ordini FROM ordini GROUP BY id_cliente) AS t);


/**/
SELECT nome FROM clienti
JOIN ordini ON clienti.id = ordini.id_cliente
GROUP BY clienti.nome HAVING COUNT(*) > 5 AND SUM(tot_ordine) > 100;


SELECT nome_piatto, SUM(quantita) AS tot_quantita FROM ordini_dettagli
GROUP BY nome_piatto
ORDER BY tot_quantita DESC
LIMIT 3;


SELECT id_cliente, cliente.nome FROM clienti
LEFT JOIN ordini ON clienti.id = ordini.id_cliente
WHERE ordini.id_cliente IS NULL;


SELECT mese, anno, SUM(fatturato) AS tot_fatturato FROM archivio_fatture
GROUP BY mese, anno;


SELECT id_cliente, nome FROM clienti 
JOIN ordini ON clienti.id = ordini.id_cliente
WHERE data_ordine BETWEEN NOW() AND NOW() + INTERVAL 3 MONTH
GROUP BY id_cliente HAVING COUNT(*) > 3;


SELECT data_ordine FROM ordini 
JOIN clienti ON ordini.id_cliente = clienti.id
ORDER BY data_ordine DESC
LIMIT 1;


SELECT id_ordine FROM ordini
GROUP BY id_ordine
HAVING COUNT(DISTINCT id_prodotto) > 5;


SELECT id_cliente FROM clienti
JOIN ordini ON clienti.id = ordini.id_cliente
GROUP BY id_cliente
HAVING SUM(tot_ordine) > (SELECT AVG(tot_ordine) FROM ordini);


SELECT id_prodotto FROM prodotti
LEFT JOIN ordini_dettagli ON prodotti.id = ordini_dettagli.id_prodotto
WHERE ordini_dettagli.id_prodotto IS NULL


SELECT id_ordine FROM ordini
GROUP BY id_ordine
HAVING COUNT(sconto) > 0;


SELECT id_cliente, clienti.nome FROM clienti
JOIN ordini ON clienti.id = ordini.id_cliente
GROUP BY id_cliente
HAVING COUNT (ordini.id_ordine) > 5 AND SUM(ordini.tot_ordine) > 1000;


SELECT id_prodotto, SUM(quantita) AS tot_quantita FROM ordini_dettagli
GROUP BY id_prodotto
ORDER BY tot_quantita DESC
LIMIT 3;


SELECT * FROM ordini
GROUP BY id_ordine
HAVING COUNT(DISTINCT id_prodotto) > 5;

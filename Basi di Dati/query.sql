SELECT nome FROM clienti
JOIN ordini ON clienti.id = ordini.id_cliente 
GROUP BY clienti.nome HAVING COUNT(*) >= 3;


SELECT nome FROM clienti
JOIN ordini ON clienti.id = ordini.id_cliente
GROUP BY clienti.nome HAVING SUM(ordini.tot_ordine) > (SELECT AVG(tot_ordine) FROM ordini);

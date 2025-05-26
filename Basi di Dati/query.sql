SELECT nome FROM clienti
JOIN ordini ON clienti.id = ordini.id_cliente 
GROUP BY clienti.nome HAVING COUNT(*) > 3;
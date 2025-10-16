function trovaPercorsoBFS(grafo, nodoPartenza, nodoArrivo) {

  const coda = [[nodoPartenza, [nodoPartenza]]];
  const visitati = new Set([nodoPartenza]);

  while (coda.length > 0) {
    const [nodoCorrente, percorso] = coda.shift(); 

    if (nodoCorrente === nodoArrivo) {
      return percorso;
    }

    const vicini = grafo[nodoCorrente] || [];
    for (const vicino of vicini) {
      if (!visitati.has(vicino)) {
        visitati.add(vicino); 
        const nuovoPercorso = [...percorso, vicino];
        coda.push([vicino, nuovoPercorso]); 
      }
    }
  }

  return null;
}


const mioGrafo = {
  'A': ['B', 'C'],
  'B': ['A', 'D', 'E'],
  'C': ['A', 'F'],
  'D': ['B'],
  'E': ['B', 'F'],
  'F': ['C', 'E', 'G'],
  'G': ['F']
};


const partenza = 'A';
const arrivo = 'F';

const percorso = trovaPercorsoBFS(mioGrafo, partenza, arrivo);

if (percorso) {
  console.log(`Il percorso più breve da ${partenza} a ${arrivo} è: ${percorso.join(' -> ')}`);
} else {
  console.log(`Non è stato trovato alcun percorso da ${partenza} a ${arrivo}.`);
}

const arrivoInesistente = 'H';
const percorsoInesistente = trovaPercorsoBFS(mioGrafo, partenza, arrivoInesistente);

if (percorsoInesistente) {
  console.log(`Il percorso più breve da ${partenza} a ${arrivoInesistente} è: ${percorsoInesistente.join(' -> ')}`);
} else {
  console.log(`Non è stato trovato alcun percorso da ${partenza} a ${arrivoInesistente}.`);
}
function trovaPercorsoBFS(
    grafo: Record<string, string[]>, 
    nodoPartenza: string, 
    nodoArrivo: string
): string[] | null {
    const coda: [string, string[]][] = [[nodoPartenza, [nodoPartenza]]];
    const visitati: Set<string> = new Set([nodoPartenza]);
    
    while (coda.length > 0) {
        const [nodoCorrente, percorso] = coda.shift()!;

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


const mioGrafo: Record<string, string[]> = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E', 'G'],
    'G': ['F']
};

const partenza = 'A';
const arrivo = 'G';

const percorso = trovaPercorsoBFS(mioGrafo, partenza, arrivo);

if (percorso) {
    console.log(`Percorso trovato: ${percorso.join(' -> ')}`);
} else {
    console.log(`Nessun percorso trovato da ${partenza} a ${arrivo}.`);
}
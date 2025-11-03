package org.example.ristorante.model;

import java.util.*;

public class RistoranteDTO {
    private final long id;
    private final String nome;
    private final int numDip;
    private final List<PiattoDTO> piatti = new ArrayList<>();

    public RistoranteDTO(long id, String n, int numD, List<PiattoDTO> p) {
        this.id = id;
        this.nome = n;
        this.numDip = numD;
        this.piatti.addAll(p);
    }

    public long getId() {
        return id;
    }
    public String getNome() {
        return nome;
    }
    public int getNumDip() {
        return numDip;
    }
    public List<PiattoDTO> getPiatti() { return piatti; }
}

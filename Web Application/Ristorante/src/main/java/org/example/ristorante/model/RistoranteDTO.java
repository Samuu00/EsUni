package org.example.ristorante.model;

import java.util.*;

public class RistoranteDTO {
    private final long id;
    private final String nome;
    private final int numDip;
    private final List<PiattoDTO> piatti = new ArrayList<>();

    public RistoranteDTO(long id, String n, int numD) {
        this.id = id;
        this.nome = n;
        this.numDip = numD;
    }

    long getId() {
        return id;
    }
    String getNome() {
        return nome;
    }
    int getNumDip() {
        return numDip;
    }
}

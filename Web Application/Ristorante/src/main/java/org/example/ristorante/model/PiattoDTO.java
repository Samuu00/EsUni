package org.example.ristorante.model;

public class PiattoDTO {
    private final long id;
    private final String nome;
    private final double prezzo;

    public PiattoDTO(long id, String n, double p) {
        this.id = id;
        this.nome = n;
        this.prezzo = p;
    }

    public long getId() {
        return id;
    }
    public String getNome() {
        return nome;
    }
    public double getPrezzo() {
        return prezzo;
    }
}

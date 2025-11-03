package org.example.ristorante.model;

public class IngredientiDTO {
    private final long id;
    private final String nome;

    public IngredientiDTO(String n) {
        this.id = 0;
        this.nome = n;
    }

    public IngredientiDTO(long id, String n) {
        this.id = id;
        this.nome = n;
    }

    public long getId() { return id; }
    public String getNome() { return nome; }
}
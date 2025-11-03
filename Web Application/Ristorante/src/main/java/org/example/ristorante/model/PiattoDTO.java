package org.example.ristorante.model;

import java.util.*;

public class PiattoDTO {
    private final long id;
    private final String nome;
    private final double prezzo;
    private final List<IngredientiDTO> ingredienti = new ArrayList<>();

    public PiattoDTO(long id, String n, double p, ArrayList<IngredientiDTO> ing) {
        this.id = id;
        this.nome = n;
        this.prezzo = p;
        if (ing != null) {
            this.ingredienti.addAll(ing);
        }
    }

    public long getId() { return id; }
    public String getNome() { return nome; }
    public double getPrezzo() { return prezzo; }
    public List<IngredientiDTO> getIngredienti() { return ingredienti; }
}
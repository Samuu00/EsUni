package Veicolo;
abstract class Veicolo {
    private String modello, marca;
    private int annoProd;

    public Veicolo(String ma, String mo, int ap) {
        this.marca = ma;
        this.modello = mo;
        this.annoProd = ap;
    }
    @Override
    public String toString() {
        return "Veicolo:[Marca: " + marca + " - Modello: " + modello + " - Anno: " + annoProd + "]";
    }

    void setMarca(String ma) {
        marca = ma;
    }

    void setModello(String mo) {
        modello = mo;
    }

    void setAnnoProd(int ap) {
        annoProd = ap;
    }

    String getMarca() {
        return marca;
    }

    String getModello() {
        return modello;
    }

    int getAnnoProd() {
        return annoProd;
    }

    public abstract void Viaggia(Percorribile p);
}

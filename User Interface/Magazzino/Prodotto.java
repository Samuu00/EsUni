package Magazzino;
public final class Prodotto {
    private String idProdotto, tipologia, marca, modello;
    private int annoProd;
    private double prezzo;

    public Prodotto(String id, String tip, String ma, String mo, int ap, double pr){
        this.idProdotto = id;
        this.tipologia = tip;
        this.marca = ma;
        this.modello = mo;
        this.annoProd = ap;
        this.prezzo = pr;
    }

    public void setIdProdotto(String idProdotto) {
        this.idProdotto = idProdotto;
    }
    public void setTipologia(String tipologia) {
        this.tipologia = tipologia;
    }
    public void setMarca(String marca) {
        this.marca = marca;
    }
    public void setModello(String modello) {
        this.modello = modello;
    }
    public void setAnnoProd(int annoProd) {
        this.annoProd = annoProd;
    }
    public void setPrezzo(double prezzo) {
        this.prezzo = prezzo;
    }

    public String getIdProdotto() {
        return idProdotto;
    }
    public String getTipologia() {
        return tipologia;
    }
    public String getMarca() {
        return marca;
    }
    public String getModello() {
        return modello;
    }
    public int getAnnoProd() {
        return annoProd;
    }
    public double getPrezzo() {
        return prezzo;
    }

    @Override
    public String toString() {
        return "Prodotto: [" + getIdProdotto() + ", " + getTipologia() + ", " + getMarca() + ", " + getModello() + ", " + getAnnoProd() + ", " + getPrezzo() + "]\n";
    }
}

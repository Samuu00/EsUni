package Veicolo;
public class Auto extends Veicolo {
    private int numeroPorte;

    public Auto(String marca, String modello, int annoProd, int numeroPorte) {
        super(marca, modello, annoProd);
        this.numeroPorte = numeroPorte;
    }
    @Override
    public String toString() {
        return "Auto:[Marca: " + getMarca() + " - Modello: " + getModello() + " - Anno: " + getAnnoProd() + " - Numero porte: " + numeroPorte + "]";
    }

    public void Viaggia(Percorribile p){
        System.out.println("Sono una macchina e sto transitando");
    }

    void setNumeroPorte(int np) {
        numeroPorte = np;
    }

    int getNumeroPorte() {
        return numeroPorte;
    }
}

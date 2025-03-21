package Veicolo;
class Moto extends Veicolo{
    private boolean haSideCare;
    private int cc;
    public Moto(String marca, String modello, int annoProd, int cc, boolean haSideCare){
        super(marca, modello, annoProd);
        this.haSideCare = haSideCare;
        this.cc = cc;
    }

    @Override
    public String toString() {
        return "Moto:[Marca: " + getMarca() + " - Modello: " + getModello() + " - Anno: " + getAnnoProd() + " - Ha side care: " + haSideCare + "]";
    }

    public void Viaggia(Percorribile p) {
        if (cc < p.getCilindrataMinima()) {  // Ora controlliamo correttamente la cilindrata minima
            System.out.println("Sono una moto di " + cc + "cc e NON posso transitare su questa strada.");
        } else {
            System.out.println("Sono una moto di " + cc + "cc e POSSO transitare su questa strada.");
        }
    }
}
package Calcolatrice;

public abstract class Operazioni {
    private double termineSinistro;
    private double termineDestro;

    protected Operazioni(double termineSinistro, double termineDestro) {
        this.termineSinistro = termineSinistro;
        this.termineDestro = termineDestro;
    }

    public double getTermineSinistro() {
        return termineSinistro;
    }
    public double getTermineDestro() {
        return termineDestro;
    }
    public abstract double Calcola();
}

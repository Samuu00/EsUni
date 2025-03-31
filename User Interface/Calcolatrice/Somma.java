package Calcolatrice;

public class Somma extends Operazioni{
    protected Somma(double termineSinistro, double termineDestro) {
        super(termineSinistro, termineDestro);
    }
    @Override
    public double Calcola(){
        return getTermineSinistro() + getTermineDestro();
    }
}

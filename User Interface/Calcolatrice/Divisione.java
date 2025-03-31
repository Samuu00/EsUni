package Calcolatrice;

public class Divisione extends Operazioni {
    protected Divisione(double termineSinistro, double termineDestro) {
        super(termineSinistro, termineDestro);
    }
    @Override
    public double Calcola() {
        if (getTermineDestro() == 0) {
            throw new ArithmeticException("Divisione per zero non consentita");
        }else{
            return getTermineSinistro() / getTermineDestro();
        }
    }
}

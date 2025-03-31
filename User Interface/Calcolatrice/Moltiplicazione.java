package Calcolatrice;

public class Moltiplicazione extends Operazioni {
    protected Moltiplicazione(double termineSinistro, double termineDestro){
        super(termineSinistro, termineDestro);
    }

    @Override
    public double Calcola(){
        return getTermineSinistro() * getTermineDestro();
    }
}

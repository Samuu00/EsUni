package Calcolatrice;

public class Sottrazione extends Operazioni {
    protected Sottrazione(double termineSinistro, double termineDestro){

        super(termineSinistro, termineDestro);
    }
    @Override
    public double Calcola(){
        return getTermineSinistro() - getTermineDestro();
    }
}

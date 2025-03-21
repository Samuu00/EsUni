package Veicolo;

public abstract class Stradasecondaria implements Percorribile {
    @Override
    public int getCilindrataMinima() {
        return 0;
    }
    @Override
    public int getVelocitaMasima() {
        return 70;
    }
}

package Veicolo;

public abstract class  Autostrada implements Percorribile {
    @Override
    public int getCilindrataMinima() {
        return 150;
    }
    @Override
    public int getVelocitaMasima() {
        return 130;
    }
}
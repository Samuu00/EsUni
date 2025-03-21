package Magazzino;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;

public class Magazzino {
    private List<Prodotto> prodotti;

    public Magazzino(){
        this.prodotti = new ArrayList<>();
    }

    public void aggiungiProdotti(String id, String tip, String ma, String mo, int ap, double pre) {
        for (Prodotto prodotto : prodotti) {
            if (prodotto.getIdProdotto().equals(id)) {
                System.out.println("ID prodotto esistente, riprova\n");
                return;
            }
        }
        prodotti.add(new Prodotto(id, tip, ma, mo, ap, pre));
    }

    public void rimuoviProdotti(String id){
        Iterator<Prodotto> iterator = prodotti.iterator();
        while(iterator.hasNext()){
            Prodotto prodotto = iterator.next();
            if(prodotto.getIdProdotto().equals(id)){
                iterator.remove();
                System.out.println("Prodotto con ID: "+ id + " rimosso");
                return;
            }
        }
        System.out.println("Prodotto con ID: "+ id + " non trovato");
    }
    public void cercaPerMarca(String ma){
        for(Prodotto prodotto : prodotti){
            if(prodotto.getMarca().equals(ma)){
                System.out.println(prodotto);
            }
        }
    }
    public void cercaPerModello(String mo){
        for(Prodotto prodotto : prodotti){
            if(prodotto.getModello().equals(mo)){
                System.out.println(prodotto);
            }
        }
    }
    public void cercaPerTipologia(String tip){
        for(Prodotto prodotto : prodotti){
            if(prodotto.getTipologia().equals(tip)){
                System.out.println(prodotto);
            }
        }
    }
    public void prezzoCrescente(){
        Collections.sort(prodotti, Comparator.comparingDouble(Prodotto::getPrezzo));
        for(Prodotto p : prodotti) {
            System.out.println(p);
        }
    }
    public void prezzoDecrescente() {
        Collections.sort(prodotti, Comparator.comparingDouble(Prodotto::getPrezzo).reversed());
        for (Prodotto p : prodotti) {
            System.out.println(p);
        }
    }

}

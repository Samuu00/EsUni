package org.example.ristorante.controller;

import org.example.ristorante.DAO.RistoranteDAO;
import org.example.ristorante.model.PiattoDTO;
import org.example.ristorante.model.RistoranteDTO;
import org.springframework.web.bind.annotation.*; 
import java.util.*;

@RestController
@RequestMapping("/ristorante")
public class RistoranteController {

    private RistoranteDAO getDao() {
        return new RistoranteDAO(DBconnection.getInstance().getConn());
    }

    @PostMapping("/")
    public RistoranteDTO addRistorante(@RequestBody RistoranteDTO ristorante) {

        RistoranteDAO dao = getDao();
        RistoranteDTO nuovoRistorante = new RistoranteDTO(
                0,
                ristorante.getNome(),
                ristorante.getNumDip(),
                ristorante.getPiatti()
        );

        dao.insertRistorante(nuovoRistorante);
        return dao.getRistoranteByNome(nuovoRistorante.getNome());
    }

    @GetMapping("/")
    public ArrayList<RistoranteDTO> getAllRistoranti() {
        return (ArrayList<RistoranteDTO>) getDao().getAllRistoranti();
    }

    @GetMapping("/{id}")
    public RistoranteDTO getRistoranteById(@PathVariable long id) {
        return getDao().getRistoranteById(id);
    }

    @GetMapping("/byNome")
    public RistoranteDTO getRistoranteByNome(@RequestParam String nome) {
        return getDao().getRistoranteByNome(nome);
    }

    @DeleteMapping("/{nome}")
    public void deleteRistorante(@PathVariable String nome) {
        getDao().deleteRistorante(nome);
    }
}
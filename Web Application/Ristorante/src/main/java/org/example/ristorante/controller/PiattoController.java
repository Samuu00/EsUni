package org.example.ristorante.controller;

import org.example.ristorante.DAO.PiattoDAO;
import org.example.ristorante.model.PiattoDTO;
import org.springframework.web.bind.annotation.*;

import java.util.*;

@RestController
@RequestMapping("/piatto")
public class PiattoController {

    @PostMapping("/")
    PiattoDTO addPiatto(@RequestBody PiattoDTO newPiatto){
        PiattoDAO dao = new PiattoDAO(DBconnection.getInstance().getConn());
        dao.insertPiatto(newPiatto);
        return dao.getPiattoByNome(newPiatto.getNome());
    }

    @GetMapping("/")
    ArrayList<PiattoDTO> getPiatti(){
        PiattoDAO dao = new PiattoDAO(DBconnection.getInstance().getConn());
        return dao.getPiatti();
    }

    @GetMapping("/{id}")
    PiattoDTO getPiattoById(@PathVariable long id){
        PiattoDAO dao = new PiattoDAO(DBconnection.getInstance().getConn());
        return dao.getPiattoById(id);
    }

    @GetMapping("/byNome")
    PiattoDTO getPiattoByNome(@RequestParam String nome){
        PiattoDAO dao = new PiattoDAO(DBconnection.getInstance().getConn());
        return dao.getPiattoByNome(nome);
    }

    @DeleteMapping("/")
    void deletePiatto(@RequestParam String nome){
        PiattoDAO dao = new PiattoDAO(DBconnection.getInstance().getConn());
        dao.deletePiatto(nome);
    }
}
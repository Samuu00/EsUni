package org.example.ristorante.controller;

import org.example.ristorante.DAO.PiattoDAO;
import org.example.ristorante.model.PiattoDTO;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;


@RestController
@RequestMapping("/piatto")
public class PiattoController {

    @PostMapping("/")
    PiattoDTO addPiatto(@RequestParam String nome, @RequestParam double prezzo){
        PiattoDAO dao = new PiattoDAO(DBconnection.getInstance().getConn());

        PiattoDTO newPiatto = new PiattoDTO(0, nome, prezzo);

        dao.insertPiatto(newPiatto);

        return dao.getPiattoByNome(nome);
    }
}
package it.unical.rest;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/rest")
public class apiStudentForm {

    @PostMapping("/apiStudentForm")
    public ResponseEntity<Void> postForm(
            @RequestParam String nome,
            @RequestParam String cognome,
            @RequestParam String email,
            @RequestParam String telefono,
            @RequestParam String indirizzo,
            @RequestParam String dataNascita,
            @RequestParam String sesso) {

        System.out.println(
                "nome: " + nome
                + " cognome: " + cognome
                + " email: " + email
                + " telefono: " + telefono
                + " indirizzo: " + indirizzo
                + " dataNascita: " + dataNascita
                + " sesso: " + sesso
        );
        
        return ResponseEntity.status(200).build();
    }
}

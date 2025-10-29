package it.unical.wa.ex_js.rest;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/api")
public class StudentFormController {



    @RequestMapping("/studentForm")
    public ResponseEntity<Void> postForm(
            @RequestParam("nome") String nome,
            @RequestParam("cognome") String cognome,
            @RequestParam("corso") String corso,
            @RequestParam("email") String email,
            @RequestParam("telefono") String telefono,
            @RequestParam(required = false, name="esame") List<String> esame,
            @RequestParam(required = false , name = "voto") List<String> voto
    ) {



        System.out.println(
                "Nome: " + nome +
                " Cognome: " + cognome +

                " email: " + email +
                " corso: " + corso +
                " telefono: " + telefono
        );


        if(esame==null || esame.isEmpty() || voto==null || voto.isEmpty()){
            System.out.println("nessun esame");
            return ResponseEntity.status(200).build();
        }

        System.out.println("Esami: ");
        for (int i = 0; i < esame.size(); i++) {
            System.out.println(esame.get(i) +" "+ voto.get(i));
        }

        return ResponseEntity.status(HttpStatus.FOUND)
                .header("Location", "http://localhost:8080/index.html")
                .build();
    }
}

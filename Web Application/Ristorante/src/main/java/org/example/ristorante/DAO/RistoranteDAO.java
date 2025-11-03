package org.example.ristorante.DAO;

import org.example.ristorante.controller.DBconnection;
import org.example.ristorante.model.RistoranteDTO;
import java.sql.*;
import java.util.*;

public class RistoranteDAO {

    Connection conn;
    public RistoranteDAO(Connection conn){
        this.conn = conn;
    }

    public void insertRistorante(){
        String q = "INSERT INTO Ristoranti VALUES (null, ?, ?)";
        try(PreparedStatement statement = conn.prepareStatement(q)){

            statement.setString(1, "risto");
            statement.setInt(2, 10);
            statement.executeUpdate();

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public RistoranteDTO getRistoranteById(long id){}

    public RistoranteDTO getRistoranteByNome(String nome){}

    public List<RistoranteDTO> getAllRistoranti(){
        String q = "SELECT * FROM Ristoranti";
        List<RistoranteDTO> ris = new ArrayList<>();
        try(PreparedStatement statement = conn.prepareStatement(q)){
            ResultSet rs = statement.executeQuery();
            while(rs.next()){
                ris.add(new RistoranteDTO(rs.getLong("id"), rs.getString("nome"), rs.getInt("numDip")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return ris;
    }
}

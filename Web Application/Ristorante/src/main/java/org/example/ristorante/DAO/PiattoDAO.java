package org.example.ristorante.DAO;

import org.example.ristorante.model.PiattoDTO;

import java.sql.*;
import java.util.*;

public class PiattoDAO{

    Connection conn;

    public PiattoDAO(Connection conn){
        this.conn = conn;
    }

    public void insertPiatto(PiattoDTO p){
        String q = "INSERT into Piatti VALUES (null, ?, ?)";
        try(PreparedStatement statement = conn.prepareStatement(q)){
            statement.setString(1, p.getNome());
            statement.setDouble(2, p.getPrezzo());

            ResultSet rs = statement.executeQuery();

            if(rs.next()) System.out.println("Piatto inserito con id: " + rs.getLong(1));
            else System.out.println("Errore durante l'inserimento del piatto");

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public ArrayList<PiattoDTO> getPiatti(){
        ArrayList<PiattoDTO> piatti = new ArrayList<>();
        String q = "SELECT * FROM Piatti";

        try(PreparedStatement statement = conn.prepareStatement(q)){

            ResultSet rs = statement.executeQuery();
            while(rs.next()){
                piatti.add(new PiattoDTO(rs.getLong(1), rs.getString(2), rs.getDouble(3)));
            }
            return piatti;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public PiattoDTO getPiattoByNome(String nome){
        String q = "SELECT * FROM Piatti WHERE nome = ?";
        try(PreparedStatement statement = conn.prepareStatement(q)){
            statement.setString(1, nome);

            ResultSet rs = statement.executeQuery();
            if(rs.next()) return new PiattoDTO(rs.getLong(1), rs.getString(2), rs.getDouble(3));
            else return null;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public PiattoDTO getPiattoById(long id){
        String q = "SELECT * FROM Piatti WHERE id = ?";
        try(PreparedStatement statement = conn.prepareStatement(q)){
            statement.setLong(1, id);

            ResultSet rs = statement.executeQuery();
            if(rs.next()) return new PiattoDTO(rs.getLong(1), rs.getString(2), rs.getDouble(3));
            else return null;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void deletePiatto(String nome){
        String q = "DELETE FROM Piatti WHERE nome = ?";
        try(PreparedStatement statement = conn.prepareStatement(q)){
            statement.setString(1, nome);

            statement.executeUpdate();
            System.out.println("Piatto eliminato");

        } catch (SQLException e) {}
    }
}

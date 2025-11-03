package org.example.ristorante.DAO;

import org.example.ristorante.model.IngredientiDTO;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class IngredientiDAO {

    private Connection conn;

    public IngredientiDAO(Connection conn) {
        this.conn = conn;
    }

    public IngredientiDTO insertIngrediente(IngredientiDTO ing) {
        String q = "INSERT INTO Ingredienti (nome) VALUES (?) RETURNING id";
        try (PreparedStatement statement = conn.prepareStatement(q)) {

            statement.setString(1, ing.getNome());

            ResultSet rs = statement.executeQuery();

            if (rs.next()) {
                long nuovoId = rs.getLong(1);
                System.out.println("Ingrediente inserito con id: " + nuovoId);
                return new IngredientiDTO(nuovoId, ing.getNome());
            } else {
                throw new SQLException("Errore durante l'inserimento dell'ingrediente, nessun ID ottenuto.");
            }

        } catch (SQLException e) {

            if (e.getSQLState().equals("23505")) {
                System.err.println("Errore: Ingrediente con nome '" + ing.getNome() + "' esiste già.");
                return getIngredienteByNome(ing.getNome());
            }
            throw new RuntimeException(e);
        }
    }

    public IngredientiDTO getIngredienteById(long id) {
        String q = "SELECT * FROM Ingredienti WHERE id = ?";
        try (PreparedStatement statement = conn.prepareStatement(q)) {

            statement.setLong(1, id);
            ResultSet rs = statement.executeQuery();

            if (rs.next()) {
                return new IngredientiDTO(rs.getLong("id"), rs.getString("nome"));
            } else {
                return null;
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public IngredientiDTO getIngredienteByNome(String nome) {
        String q = "SELECT * FROM Ingredienti WHERE nome = ?";
        try (PreparedStatement statement = conn.prepareStatement(q)) {

            statement.setString(1, nome);
            ResultSet rs = statement.executeQuery();

            if (rs.next()) {
                return new IngredientiDTO(rs.getLong("id"), rs.getString("nome"));
            } else {
                return null;
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public List<IngredientiDTO> getAllIngredienti() {
        List<IngredientiDTO> ingredienti = new ArrayList<>();
        String q = "SELECT * FROM Ingredienti";
        try (PreparedStatement statement = conn.prepareStatement(q)) {

            ResultSet rs = statement.executeQuery();
            while (rs.next()) {
                ingredienti.add(new IngredientiDTO(rs.getLong("id"), rs.getString("nome")));
            }
            return ingredienti;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void deleteIngrediente(String nome) {
        String q = "DELETE FROM Ingredienti WHERE nome = ?";
        try (PreparedStatement statement = conn.prepareStatement(q)) {

            statement.setString(1, nome);
            int rowsAffected = statement.executeUpdate();

            if (rowsAffected > 0) {
                System.out.println("Ingrediente eliminato: " + nome);
            } else {
                System.out.println("Nessun ingrediente trovato con nome: " + nome);
            }

        } catch (SQLException e) {
            if (e.getSQLState().equals("23503")) {
                System.err.println("Errore: Impossibile eliminare '" + nome + "' perché è usato in una ricetta.");
            } else {
                throw new RuntimeException(e);
            }
        }
    }
}
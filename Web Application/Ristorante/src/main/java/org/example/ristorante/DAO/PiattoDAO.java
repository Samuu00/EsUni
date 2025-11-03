package org.example.ristorante.DAO;

import org.example.ristorante.model.PiattoDTO;
import org.example.ristorante.model.IngredientiDTO;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class PiattoDAO {

    private Connection conn;
    private IngredientiDAO ingredientiDAO;

    public PiattoDAO(Connection conn) {
        this.conn = conn;
        this.ingredientiDAO = new IngredientiDAO(conn);
    }

    public void insertPiatto(PiattoDTO p) {
        String qPiatto = "INSERT INTO Piatti (nome, prezzo) VALUES (?, ?) RETURNING id";
        long nuovoPiattoId = 0;

        try {

            try (PreparedStatement statementPiatto = conn.prepareStatement(qPiatto)) {
                statementPiatto.setString(1, p.getNome());
                statementPiatto.setDouble(2, p.getPrezzo());

                ResultSet rs = statementPiatto.executeQuery();
                if (rs.next()) {
                    nuovoPiattoId = rs.getLong(1);
                } else {
                    throw new SQLException("Creazione piatto fallita, nessun ID ottenuto.");
                }
            }

            String qRicetta = "INSERT INTO Ricette (piatto_id, ingrediente_id) VALUES (?, ?)";
            try (PreparedStatement statementRicetta = conn.prepareStatement(qRicetta)) {

                for (IngredientiDTO ing : p.getIngredienti()) {
                    IngredientiDTO ingConId = ingredientiDAO.getIngredienteByNome(ing.getNome());

                    if (ingConId == null) {
                        throw new SQLException("Ingrediente non trovato nel DB: " + ing.getNome());
                    }

                    long ingredienteId = ingConId.getId();

                    statementRicetta.setLong(1, nuovoPiattoId);
                    statementRicetta.setLong(2, ingredienteId);
                    statementRicetta.addBatch();
                }
                statementRicetta.executeBatch();
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public ArrayList<PiattoDTO> getPiatti() {
        ArrayList<PiattoDTO> piatti = new ArrayList<>();
        String q = "SELECT * FROM Piatti";

        try (PreparedStatement statement = conn.prepareStatement(q)) {
            ResultSet rs = statement.executeQuery();
            while (rs.next()) {
                long piattoId = rs.getLong("id");
                String nome = rs.getString("nome");
                double prezzo = rs.getDouble("prezzo");

                ArrayList<IngredientiDTO> ingredienti = getIngredientiPerPiatto(piattoId);

                piatti.add(new PiattoDTO(piattoId, nome, prezzo, ingredienti));
            }
            return piatti;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private ArrayList<IngredientiDTO> getIngredientiPerPiatto(long piattoId) {
        ArrayList<IngredientiDTO> ingredienti = new ArrayList<>();
        String q = "SELECT i.id, i.nome FROM Ingredienti i " +
                "JOIN Ricette r ON i.id = r.ingrediente_id " +
                "WHERE r.piatto_id = ?";

        try (PreparedStatement ps = conn.prepareStatement(q)) {
            ps.setLong(1, piattoId);
            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                ingredienti.add(new IngredientiDTO(rs.getLong("id"), rs.getString("nome")));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return ingredienti;
    }

    public PiattoDTO getPiattoByNome(String nome) {
        String q = "SELECT p.id as p_id, p.nome as p_nome, p.prezzo, i.id as i_id, i.nome as i_nome " +
                "FROM Piatti p " +
                "LEFT JOIN Ricette r ON p.id = r.piatto_id " +
                "LEFT JOIN Ingredienti i ON r.ingrediente_id = i.id " +
                "WHERE p.nome = ?";

        PiattoDTO piatto = null;
        List<IngredientiDTO> ingredienti = new ArrayList<>();
        long piattoId = 0;
        String piattoNome = null;
        double piattoPrezzo = 0;
        boolean piattoTrovato = false;

        try (PreparedStatement statement = conn.prepareStatement(q)) {
            statement.setString(1, nome);
            ResultSet rs = statement.executeQuery();

            while (rs.next()) {
                piattoTrovato = true;
                if (piattoId == 0) {
                    piattoId = rs.getLong("p_id");
                    piattoNome = rs.getString("p_nome");
                    piattoPrezzo = rs.getDouble("prezzo");
                }

                long ingId = rs.getLong("i_id");
                if (!rs.wasNull()) {
                    ingredienti.add(new IngredientiDTO(ingId, rs.getString("i_nome")));
                }
            }

            if (piattoTrovato) {
                piatto = new PiattoDTO(piattoId, piattoNome, piattoPrezzo, (ArrayList<IngredientiDTO>) ingredienti);
            }

            return piatto;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public PiattoDTO getPiattoById(long id) {
        String q = "SELECT p.id as p_id, p.nome as p_nome, p.prezzo, i.id as i_id, i.nome as i_nome " +
                "FROM Piatti p " +
                "LEFT JOIN Ricette r ON p.id = r.piatto_id " +
                "LEFT JOIN Ingredienti i ON r.ingrediente_id = i.id " +
                "WHERE p.id = ?";

        PiattoDTO piatto = null;
        List<IngredientiDTO> ingredienti = new ArrayList<>();
        long piattoId = 0;
        String piattoNome = null;
        double piattoPrezzo = 0;
        boolean piattoTrovato = false;

        try (PreparedStatement statement = conn.prepareStatement(q)) {
            statement.setLong(1, id);
            ResultSet rs = statement.executeQuery();

            while (rs.next()) {
                piattoTrovato = true;
                if (piattoId == 0) {
                    piattoId = rs.getLong("p_id");
                    piattoNome = rs.getString("p_nome");
                    piattoPrezzo = rs.getDouble("prezzo");
                }
                long ingId = rs.getLong("i_id");
                if (!rs.wasNull()) {
                    ingredienti.add(new IngredientiDTO(ingId, rs.getString("i_nome")));
                }
            }

            if (piattoTrovato) {
                piatto = new PiattoDTO(piattoId, piattoNome, piattoPrezzo, (ArrayList<IngredientiDTO>) ingredienti);
            }

            return piatto;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void deletePiatto(String nome) {
        long piattoId = 0;
        String qId = "SELECT id FROM Piatti WHERE nome = ?";
        try (PreparedStatement psId = conn.prepareStatement(qId)) {
            psId.setString(1, nome);
            ResultSet rs = psId.executeQuery();
            if (rs.next()) {
                piattoId = rs.getLong("id");
            } else {
                System.out.println("Piatto non trovato: " + nome);
                return;
            }
        } catch (SQLException e) {
            throw new RuntimeException("Errore nel recupero ID piatto", e);
        }

        try {
            conn.setAutoCommit(false);

            String qRicette = "DELETE FROM Ricette WHERE piatto_id = ?";
            try (PreparedStatement psRicette = conn.prepareStatement(qRicette)) {
                psRicette.setLong(1, piattoId);
                psRicette.executeUpdate();
            }

            String qMenu = "DELETE FROM Menu WHERE piatto_id = ?";
            try (PreparedStatement psMenu = conn.prepareStatement(qMenu)) {
                psMenu.setLong(1, piattoId);
                psMenu.executeUpdate();
            }

            String qPiatto = "DELETE FROM Piatti WHERE id = ?";
            try (PreparedStatement psPiatto = conn.prepareStatement(qPiatto)) {
                psPiatto.setLong(1, piattoId);
                int rowsAffected = psPiatto.executeUpdate();
                if (rowsAffected > 0) {
                    System.out.println("Piatto eliminato: " + nome);
                }
            }

            conn.commit();

        } catch (SQLException e) {
            try {
                conn.rollback();
            } catch (SQLException ex) {
                throw new RuntimeException("Errore durante il rollback", ex);
            }
            throw new RuntimeException("Errore durante l'eliminazione del piatto", e);
        } finally {
            try {
                conn.setAutoCommit(true);
            } catch (SQLException e) {
                throw new RuntimeException("Errore nel ripristino autocommit", e);
            }
        }
    }
}
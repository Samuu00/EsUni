package org.example.ristorante.DAO;

import org.example.ristorante.model.PiattoDTO;
import org.example.ristorante.model.RistoranteDTO;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class RistoranteDAO {

    private Connection conn;
    private PiattoDAO piattoDAO;

    public RistoranteDAO(Connection conn) {
        this.conn = conn;
        this.piattoDAO = new PiattoDAO(conn);
    }

    public void insertRistorante(RistoranteDTO r) {
        String qRistorante = "INSERT INTO Ristoranti (nome, numDip) VALUES (?, ?) RETURNING id";
        long nuovoRistoranteId = 0;

        try {

            try (PreparedStatement statementRist = conn.prepareStatement(qRistorante)) {
                statementRist.setString(1, r.getNome());
                statementRist.setInt(2, r.getNumDip());

                ResultSet rs = statementRist.executeQuery();
                if (rs.next()) {
                    nuovoRistoranteId = rs.getLong(1);
                } else {
                    throw new SQLException("Creazione ristorante fallita, nessun ID ottenuto.");
                }
            }

            String qMenu = "INSERT INTO Menu (ristorante_id, piatto_id) VALUES (?, ?)";
            try (PreparedStatement statementMenu = conn.prepareStatement(qMenu)) {
                for (PiattoDTO p : r.getPiatti()) {
                    if (p.getId() == 0) {
                        throw new SQLException("PiattoDTO fornito senza un ID valido: " + p.getNome());
                    }
                    statementMenu.setLong(1, nuovoRistoranteId);
                    statementMenu.setLong(2, p.getId());
                    statementMenu.addBatch();
                }
                statementMenu.executeBatch();
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private ArrayList<PiattoDTO> getPiattiPerRistorante(long ristoranteId) throws SQLException {
        ArrayList<PiattoDTO> piatti = new ArrayList<>();
        String q = "SELECT piatto_id FROM Menu WHERE ristorante_id = ?";

        try (PreparedStatement ps = conn.prepareStatement(q)) {
            ps.setLong(1, ristoranteId);
            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                long piattoId = rs.getLong("piatto_id");
                PiattoDTO piatto = piattoDAO.getPiattoById(piattoId);
                if (piatto != null) {
                    piatti.add(piatto);
                }
            }
        }
        return piatti;
    }

    public RistoranteDTO getRistoranteById(long id) {
        String q = "SELECT * FROM Ristoranti WHERE id = ?";
        try (PreparedStatement statement = conn.prepareStatement(q)) {
            statement.setLong(1, id);
            ResultSet rs = statement.executeQuery();

            if (rs.next()) {
                long ristoranteId = rs.getLong("id");
                String nome = rs.getString("nome");
                int numDip = rs.getInt("numDip");

                ArrayList<PiattoDTO> piatti = getPiattiPerRistorante(ristoranteId);

                return new RistoranteDTO(ristoranteId, nome, numDip, piatti);
            } else {
                return null;
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public RistoranteDTO getRistoranteByNome(String nome) {
        String q = "SELECT * FROM Ristoranti WHERE nome = ?";
        try (PreparedStatement statement = conn.prepareStatement(q)) {
            statement.setString(1, nome);
            ResultSet rs = statement.executeQuery();

            if (rs.next()) {
                long ristoranteId = rs.getLong("id");
                String ristNome = rs.getString("nome");
                int numDip = rs.getInt("numDip");

                ArrayList<PiattoDTO> piatti = getPiattiPerRistorante(ristoranteId);

                return new RistoranteDTO(ristoranteId, ristNome, numDip, piatti);
            } else {
                return null;
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public List<RistoranteDTO> getAllRistoranti() {
        String q = "SELECT * FROM Ristoranti";
        List<RistoranteDTO> ris = new ArrayList<>();
        try (PreparedStatement statement = conn.prepareStatement(q)) {
            ResultSet rs = statement.executeQuery();
            while (rs.next()) {
                long ristoranteId = rs.getLong("id");
                String nome = rs.getString("nome");
                int numDip = rs.getInt("numDip");

                ArrayList<PiattoDTO> piatti = getPiattiPerRistorante(ristoranteId);

                ris.add(new RistoranteDTO(ristoranteId, nome, numDip, piatti));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return ris;
    }

    public void deleteRistorante(String nome) {
        long ristoranteId = 0;
        String qId = "SELECT id FROM Ristoranti WHERE nome = ?";
        try (PreparedStatement psId = conn.prepareStatement(qId)) {
            psId.setString(1, nome);
            ResultSet rs = psId.executeQuery();
            if (rs.next()) {
                ristoranteId = rs.getLong("id");
            } else {
                System.out.println("Ristorante non trovato: " + nome);
                return;
            }
        } catch (SQLException e) {
            throw new RuntimeException("Errore nel recupero ID ristorante", e);
        }

        try {

            String qMenu = "DELETE FROM Menu WHERE ristorante_id = ?";
            try (PreparedStatement psMenu = conn.prepareStatement(qMenu)) {
                psMenu.setLong(1, ristoranteId);
                psMenu.executeUpdate();
            }

            String qRistorante = "DELETE FROM Ristoranti WHERE id = ?";
            try (PreparedStatement psRist = conn.prepareStatement(qRistorante)) {
                psRist.setLong(1, ristoranteId);
                int rowsAffected = psRist.executeUpdate();
                if (rowsAffected > 0) {
                    System.out.println("Ristorante eliminato: " + nome);
                }
            }

        } catch (SQLException e) {
            throw new RuntimeException("Errore durante l'eliminazione del ristorante", e);
        }
    }
}
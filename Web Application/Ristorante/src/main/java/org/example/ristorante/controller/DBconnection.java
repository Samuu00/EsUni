package org.example.ristorante.controller;

import org.example.ristorante.DAO.PiattoDAO;
import java.sql.Connection;
import java.sql.DriverManager;

public final class DBconnection {

    public static DBconnection instance = null;

    public static DBconnection getInstance() {
        if(instance == null) instance = new DBconnection();
        return instance;
    }

    private PiattoDAO piatto = null;

    public PiattoDAO getPiatto() {
        return piatto;
    }

    Connection conn = null;

    public Connection getConn() {
        if(conn == null){
            try {
                conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/ristorante", "postgres", "postgres");
            } catch (Exception e) {
                e.printStackTrace();
            }
            return conn;
        }
        return conn;
    }
}

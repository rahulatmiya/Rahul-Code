package jdbcdemo;

import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.io.*;

public class JDBCdemo {
    
    public static void main(String[] args) {

        try {
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            Connection c = DriverManager.getConnection("jdbc:derby://localhost:1527/myd123", "root", "root");
            System.out.println("connection established");
            Statement s = c.createStatement();
            System.out.println("Enter the value for Column C1");
            int c1 = Integer.parseInt(cin());
            System.out.println("Enter the value for Column C2");
            int c2 = Integer.parseInt(cin());
            s.execute("insert into T1 values ("+c1+","+c2+")");
            System.out.println("insert was successful");
            
        } catch (SQLException ex) {
            System.out.println(ex);
        } catch (ClassNotFoundException cnf) {
            System.out.println("Class not found");
        }
        
    }
    
    static String cin()
    {
        String s = "";
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try{
            s= br.readLine();
        }
        catch(Exception ew)
        {
            System.out.println(ew);
        }
        return s;
        
    }

}
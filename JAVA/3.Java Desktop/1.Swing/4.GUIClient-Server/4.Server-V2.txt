package guiserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;

public class GUIServer {

    public static void main(String[] args) throws Exception {
        int p1 = Integer.parseInt(JOptionPane.showInputDialog("Enter Server Port Number 1"));
        int p2 = Integer.parseInt(JOptionPane.showInputDialog("Enter Server Port Number 2"));
        ServerChatWindow w1 = new ServerChatWindow(p1, 900, 1, 350, 350);
        ServerChatWindow w2 = new ServerChatWindow(p2, 900, 400, 350, 350);
        w1.setTitle("Server 1 Port = "+ p1);
        w2.setTitle("Server 2 Port = "+ p2);
    }

}

class ServerChatWindow extends JFrame {

    private JTextArea ta;
    private JScrollPane jp;
    private int port;

    public ServerChatWindow(int port, int xoffset, int yoffset, int width, int height) {
        this.port = port;
        ta = new JTextArea();
        ta.setAutoscrolls(true);
        jp = new JScrollPane(ta);
        add(jp);
        setSize(width, height);
        setLocation(xoffset, yoffset);
        setVisible(true);
        new Thread(() -> {
            try {
                System.out.println("Sever Singing ON");
                ServerSocket ss = new ServerSocket(port);
                System.out.println("Port is " + port);
                Socket soc = ss.accept();
                System.out.println("Connection Established");
                BufferedReader nis = new BufferedReader(
                        new InputStreamReader(
                                soc.getInputStream()
                        )
                );
                String str = nis.readLine();
                while (!str.equals("End")) {
                    ta.append("Server Recieved " + str + "\n");
                    str = nis.readLine();
                }
                System.out.println("Server Singing OFF");
            } catch (IOException ex) {
                System.out.println("Exception caught" + ex);
            }
        }).start();
    }
}
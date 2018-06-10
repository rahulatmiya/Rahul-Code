package guiclient;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import javax.swing.*;
import javax.swing.JFrame;

public class GUIClient {

    public static void main(String[] args) throws Exception {
        String addr1 = JOptionPane.showInputDialog("Enter Server Address 1");
        int p1 = Integer.parseInt(JOptionPane.showInputDialog("Enter Server Port Number 1"));
        String addr2 = JOptionPane.showInputDialog("Enter Server Address 2");
        int p2 = Integer.parseInt(JOptionPane.showInputDialog("Enter Server Port Number 2"));
  
        Connection c1 = new Connection(addr1,p1);
        Connection c2 = new Connection(addr2,p2);
        ChatWindow f1 = new ChatWindow(c1,1,1,350,300);
        ChatWindow f2 = new ChatWindow(c2,400,1,350,300);
        ChatWindow f3 = new ChatWindow(c1,1,400,350,300);
        ChatWindow f4 = new ChatWindow(c2,400,400,350,300);
    }

}



class ChatWindow extends JFrame implements ActionListener
{
    private JButton b1;
    private JTextArea ta;
    private JTextField tf;
    private JPanel p1;
    private Connection c;
    public ChatWindow(Connection c,int xoffset, int yoffset, int width,int height){
        this.c = c;
        b1 = new JButton("Send");
        ta = new JTextArea();
        tf = new JTextField(20);
        p1 = new JPanel();
        p1.add(tf);
        p1.add(b1);
        add(p1,BorderLayout.SOUTH);
        add(ta);
        setTitle("Connected to Ip = "+c.getIp()+" port = "+c.getPort());
        setSize(width,height);
        setLocation(xoffset,yoffset);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        b1.addActionListener(this);
        tf.addActionListener(this);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        String str = tf.getText();
        ta.append(str + "\n");
        tf.setText("");
        c.getNos().println(str);
        if (str.equals("End")) {
            System.exit(1);
        }
    }
}

class Connection
{
    private String ip;
    private int port;

    public String getIp() {
        return ip;
    }

    public int getPort() {
        return port;
    }
    Socket soc;
    PrintWriter nos;
    public Connection(String ip , int port) throws Exception
    {
        this.ip = ip;
        this.port = port;
        soc = new Socket(ip,port);
        System.out.println("The port for new socket is " + soc.getLocalPort());
        nos = new PrintWriter(
                new BufferedWriter(
                        new OutputStreamWriter(
                                soc.getOutputStream()
                        )
                ), true
        );
        System.out.println("Connection Established");
        
    }
    public Socket getSoc() {
        return soc;
    }
    public PrintWriter getNos() {
        return nos;
    }
    
}
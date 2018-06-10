<%@page import="com.rajeshpatkar.PiggyBank"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" 
              content="text/html; charset=UTF-8">
        <title>PiggyBank Client</title>
    </head>
    <body>
        <h1>PiggyBank Client</h1>
        <%
            PiggyBank p1 = new PiggyBank();
            out.println("Initial Balance = " + 
                    p1.getBalance() + "<br>");
            out.println("Initial Last Transaction = " + 
                    p1.getLt() + "<br>");
            p1.deposit(100);
            p1.deposit(50);
            p1.withdraw(25);
            out.println("Final Balance = " + 
                    p1.getBalance() + "<br>");
            out.println("Final Last Transaction = " + 
                    p1.getLt() + "<br>");
        %>
    </body>
</html>
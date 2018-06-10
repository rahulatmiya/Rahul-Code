<!DOCTYPE html>
<html>
    <head>
        <title>Working with Conditional Constructs</title>
    </head>
    <body>
        <h2> Using if </h2>
        <%
            int i = 0;
            out.println("<p> First if </p>");
            if (i == 0) {
                out.println("<p> In First If </p>");
            }
            out.println("<p> Second if </p>");
            if (i > 5) {
                out.println("<p> In Second If </p>");
            }
        %>
        <h2> Using if-else  </h2>
        <%
            i = 9;
            out.println("<p> First if-else </p>");
            if (i == 0) {
                out.println("<p> In First If </p>");
            } else {
                out.println("<p> In First Else </p>");
            }
            out.println("<p> Second if-else </p>");
            if (i > 5) {
                out.println("<p> In Second If </p>");
            } else {
                out.println("<p> In Second Else</p>");
            }
        %>
        <h2> Using switch case  </h2>
        <%
            for (int k = 0; k < 5; k++) {
                out.println("<p> For Loop Iteration number "+k +"</p>");
                switch (k) {
                    case 0:
                        out.println("<p> Case 0 is being executed </p>");
                        break;
                    case 1:
                        out.println("<p> Case 1 is being executed </p>");
                        break;
                    case 2:
                        out.println("<p> Case 2 is being executed </p>");
                        break;
                    case 3:
                        out.println("<p> Case 3 is being executed </p>");
                        break;
                    default:
                        out.println("<p> Default is being executed </p>");
                        break;
                }
            }
        %>
    </body>
</html>
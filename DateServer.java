import java.net.*;
import java.io.*;
import java.util.*;

public class DateServer {
    public static void main(String[] args) {
        // ServerSocket is created to listen on port 6013.
        try (ServerSocket serverSocket = new ServerSocket(6013)) {
            while (true) {
                // Print a message when waiting for a new connection.
                System.out.println("Waiting for connection...");
                
                // Accept a connection from a client.
                Socket client = serverSocket.accept();
                
                // Create PrintWriter to send data to the client.
                // It's wrapped in a try-with-resources to ensure it closes and doesn't leak resources.
                try (PrintWriter pout = new PrintWriter(client.getOutputStream(), true)) {
                    // Send the current date and time to the client.
                    pout.println(new java.util.Date().toString());
                } finally {
                    // Close the client socket after sending the date.
                    client.close();
                }
            }
        } catch (IOException ioe) {
            // Print an error message if an I/O error occurs.
            System.err.println(ioe);
        }
    }
}

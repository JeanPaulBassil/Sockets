import java.io.*;
import java.net.*;

public class DateClient {
    public static void main(String[] args) {
        // Establish a connection to the server running on localhost at port 6013.
        try {
            // The IP "127.0.0.1" refers to the localhost, and 6013 is the port number.
            Socket sock = new Socket("127.0.0.1", 6013);

            // Get the input stream from the socket.
            InputStream in = sock.getInputStream();
            
            // Wrap the InputStream with a BufferedReader for efficient reading.
            BufferedReader bin = new BufferedReader(new InputStreamReader(in));
            
            // Read the response from the server and print it to the console.
            System.out.println(bin.readLine());
            
            // Close the socket once the message is received.
            sock.close();
        } catch (IOException ioe) {
            // Print an error message if an I/O error occurs.
            System.err.println(ioe);
        }
    }
}

import java.io.*;
import java.net.*;

public class tcpclient{
 public static void main(String args[]) throws Exception {
 
   Socket sock=new Socket("localhost",4002);
   System.out.print("Enter the filename:");
   BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
   String frame=br.readLine();
   
   OutputStream ostream=sock.getOutputStream();
   PrintWriter pwrite=new PrintWriter(ostream,true);
   pwrite.println(frame);
   
   InputStream istream=sock.getInputStream();
   BufferedReader sockread=new BufferedReader(new InputStreamReader(istream));
   
   String str;
   while((str=sockread.readLine())!=null)
    System.out.println(str);
   
   sock.close();
   sockread.close();
   pwrite.close();
 
  }
}

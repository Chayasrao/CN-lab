import java.io.*;
import java.net.*;

public class tcpserver{
 public static void main(String args[]) throws Exception{
   
   ServerSocket sersock=new ServerSocket(4002);
   System.out.println("Server is up");
   Socket sock=sersock.accept();
   System.out.println("Connecting successfully....");
   
   InputStream istream=sock.getInputStream();
   BufferedReader br=new BufferedReader(new InputStreamReader(istream));
   String fname=br.readLine();
   BufferedReader contread=new BufferedReader(new FileReader(fname));
   
   OutputStream ostream=sock.getOutputStream();
   PrintWriter pwrite=new PrintWriter(ostream,true);
   
   String str;
   while((str=contread.readLine())!=null)
    pwrite.println(str);
   
   sersock.close();
   sock.close();
   contread.close();
   br.close();
 
 
 }
}
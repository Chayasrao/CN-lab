import java.io.*;
import java.net.*;

public class udpclient{
 public static void main(String args[]) throws Exception{
 
  DatagramSocket sock=new DatagramSocket();
 
  InetAddress ipadd=InetAddress.getByName("localhost");
 
  System.out.print("Enter the string : ");
  BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
  String sent=br.readLine();
 
  byte[] sdata=new byte[1024];
  byte[] rdata=new byte[1024];
 
  sdata=sent.getBytes();
 
  DatagramPacket spkt=new DatagramPacket(sdata,sdata.length,ipadd,9876);
  sock.send(spkt);
 
  DatagramPacket rpkt=new DatagramPacket(rdata,rdata.length);
  sock.receive(rpkt);
 
  String modsent=new String(rpkt.getData());
  System.out.println("From Server : "+modsent);
 
  sock.close();
 
 }
}
import java.io.*;
import java.net.*;

public class udpserver{
 public static void main(String args[]) throws Exception{
 
  DatagramSocket socket=new DatagramSocket(9876);
  System.out.println("Server is up");
 
  while(true)
  {
  byte[] sdata=new byte[1024];
  byte[] rdata=new byte[1024];
 
  DatagramPacket rpkt=new DatagramPacket(rdata,rdata.length);
 
  socket.receive(rpkt);
  String sent=new String(rpkt.getData());
  System.out.println("Received : "+sent);
 
  InetAddress ipadd=rpkt.getAddress();
  int port=rpkt.getPort();
  String caps=sent.toUpperCase();
  sdata=caps.getBytes();
 
 
  DatagramPacket spkt=new DatagramPacket(sdata,sdata.length,ipadd,port);
 
  socket.send(spkt);
 
 
  }
 }
}

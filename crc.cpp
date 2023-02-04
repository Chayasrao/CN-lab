# include <bits/stdc++.h>
using namespace std;
string crc(string data,string poly,bool crchk)
 {
  string rem=data;
  if(!crchk)
   for(int i=0;i<poly.length()-1;i++)
    rem.append("0");
 
  for(int i=0;i<rem.length()-poly.length()+1;i++)
  if(rem[i]=='1')
  for(int j=0;j<poly.length();j++)
  if(rem[i+j]==poly[j])
  rem[i+j]='0';
  else
  rem[i+j]='1';
 
  return rem.substr(rem.length()-poly.length()+1);
 }
 
int main()
 {
  string data,poly,rem,nrem,cw,ncw;
  cout<<"Enter the binary data to be sent : ";
  cin>>data;
  cout<<"Enter the generating polynomial : ";
  cin>>poly;
 
  rem=crc(data,poly,0);
  cout<<"Remainder : "<<rem<<endl;
  cw=data+rem;
  cout<<"Message sent : "<<cw<<endl;
 
  cout<<"Enter the message received : ";
  cin>>ncw;
 
  if(cw.length()!=ncw.length())
  {
  cout<<"Error in data transmission\n";
  exit(1);
  }
 
  nrem=crc(cw,poly,1);
  if(stoi(nrem)==0)
  cout<<"No error in data transmission\n";
  else
  cout<<"Error in data transmission\n";
 }
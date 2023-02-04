#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

const int cap=100;
const int rate=50;

int main(){
 
 int tokens=0,prev;
 int flag=0;
 int tokneed[5];
 int f=0,r=-1;
 int q=0;
 for(int i=0;i<10;i++){
  this_thread::sleep_for(chrono::seconds(1));
  tokens+=rate;
  if(tokens>cap)
   tokens=cap;
  if(q!=5){
  r=(r+1)%5;
   tokneed[r]=rand()%100;
   q++;
  }
 
  if(tokneed[f]<=tokens){
   cout<<tokneed[f]<<"packet sent tokens remaining "<<tokens<<endl;
   tokens-=tokneed[f];
   f=(f+1)%5;
   q--;
  }
  else{
   cout<<tokneed[f];
   cout<<"  packet can not be sent waiting \n";
  }
 }
 
 return 0;
}
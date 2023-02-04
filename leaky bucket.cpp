# include <bits/stdc++.h>
using namespace std;

int main()
{
int sent=0,acc=0,rem=0,n,bck,op;
cout<<"Enter the number of packets : ";
cin>>n;
int a[n];
cout<<"Enter the packets : ";
for(int i=0;i<n;i++)
cin>>a[i];

cout<<"Enter the bucket size : ";
cin>>bck;
cout<<"Enter the rate of flow : ";
cin>>op;

cout<<"clk\tinput\taccept\tsent\tremaining\n";
for(int i=0;i<n;i++)
{
if(a[i]+rem<=bck)
acc=a[i];
else
acc=0;
if(acc+rem<=op)
{
sent=acc+rem;
rem=0;
}
else
{
sent=op;
rem=acc+rem-sent;
}
cout<<(i+1)<<"\t"<<a[i]<<"\t"<<acc<<"\t"<<sent<<"\t"<<rem<<"\n";
}

}
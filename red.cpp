# include <bits/stdc++.h>
using namespace std;

const int maxqsize=10;
const int maxpkts=20;
const double minprob=0.3;
const double maxprob=0.7;

double rand_double(double min,double max)
{
return min+(max-min)*(double)rand()/RAND_MAX;
}

int main()
{
srand(time(0));
int qsize=0;
double dp=minprob;
for(int i=0;i<maxpkts;i++)
{
if(qsize==maxqsize)
{
cout<<"Packet Dropped (Queue Full)\n";
dp=minprob;
}
else if(rand_double(0,1)<dp)
{
cout<<"Packet Dropped (Random)\n";
dp=dp+(maxprob-minprob)/(maxpkts-1);
}
else
{
cout<<"Packet Accepted\n";
dp=minprob;
qsize++;
}
}
return 0;
}
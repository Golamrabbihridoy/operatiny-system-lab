
#include<iostream>
using namespace std;

int main()
{
    int n,burstTime[30],waitTime[30],i,j;
    double  avgWaitTime;
    cout<<"Enter total number of processes:";
    cin>>n;

    cout<<"\nEnter Process Burst Time\n";
    for(i=1;i<=n;i++)
    {
        cout<<"P["<<i<<"]:";
        cin>>burstTime[i-1];
    }


    waitTime[0]=0;

    for(i=1;i<n;i++)
    {
       waitTime[i]=0;
        for(j=0;j<i;j++)
           waitTime[i]+=burstTime[j];
    }

    cout<<"\nProcess\t\tBurst Time\tWaiting Time";
    for(i=0;i<n;i++)
    {
        avgWaitTime+= waitTime[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<burstTime[i]<<"\t\t"<< waitTime[i];
    }

    avgWaitTime/=i;
    cout<<"\n\nAverage Waiting Time:"<<avgWaitTime;
    return 0;
}

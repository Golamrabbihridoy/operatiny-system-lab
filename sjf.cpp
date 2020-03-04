
#include<iostream>
using namespace std;

int main()
{
    int n,i,j,burstTime[30],p[20];
    double waitTime[30],avgWaitTime=0.0;
    cout<<"Enter total number of processes:";
    cin>>n;

    cout<<"\nEnter Process Burst Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>burstTime[i];
        p[i]=i+1;
    }
     int temp;
     for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(burstTime[i]>burstTime[j]){
                  temp=burstTime[i];
                  burstTime[i]=burstTime[j];
                  burstTime[j]=temp;

                   temp=p[i];
                   p[i]=p[j];
                   p[j]=temp;
                }
            }
     }
     waitTime[0]=0;

    for(i=1;i<=n;i++)
    {
       waitTime[i]=0;
        for(j=0;j<i;j++)
           waitTime[i]+=burstTime[j];
    }

    cout<<"\nProcess\t\tBurst Time\tWaiting Time";
    for(i=0;i<n;i++)
    {
        avgWaitTime+= waitTime[i];
        cout<<"\nP["<<p[i]<<"]"<<"\t\t"<<burstTime[i]<<"\t\t"<< waitTime[i];
    }

    avgWaitTime/=i;

    cout<<"\n\nAverage Waiting Time:"<<avgWaitTime;

    return 0;
}

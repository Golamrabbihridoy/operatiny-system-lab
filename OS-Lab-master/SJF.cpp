#include<iostream>

using namespace std;

int main(){
    int tmp,p[50],n,tat[50],burst_time[50],waiting_time[50],i,j;
    double av_waiting_time=0.0,av_tat=0.0;

    cout<<"Enter total number of processes(maximum 50):";
    cin>>n;

    cout<<"\nEnter Process Burst Time\n";
    for(i=1;i<=n;i++){
        cout<<"P["<<i<<"]:";
        cin>>burst_time[i];
        p[i]=i;
    }
    //sorting
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(burst_time[i]>burst_time[j]){
                tmp=burst_time[i];
                burst_time[i]=burst_time[j];
                burst_time[j]=tmp;

                tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
        }
    }

    //calculating waiting time
    for(i=1;i<=n;i++){
        waiting_time[i]=0;
        for(j=1;j<i;j++)
            waiting_time[i]+=burst_time[j];
    }

    cout<<"\nProcess\t\tBurst Time\tWaiting Time\t Turnaround time";

    //calculating turnaround time
    for(i=1;i<=n;i++)
    {
        tat[i]=burst_time[i]+waiting_time[i];
        av_tat+=tat[i];
        av_waiting_time+=waiting_time[i];
        cout<<"\nP["<<p[i]<<"]"<<"\t\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t "<<tat[i];
    }
    av_waiting_time=av_waiting_time/n;
    av_tat=av_tat/n;
    cout<<"\n\nAverage Waiting Time:"<<av_waiting_time<<endl;
    cout<<"\n\nAverage Turnaround Time:"<<av_tat<<endl;
    return 0;
}


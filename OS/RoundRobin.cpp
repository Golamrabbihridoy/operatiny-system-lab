#include<bits/stdc++.h>
using namespace std;
int main(){
    queue <int>que;
    int bt[20], temp[20], wt[20], tat[20], avwt=0, n, i, j, time=0, quantum;

    cout<<"Enter Total Number of Processes: ";
    cin>>n;
    cout<<"Enter Time Quantum: ";
    cin>>quantum;
    cout<<"Enter Process Burst Time:"<<endl;

    for(i=1;i<=n;i++){
        cout<<"P["<<i<<"]: ";
        cin>>bt[i];
        temp[i]=bt[i];
        que.push(i);
    }

    cout<<"Gantt Chart :";
    while(!que.empty()){
        i=que.front();
         if(temp[i]>quantum){
            temp[i]=temp[i]-quantum;
            time=time+quantum;
            cout<<"P["<<i<<"] | ";
            que.push(i);
            que.pop();
         }
         else{
            cout<<"P["<<i<<"] | ";
            time=time+temp[i];
            tat[i]=time;
            que.pop();
         }
    }

    cout<<endl<<"Process\t\tBurst Time\tWaiting Time\tTurnAround Time";
    for(i=1;i<=n;i++){
        wt[i]=tat[i]-bt[i];
        avwt=avwt+wt[i];
        cout<<endl<<"P["<<i<<"]\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }

    cout<<endl<<"Average Waiting Time : "<<avwt/n;
    cout<<endl<<"Average Turnaround Time : "<<time/n;
    return 0;
}

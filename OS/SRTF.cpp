#include<bits/stdc++.h>
using namespace std;
int n, art[20], bt[20], wt[20], tat[20], avwt=0, avtat=0, i, j, k, index[20], itemp, temp,  small, serial=0, limit=0, minimum=0;

int shortest(int m){
    for(k=0;k<m;k++){
        if(minimum>bt[i])minimum=bt[i];
    }
    for(k=0;k<m;k++){
        if(minimum==bt[i])return i;
    }
}

int main(){
    cout<<"Enter Number of Processes: ";
    cin>>n;

    cout<<"Enter Process Arrival Time:"<<endl;
    for(i=0;i<n;i++){
        cout<<"P["<<i+1<<"]:";
        cin>>art[i];
        index[i]=i;
    }

    cout<<"Enter Process Burst Time:"<<endl;
    for(i=0;i<n;i++){
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }

    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(art[j]<art[i]){
                swap(art[i], art[j]);
                swap(bt[i], bt[j]);
                swap(index[i], index[j]);
            }
        }
    }

    int time=art[0];
    int div[20];
    div[0]=art[0];
    tat[0]=div[0];
    for(i=0;i<n;i++){
        time = time+bt[i];
        if(i>0)div[i]=art[i]-art[i-1];
    }


    for(i=0;i<time;i++){
        if(time>=art[serial] & bt[serial]!=0){
            small=shortest(limit);
            if(bt[small]<div[serial]){
                tat[small]=tat[small]+bt[small];
            }
            else{
                tat[small]=tat[small]+div[serial];
                bt[small]=bt[small]-div[serial];
            }
            serial++;
        }
        else serial++;
        if(serial>n)serial=0;
    }


    cout<<endl<<"Process\t\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;
    for(i=0;i<n;i++){
        wt[i]= tat[i]-bt[i];
        avwt=avwt+wt[i];
        avtat=avtat+tat[i];
        cout<<"P["<<index[i]+1<<"]\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;

    }
    cout<<endl<<"Average Waiting Time: "<<avwt/i<<endl;
    cout<<"Average Turnaround Time: "<<avtat/n<<endl;
    return 0;
}

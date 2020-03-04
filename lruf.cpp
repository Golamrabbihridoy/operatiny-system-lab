#include<bits/stdc++.h>
using namespace std;

int  check(int frame[],int page,int frameSize)
{

    for(int j=0;j<frameSize;j++){
        if(frame[j]==page) return 1;
    }
    return 0;
}
int main(){
    queue <int>que;
    queue <int>temp;
    int i,j,m,n, fault=0, last=0, point=0, temp1, temp2;
    bool flag =false;
    cout<<"Total Number of Reference Pages: ";
    cin>>n;
    cout<<"Enter Frame Size: ";
    cin>>m;
    int refstr[n], frame[m];
    cout<<"Enter Reference String: ";
    for(i=0;i<n;i++){
        cin>>refstr[i];
    }
    for(i=0;i<m;i++){
        frame[i]=-1;
    }
    que.push(refstr[0]);
    frame[0]==refstr[0];
    fault=1;
    for(i=1;i<n;i++){
         if(check(frame,refstr[i],m)){
             while(!que.empty()){
                point=que.front();
                que.pop();
                if(refstr[i] != point){
                    temp.push(point);
                }
             }
            while(!temp.empty()){
                point=temp.front();
                temp.pop();
               que.push(point);
             }
            que.push(refstr[i]);
        }
        else{
            if(fault<m){
            fault++;
            que.push(refstr[i]);
            frame[fault]=refstr[i];

           }
           else{
            point=que.front();
            que.pop();
            for(j=0;j<m;j++)
                {
                    if(frame[j]==point){
                    frame[j]=refstr[i];
                    que.push(refstr[i]);
                    fault++;
                    break;
                   }
                }
           }
    }
}

    cout<<"Number of Page Faults: "<<fault<<endl;
    return 0;
}

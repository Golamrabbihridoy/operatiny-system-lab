//C++ implementation of above algorithm
#include<bits/stdc++.h>
using namespace std;

void showq(int frame[],int frameSize)
{
    for(int j=0;j<frameSize;j++){
        cout<<frame[j]<< " ";
    }
}
int  check(int frame[],int page,int frameSize)
{

    for(int j=0;j<frameSize;j++){
        if(frame[j]==page) return 0;
    }
    return 1;

}

// for(j=0;j<frameSize && j<gquiz.size();j++)
int pageFaults(int pages[], int n, int frameSize)
{   int i,j=0,count=1;
    int frame[frameSize]={9999,9999,9999,9999};
    frame[0]=pages[0];
    for(i=1;i<n;i++){
        if(check(frame,pages[i],frameSize)){
            frame[(count%frameSize)]=pages[i];
            count++;
        }
        cout << "\n The queue gquiz is : ";
	     showq(frame,frameSize);
    }
	return count;
}

int main()
{
	int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
	int n = sizeof(pages)/sizeof(pages[0]);
	int frameSize = 4;
	cout << pageFaults(pages, n, frameSize);
	return 0;
}

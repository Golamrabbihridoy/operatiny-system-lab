//Banker's Algorithm
#include <iostream>
using namespace std;
int main()
{

	int n, m, i, j, k,flag;

	cout<<"Enter Number of Processes: ";
    cin>>n;
    cout<<"Enter Number of Resources: ";
    cin>>m;

    int alloc[n][m];
	cout<<"Enter Allocation of Processes: ";
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin>>alloc[i][j];
        }
    }
 /*int max[n][m], need[n][m];;
  cout<<"Enter Maximum Needs of Processes: ";
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin>>max[i][j];
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }*/

    int req[n][m];
  cout<<"Enter Request Table: ";
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin>>req[i][j];

        }
    }
    int avail[m],work[m];
    for(i=0; i<m; i++){
        cin>>avail[i];
        work[i]=avail[i];
    }
	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
            flag =0;
        for(i=0;i<m;i++){
           if( alloc[k][i]!=0){
              flag=1;
              f[k]=0;
              break;
           }
        }
        if(flag==0){
            f[k]=1;
        }
	}

	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {

			if (f[i] == 0) {

                flag = 0;
				for (j = 0; j < m; j++) {
					if (req[i][j] > work[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						work[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	cout<<"Following is the SAFE Sequence"<<endl;
	for (i = 0; i <n ; i++)
		cout<< ans[i]<<" ";

	return (0);

}

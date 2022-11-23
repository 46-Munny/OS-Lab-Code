
#include <bits/stdc++.h>
using namespace std;

int size = 8;

void FCFS(int arr[], int head)
{
    int seek_count = 0;
    int distance, cur_track;

}

// Driver code
int main()
{

    int n,arr[100],diff[100],disk_size,i,j,head,seek_count = 0;

	int distance, cur_track,s=0,temp,temp2,k,l,v[100];
	int sq[100];
	cout<<"Total disk size: ";
	cin>>disk_size;
    cout<<"\nEnter no of request:";
    cin>>n;
    cout<<"\nRequested sequence:";

	for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"\nEnter head: ";
    cin>>head;
    int head2=head;

    for(i=0;i<n;i++)
    {
        v[i]=0;
    }

     for(k=0;k<n;k++)
     {
         cout<<"\n"<<k<<":\n";
    for(l=0;l<n;l++)
    {
        diff[l]=abs(arr[l]-head);
        cout<<diff[l]<<" ";
    }

     for(i=0; i<n; i++)
    {
        for(j=0; j<n-i; j++)
        {
            if(diff[j]>diff[j+1] && v[j]!=1)
            {
                temp=diff[j+1];
                diff[j+1]=diff[j];
                diff[j]=temp;


                temp2=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp2;


            }
        }
    }

    cout<<"\narray sort: ";
    for(int p=0;p<n;p++)
    {
        cout<<arr[p]<<" ";
    }

    cout<<"\ndiff sort: ";
    for(int q=0;q<n;q++)
    {
        cout<<diff[q]<<" ";
    }

    sq[s]=arr[k];
    s++;
    head=arr[k];
    v[k]=1;

     }


    for (int i = 0; i <n; i++) {
        cur_track = sq[i];


        distance = abs(cur_track - head2);


        seek_count += distance;


        head2 = cur_track;
    }


    cout << "Total number of seek operations = "
         << seek_count << endl;


    cout << "Seek Sequence is" << endl;

    for (int i = 0; i <n; i++) {
        cout << sq[i] << endl;
    }

}

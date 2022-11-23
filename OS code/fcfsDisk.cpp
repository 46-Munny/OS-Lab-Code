
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

    int n,arr[100],disk_size,i,head,seek_count = 0;

	int distance, cur_track,s=0;
	int seek_sequence[100];
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



    for (int i = 0; i <n; i++) {
        cur_track = arr[i];


        distance = abs(cur_track - head);


        seek_count += distance;


        head = cur_track;
    }

    cout << "Total number of seek operations = "
         << seek_count << endl;


    cout << "Seek Sequence is" << endl;

    for (int i = 0; i <n; i++) {
        cout << arr[i] << endl;
    }

}

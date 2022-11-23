#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n,arr[100],disk_size,i,head,seek_count = 0;
    string direction ;
	int distance, cur_track,l=0,r=0,s=0;
	int left[100],right[100],seek_sequence[100];
	cout<<"Total disk size: ";
	cin>>disk_size;
    cout<<"\nEnter no of request:";
    cin>>n;
    cout<<"\nRequested sequence:";

	for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\nEnter Direction:";
    cin>>direction;
    cout<<"\nEnter head: ";
    cin>>head;


	for (int i = 0; i <n; i++) {
		if (arr[i] < head)
        {
            left[l]=arr[i];
            l++;
        }

		if (arr[i] > head)
        {
            right[r]=arr[i];
            r++;
        }

	}


	sort(left,left+l);
	sort(right, right+r);
    if(direction=="right")
    {
        for (int i = 0; i < r; i++) {
        cur_track = right[i];
        seek_sequence[s]=cur_track;
		 s++;

		distance = cur_track - head;

        seek_count += distance;

        head = cur_track;
    }

    head = left[0];
    seek_count += (right[r-1] - left[0]);
    for (int i = 0; i <l; i++) {
        cur_track = left[i];
		seek_sequence[s]=cur_track;
		 s++;
		 distance = cur_track - head;
         seek_count += distance;
         head = cur_track;
    }
    }


     if(direction=="left")
    {
        for (int i = 0; i < l; i++) {
        cur_track = left[i];
        seek_sequence[s]=cur_track;
		 s++;

		distance = head-cur_track;

        seek_count += distance;

        head = cur_track;
    }

    head =right[r-1];
    seek_count += (right[r-1] - left[0]);
    for (int i =r-1; i>=0; i--) {
        cur_track = right[i];
		seek_sequence[s]=cur_track;
		 s++;
		 distance = head-cur_track;
         seek_count += distance;
         head = cur_track;
    }
    }

	cout << "Total number of seek operations = "
		<< seek_count << endl;

	cout << "Seek Sequence: " << endl;

	for (int i = 0; i <s ; i++) {
		cout << seek_sequence[i] << endl;
	}

	return 0;
}




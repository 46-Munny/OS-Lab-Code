
#include <iostream>
using namespace std;

int main()
{


int n, m, i, j, k,flag2,c=0,y,r,c2=0,c3=0;
int alloc[100][100],max[100][100],avail[100],need[100][100],flag[100],sq[100],rq[100];
cout<<"Number of processes:";
cin>>n;
cout<<"\nNumber of resources:";
cin>>m;
cout<<"\nrequested process: p";
cin>>r;
cout<<"\nrequested value: ";
for(i=0; i<m; i++)
{
    cin>>rq[i];
}
cout<<"\nallocation matrix:\n";
for(i=0;i<n;i++)
{
    //cout<<"p"<<i<<" ";
    for(j=0;j<m;j++)
    {
      cin>>alloc[i][j];
    }
}

cout<<"\max matrix:\n";
for(i=0;i<n;i++)
{
    //cout<<"p"<<i<<" ";
    for(j=0;j<m;j++)
    {
      cin>>max[i][j];
    }
}

cout<<"\navailable matrix:\n";
for(i=0;i<m;i++)
{

      cin>>avail[i];

}
for (i = 0; i < n; i++)
{
	for (j = 0; j < m; j++)
    {
      need[i][j] = max[i][j] - alloc[i][j];
    }

}

cout<<"\nneed matrix\n";

for (i = 0; i < n; i++)
{
	for (j = 0; j < m; j++)
    {
      cout<<need[i][j]<<" ";
    }
    cout<<endl;

}
for(i=0;i<m;i++)
{
    if(rq[i]<=need[r][i])
    {
        c2++;
        //cout<<"c2:"<<c2<<" ";
    }
     if(rq[i]<=avail[i])
    {
        c3++;
        //cout<<"c3:"<<c3<<" ";
    }
    cout<<endl;
}
if(c2==m && c3==m)
{

for(i=0;i<m;i++)
{
    avail[i]=avail[i]-rq[i];
}

for(i=0;i<m;i++)
{
    alloc[r][i]=alloc[r][i]+rq[i];
}

for(i=0;i<m;i++)
{
    need[r][i]=need[r][i]-rq[i];
}

cout<<"\nnew allocation\n";
for (i = 0; i < n; i++)
{
	for (j = 0; j < m; j++)
    {
      cout<<alloc[i][j]<<" ";
    }
    cout<<endl;

}

cout<<"\nnew need\n";
for (i = 0; i < n; i++)
{
	for (j = 0; j < m; j++)
    {
      cout<<need[i][j]<<" ";
    }
    cout<<endl;

}
cout<<"\nnew available\n";
for(i=0;i<m;i++)
{
    cout<<avail[i];
}


for(i=0;i<n;i++)
{
    flag[i]=0;
}


for (k = 0; k < n; k++) {
	for (i = 0; i < n; i++) {
	if (flag[i] == 0) {

		int flag2 = 1;
		for (j = 0; j < m; j++) {
		if (need[i][j] > avail[j]){
			flag2 = 0;
			break;
		}
		}

		if (flag2 == 1) {
		sq[c] = i;
		c++;
		for (y = 0; y < m; y++)
        {
            avail[y] += alloc[i][y];
        }

		flag[i] = 1;
		}
	}
	}
}

if(n==c)
{
    cout<<"\nsafe sequence:";
    for (i = 0; i < n; i++)
    {
        if(i<n-1)
        {
           cout << " P" << sq[i] << " ->";
        }
        else
        {
              cout << " P" << sq[i] <<endl;
        }


    }
     cout<<"System  grants request";

}

else{
    cout<<"\nEnter into unsafe state";
     cout<<"System doesn't grant request";
}
}
else{
    cout<<"System doesn't grant request";
}

}




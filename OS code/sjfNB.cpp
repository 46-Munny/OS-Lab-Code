
#include<iostream>
#include<string>
using namespace std;
class process{
public:
    int pid;
    string pt;
    int art;
    int bt;
    int ct;
    int wt;
    int tat;

    void getinput()
    {

        cin>>pid>>pt>>art>>bt;

    }
    void getoutput()
    {
        cout<<"\t"<<pid;
        cout<<"\t"<<pt;
        cout<<"\t"<<art;
        cout<<"\t"<<bt;
        cout<<"\t"<<ct;
        cout<<"\t"<<tat;
        cout<<"\t"<<wt;
        cout<<endl;
    }




};

void atsort(process ar[],int n)
{
    process temp;
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n-i; j++)
        {
            if(ar[j].art>ar[j+1].art)
            {
                temp=ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=temp;


            }
        }
    }
}

void processType(process p[50],int n)
{
   process temp;
   int i,j;
   for(i=1;i<=n;i++)
   {
       for(j=i+1;j<=n;j++)
       {
           if(p[i].art==p[j].art)
           {
               if(p[i].pt=="up"&&p[j].pt=="sp")
               {
                   temp=p[i];
                   p[i]=p[j];
                   p[j]=temp;
               }
           }
       }
   }

}
void processId(process p[50],int n)
{
   process temp;
   int i,j;
   for(i=1;i<=n;i++)
   {
       for(j=i+1;j<=n;j++)
       {
           if(p[i].pt==p[j].pt && p[i].art==p[j].art && p[i].bt==p[j].bt)
           {
               if(p[i].pid>p[j].pid)
               {
                   temp=p[i];
                   p[i]=p[j];
                   p[j]=temp;
               }
           }
       }
   }

}

void processBt(process p[50],int n)
{
int i,j,k,l,m,c=0,c2;
process tmp;

for(i=1;i<=n;i++)
{
    if(i==1)
    {
        for(j=i+1;j<=n;j++)
        {
            if(p[i].art==p[j].art)
            {
                 c++;

            }

        }

        if(c==0)
        {
            p[i].ct=p[i].art+p[i].bt;
        }
        else{
            for(k=1;k<=c;k++)
            {
                for(l=1;l<=c;l++)
                {
                    if(p[l].bt>p[l+1].bt)
                    {
                        tmp=p[l+1];
                        p[l+1]=p[l];
                        p[l]=tmp;
                    }
                }
            }
            p[i].ct=p[i].art+p[i].bt;

        }
    }
    else{
         p[i].ct=p[i-1].ct+p[i].bt;
    }
    c2=0;
    for(j=2;j<=n;j++)
    {
        if(p[i].ct>=p[j].art)
        {
            c2++;

        }
    }

    if(c2>0)
    {
      for(k=i+1;k<=c2;k++)
      {
        for(m=i+1;m<=c2;m++)
        {
            if(p[m].bt>p[m+1].bt)
            {
                tmp=p[m+1];
                p[m+1]=p[m];
                p[m]=tmp;
            }
        }
    }

    }



}

}



void calsjf(process p[50],int n)
{

    int i,j;
    int c=0;
    int idle;
    p[1].wt=0;
    p[1].ct=p[1].art+p[1].bt;
    p[1].tat=p[1].ct-p[1].art;
    if(p[1].art!=0)
    {
        cout<<"0--|cpu idle|--"<<p[1].art;
         cout<<"--|"<<p[1].pid<<"|--"<<p[1].ct;
    }
    else{
        cout<<"0--|"<<p[1].pid<<"|--"<<p[1].ct;
    }
    for(i=2;i<=n;i++)
    {
        if(p[i-1].ct>=p[i].art)
            {
                c++;
            }
        if(c==0)
        {
            cout<<"--|cpu idle|--"<<p[i].art;
            p[i].ct=p[i].art+p[i].bt;
            p[i].tat=p[i].ct-p[i].art;
            p[i].wt=p[i].tat-p[i].bt;
            cout<<"--|"<<p[i].pid<<"|--"<<p[i].ct;
        }
        else{
            p[i].ct=p[i-1].ct+p[i].bt;
            p[i].tat=p[i].ct-p[i].art;
            p[i].wt=p[i].tat-p[i].bt;
            cout<<"--|"<<p[i].pid<<"|--"<<p[i].ct;
        }
    }

}


int main()
{
    process p[50];
    int n,i,j,totalWT=0,totalTAT=0;
    float avgtat,avgwt;


    cout<<"\nEnter no of processes:";
    cin>>n;
    cout<<"\nEnter PID PT AT BT\n";
    for(i=1;i<=n;i++)
    {
        p[i].getinput();
    }
    atsort(p,n);
    processType(p,n);
    processBt(p,n);
    processId(p,n);

    cout<<"\nGantt chart\n\n";
    calsjf(p,n);
    cout<<"\n\n\n\tPID\tPT\tAT\tBT\tCT\tTAT\tWT\n";
    for(i=1;i<=n;i++)
    {
        p[i].getoutput();
    }



    for(i=1;i<=n;i++)
    {
      totalTAT=totalTAT+p[i].tat;

      totalWT=totalWT+p[i].wt;

    }
    avgtat=(float)totalTAT/(float)n;
    avgwt=(float)totalWT/(float)n;

    cout<<"\n\n\n Avereage Turnaround Time="<<avgtat;
    cout<<"\n\n Avereage Wating Time="<<avgwt;
    cout<<"\n\n\nReady Queue:"<<endl;
   cout<<"0 second:";
    if(p[1].art==0)
    {
        cout<<p[1].pid<<endl;
    }
    else{
        cout<<" "<<endl;
        cout<<p[1].art<<" second:";
        for(i=1;i<=n;i++)
        {
            if(p[1].art==p[i].art)
            {
                cout<<p[i].pid<<" ";
            }
        }
        cout<<endl;


    }
    for(i=1;i<=n;i++)
    {
        cout<<p[i].ct<<" second:";
        for(j=i+1;j<=n;j++)
        {
           if(p[i].ct>=p[j].art)
           {

               cout<<p[j].pid<<" ";
           }



        }
        cout<<endl;
    }
  cout<<"\n\n";
}

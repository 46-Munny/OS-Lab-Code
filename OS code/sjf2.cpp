
#include<iostream>
#include<string>
//int cnt=1;
using namespace std;
class process{
public:
    int pid;
    string pt;
    int art;
    int bt;
    int rbt;
    int ct;
    int wt;
    int tat;
    //int is_completed;

    void getinput()
    {

        cin>>pid>>pt>>art>>bt;
         rbt=bt;
        // is_completed=0;

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





void processBt(process p[50],int n)
{

int sTime,cTime,i,j,c,k,l,m,q,time,time2,idp,cnt,c2;
int st[50],ct[50],id[50];
time=-1,time2=0,cnt=1,i=1;

process tmp;


//while(complete!=n)
//{
   while(i!=n+1)
   {
      time++;
      time2++;
      c=0;
      for(j=1;j<=n;j++)
      {
      if(p[j].art<=time)
      {
         c++;
         //cout<<"c:"<<c<<endl;

      }
      }

      if(c==0)
      {
         id[cnt]=000;
         st[cnt]=time;
         ct[cnt]=time2;
         cnt++;

         //cout<<time<<"---|"<<"cpu odle"<<"|---"<<time2<<" ";

      }
      if(c==1)
      {
        p[i].rbt--;

         id[cnt]=p[i].pid;
         st[cnt]=time;
         ct[cnt]=time2;
         cnt++;

        // cout<<time<<"---|"<<p[i].pid<<"|---"<<time2<<"---|";
         if(p[i].rbt==0)
         {
          i++;
         }


      }
      if(c>1)
      {
          for(k=1;k<=c;k++)
          {
             for(l=k+1;l<=c;l++)
             {
                if(p[k].rbt>p[l].rbt)
                {
                    tmp=p[k];
                    p[k]=p[l];
                    p[l]=tmp;
                }

                if(p[k].rbt==p[l].rbt && p[k].pt=="up"&&p[l].pt=="sp")
                {
                     tmp=p[k];
                    p[k]=p[l];
                    p[l]=tmp;
                }

                if(p[k].rbt==p[l].rbt && p[k].pt==p[l].pt&& p[k].pid>p[l].pid)
                {
                     tmp=p[k];
                    p[k]=p[l];
                    p[l]=tmp;
                }

             }
        /* cout<<"lining: ";
         for(int t=1;t<=n;t++)
         {
           cout<<p[t].pid<<" ";
         }
         cout<<endl;*/
          }

        /*p[i].rbt--;*/
       id[cnt]=p[i].pid;
         st[cnt]=time;
         ct[cnt]=time2;
         cnt++;
         /*cout<<"short: ";
         for(int t=1;t<=n;t++)
         {
           cout<<p[t].pid<<" ";
         }*/
         //cout<<endl;
         //cout<<time<<"---|"<<p[i].pid<<"|---"<<time2<<"---|";
          p[i].rbt--;
        if(p[i].rbt==0)
         {
          i++;
         }


      }


        //cout<< gt[cnt].id<<"--"<< gt[cnt].st<<"--"<< gt[cnt].ct;
       // cout<<p[i].pid<<"  ";




   }

 cout<<"\nGant chart\n";
for(i=1;i<cnt;i++)
{
    cout<<st[i]<<"---|"<<id[i]<<"--|"<<ct[i]<<endl;
}

for(m=1;m<=n;m++)
{
    c2=0;
   for(q=cnt-1;q>=1;q--)
   {
       if(p[m].pid==id[q])
       {
           c2++;

       }
       if(c2==1)
       {
           p[m].ct=ct[q];

           break;

       }
   }



}

  for(m=1;m<=n;m++)
   {
        p[m].tat=p[m].ct-p[m].art;
        p[m].wt=p[m].tat-p[m].bt;
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
   // processType(p,n);
    processBt(p,n);
   // processId(p,n);
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




}

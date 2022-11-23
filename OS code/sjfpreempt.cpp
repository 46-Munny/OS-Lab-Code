
#include<iostream>
#include<string>
int cnt=1;
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

class ganttChart{
public:
    int id;
    int st;
    int ct;

    void gantt()
    {
        cout<<st<<"---|"<<id<<"|--"<<ct;
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

int complete,sTime,cTime,i,j,c,k,l,time,time2,idp;
complete=0,time=-1,time2=0;

process tmp;

ganttChart gt[50];
i=1;

//while(complete!=n)
//{
   while(i!=3)
   {
      time++;
      time2++;
      c=0;
      for(j=1;j<n;j++)
      {
      if(p[j].art<=time)
      {
         c++;
      }
      }

      if(c==0)
      {
         /*gt[cnt].id=000;
         gt[cnt].st=time;
         gt[cnt].ct=time2;
         cnt++;*/

         cout<<time<<"---|"<<"cpu odle"<<"|---"<<time2<<" ";

      }
      if(c==1)
      {
        /*p[i].rbt--;
        idp=p[i].pid;
        gt[cnt].id=idp;
         gt[cnt].st=time;
         gt[cnt].ct=time2;
         cnt++;*/

         cout<<time<<"---|"<<p[i].pid<<"|---"<<time2<<"---|";
         if(p[i].rbt==0)
         {
          i++;
         }
         else{
              p[i].rbt--;
         }

      }
      if(c>1)
      {
        for(k=1; k<=c; k++)
        {
        for(l=1; l<=c-k; l++)
        {
            if(p[l].rbt>p[l+1].rbt)
            {
                tmp=p[l+1];
                p[l+1]=p[l];
                p[l]=tmp;


            }

             if(p[l].rbt==p[l+1].rbt && p[l].pid>p[l+1].pid)
                {
                tmp=p[l+1];
                p[l+1]=p[l];
                p[l]=tmp;
                }
        }
    }

        /*p[i].rbt--;
        idp=p[i].pid;
        gt[cnt].id=idp;
         gt[cnt].st=time;
         gt[cnt].ct=time2;
         cnt++;*/
         cout<<"short: ";
         for(int t=1;t<=n;t++)
         {
           cout<<p[t].pid<<" ";
         }
         cout<<endl;
         cout<<time<<"---|"<<p[i].pid<<"|---"<<time2<<"---|";
          p[i].rbt--;
        if(p[i].rbt==0)
         {
          i++;
         }


      }


        //cout<< gt[cnt].id<<"--"<< gt[cnt].st<<"--"<< gt[cnt].ct;
       // cout<<p[i].pid<<"  ";




   }
//}


}






int main()
{
    process p[50];
    ganttChart g[50];
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






}

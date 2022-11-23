#include<bits/stdc++.h>
using namespace std;
vector <int> v[200];
queue <int> q;
int vis[200],par[200],level[200];
int check[200];
int cnt=0;
void bfs(int u)
{
    char root,z;
    int x,i;
    vis[u]=1;
    par[u]=-1;
    level[u]=0;
    q.push(u);

    root = (char) u;
    while(!q.empty())
    {
        u = q.front();
        cnt++;
        check[cnt]=u;
        q.pop();
        for(i=0; i<v[u].size(); i++)
        {
            x = v[u][i];
            if(vis[x]== 0)
            {
                vis[x] = 1;
                q.push(x);
                par[x]=u;
                level[x]=level[u]+1;
            }
        }
    }
}

void out(int u)
{
    int a;
    for(int k=1; k<=cnt; k++)
    {
        a = check[k];

        if(par[a]==u)
        {
            cout<<(char)u<<','<<(char)a<<" - "<<level[a]<<endl;
        }
        else if(level[a]!=0)
        {
            cout<<(char)u;
            int h=par[a];
            for(int g=1;g<level[a];g++)
            {
                cout<<','<<(char)h;
                h = par[h];
            }
            cout<<','<<(char)a;
            cout<<" - "<<level[a]<<endl;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int m,i,j,u;
    char x,y,z;
    cin >> m;
    for(int k=1; k<=m; k++)
    {
        cin>>x>>y;

        v[x].push_back(y);

    }
    cin >>z;
    u = z;
    bfs(u);
    out(u);

    return 0;
}



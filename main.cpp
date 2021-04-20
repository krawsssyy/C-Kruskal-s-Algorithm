#include <iostream>
#include <fstream>
using namespace std;
ifstream f("kruskal.in");
ofstream g("kruskal.out");
struct muchie
{
    short x,y,c;
}edge[105];
short n,m;
short arb[105],apm[105][105];
void Citire()
{
    f >> n >> m;
    for(short i=1;i<=m;i++)
     f>>edge[i].x >> edge[i].y >> edge[i].c;
}
void InitArbor()
{
    for(short i=1;i<=n;i++)
        arb[i]=i;
}
void Sort()
{muchie aux;
 for(short i=1;i<m;i++)
     for(short j=i+1;j<=m;j++)
 {
     if(edge[i].c>edge[j].c)
     {
     aux=edge[i];
     edge[i]=edge[j];
     edge[j]=aux;
     }
 }
}
void Kruskal()
{ short k=0,ct=0,i=1;
  while(k<n-1)
  {
      if(arb[edge[i].x]!=arb[edge[i].y])
      {
          k++;
          ct+=edge[i].c;
          apm[edge[i].x][edge[i].y]=1;
          int v=arb[edge[i].y],w=arb[edge[i].x];
          for(short j=1;j<=n;j++)
              if(arb[j]==v)
              arb[j]=w;
      }
      i++;
  }
 g << ct << endl;
}
int main()
{Citire();
 InitArbor();
 Sort();
 Kruskal();
 for(short i=1;i<=n;i++)
     for(short j=1;j<=n;j++)
       if(apm[i][j]==1)
         g << i << " " << j << endl;
 return 0;
}

#include<stdio.h>
#define QTD 9999
#define MAX 5

void dijkstra(float G[MAX][MAX],int n,int inicial);

int main(){
	float gasosa = 6.596;
	float r1,r2,r3,r4,r5,r6,r7;
 	int i,j,u,l,p;
	float G[MAX][MAX];

	for(l=0 ;l < MAX; l++){
   		for( p=0; p< MAX; p++){
    		G[l][p] = -1;//ninguem pode ser menor do que zero
    }
  }
  //RA: 21011038
  r1 = 2 * gasosa;
  r2 = 1 * gasosa;
  r3 = 0 * gasosa;
  r4 = 1 * gasosa;
  r5 = 1 * gasosa;
  r6 = 0 * gasosa;
  r7 = 3 * gasosa;

  G[0][1] = r1;
  G[0][2] = r2;
  G[1][3] = r3;
  G[1][4] = r4;
  G[2][1] = r5;
  G[2][4] = r6;
  G[3][4] = r7;

  for(l=0 ;l < MAX; l++){
    for( p=0; p< MAX; p++){
      printf("%.3f,",G[l][p]);
    }
    printf("\n");
  }

  printf("\nInforme o node inicial:");
  scanf("%d",&u);
  dijkstra(G,MAX,u-1);

  return 0;
}

void dijkstra(float G[MAX][MAX],int n,int inicial)
{
  int custo[n][n],distancia[n],pred[n];
  int visitado[n],cont,distanciamin,proxno,i,j;

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(G[i][j]==-1)
        custo[i][j]=QTD;
      else
        custo[i][j]=G[i][j];

  for(i=0;i<n;i++){
    distancia[i]=custo[inicial][i];
    pred[i]=inicial;
    visitado[i]=0;
  }

  distancia[inicial]=0;
  visitado[inicial]=1;
  cont=1;

  while(cont<n-1){
    distanciamin=QTD;
    for(i=0;i<n;i++)
      if(distancia[i]<distanciamin&&!visitado[i]){
        distanciamin=distancia[i];
        proxno=i;
      }

    visitado[proxno]=1;
    for(i=0;i<n;i++){
      if(!visitado[i])
        if(distanciamin+custo[proxno][i]<distancia[i]){
          distancia[i]=distanciamin+custo[proxno][i];
          pred[i]=proxno;
        }
      }
      cont++;
    }

    for(i=0;i<n;i++)
      if(i!=inicial){
        printf("\nDistancia do no %d = %d",i,distancia[i]);
        printf("\nCaminho = %d",i);

        j=i;
        do{
          j=pred[j];
          printf("<-%d",j);
        }while(j!=inicial);
      }
}

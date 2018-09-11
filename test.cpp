#include <cstdio>
#include<iostream>
using namespace std;
/*
 * 参数row：表示起始行
 * 参数n：表示列数
 * (*chess[8])指向每一行
 */
int notDanger(int row,int j,int(*chess)[8])
{
    int flag1=0,i ,k,flag2=0,flag3=0,flag4=0,flag5=0;
    //判断列方向
    for(i=0;i<8;i++)
    {
        if(*(*(chess+i)+j)!=0)
        {
            flag1 = 1;
            break;
        }
    }
   // 判断左上方
   for(i=row,k=j;i>=0&&k>=0;k--,i--)
   {
        if(*(*(chess+i)+k)!=0)
        {
            flag2 = 1;
            break;
        }
   }
   //判断左下方
   for(i=row,k=j;i<8&&k<8;k++,i++)
   {
        if(*(*(chess+i)+k)!=0)
        {
            flag3 = 1;
            break;
        }
   }
   //判断右上方
   for(i=row,k=j;i>=0&&k<8;k++,i--)
   {
        if(*(*(chess+i)+k)!=0)
        {
            flag4 = 1;
            break;
        }
   }
   //判断右下方
   for(i=row,k=j;i<8&&k>=0;k--,i++)
   {
        if(*(*(chess+i)+k)!=0)
        {
            flag5 = 1;
            break;
        }
   }
   if(flag1 || flag2 || flag3 || flag4 || flag5)
   {
       return 0;
   }
   else
   {
       return 1;
   }
}
int num  = 0;
void EightQueen(int row, int n, int(*chess)[8])
{
    int chess2[8][8], i ,j;
    for(i=0;i<8; i++)
        for(j=0;j<8;j++)
            chess2[i][j] = chess[i][j];
    if(row == 8)
    {
        printf("第 %d 种\n",num+1);
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                printf("%d",chess[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        num++;
    }
    else
    {
        //判断这个位置是否有危险
        //没有危险？继续
        for(j=0;j<8;j++)
        {
            if(notDanger(row, j, chess))
            {
                for(i=0;i<8;i++)
                    *(*(chess2+row)+i)=0;
                *(*(chess2+row)+j)=1;
                EightQueen(row+1,n,chess2);
            }
        }
    }
}
int main()
{
    int chess[8][8],i,j;
 //   memset(chess,0,sizeof(chess));
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            chess[i][j] = 0;
    EightQueen(0, 8, chess);
    printf("总共有 %d 种方法\n\n", num);
    return 0;
}

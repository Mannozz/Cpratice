#include <stdio.h>
#define  true 1
#define false 0

int count = 0;//记录找到的排列方法数
int cmp(int *arr,int row , int col)//比较方法(行，列)
{
        int i;
        for(i = 0 ; i < row ; i++)
        {
                //比较列：确保当前列col 不等于 之前 所有列
                //比较斜线， 确保不出现同一斜率为1或者-1的斜线。(row - i) / (col - arr[i]) != 1 或 -1
                if( col == arr[i] || i - row == col - arr[i] || i - row == arr[i] - col)
                {
                        return false;
                }
        }

        return true;
}//end of cmp

int FindNQueen(int *arr,int k,int n)
{
        int i;
        if(k == n)//找到一种方法
        {
                count++;
                for(i = 0 ; i < n ; i++)
                {
                        printf("%d-", arr[i]+1);
                }
                printf("\n");


        }
        for(i = 0 ; i < n ; i++)
        {
                if(cmp(arr,k,i) == true)//若符合条件
                {
                        arr[k] = i;//记录在K+1行放置第i个皇后
                        FindNQueen(arr,k + 1,n);//递归查找
                }
        }

}//end of FindNQueen


int main(void)
{
        int n;//给定输入的皇后数量
        scanf("%d" , &n);
        int arr[n];
        int i;


       FindNQueen(arr,0,n);

        printf("Total: %d solutions." , count);



}//end of main


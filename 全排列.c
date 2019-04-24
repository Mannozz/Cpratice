#include <stdio.h>
void paint(int a[] , int n)
{
        int i = n;
        for(i = 0 ; i < n ; i++)
        {
                printf("%d-",a[i]);
        }
        printf("\n");
}
void swap(int a[] , int k , int m)
{
        int temp;
        temp = a[k];
        a[k] = a[m];
        a[m] = temp;
}
void perm(int a[] , int k , int m , int n)//全排列函数k、m为0、n
{
        if(k == m)//排至最后一种组合
        {
                paint(a , n);
        }
        else
                {
                        int i = k;
                        for(i = k ; i < m ; i++)// 还有多个元素待排列，递归产生排列,每当i++执行时都已获得了以一个元素为头的全部排列
                        {
                                swap(a , k , i);
                                perm(a , k+1 , m , n);
                                swap(a , k , i);
                                /*
                                【1，3，5，9】（第一个）
                                首先保持第一个不变，对【3，5，9】进行全排列。
                                同样地，我们先保持3不变，对【5，9】进行全排列。
                                保持5不变，对9对进行全排列，由于9只有一个，它的排列只有一种：9。
                                故排列为【1，3，5，9】
                                接下来5不能以5打头了，5，9相互交换，得到
                                【1，3，9，5】
                                此时5，9的情况都写完了，不能以3打头了，得到
                                1，5，3，9
                                1，5，9，3
                                1，9，3，5
                                1，9，5，3
                                这样，我们就得到了1开头的所有排列，这是我们一般的排列数生成的过程。
                                */
                        }
                }

}





int main(void)
{
        int n;
        scanf("%d" , &n);
        int a[n];
        int i =n;
        for(i = 0 ; i < n ; i++)
        {
                scanf("%d" , &a[i]);
        }
        perm(a , 0 , n , n);
        return 0;
}

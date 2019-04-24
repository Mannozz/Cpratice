#include <stdio.h>
typedef struct item
{
        float weight;
}ITEM;

int QuickSort(float a[] , int left , int right)
{
       float key = a[left];//存放基准数,基准数取左边第一个
       int i = left;
       int j = right;
       float temp;

       if(left >= right)
       {
               return 0;
       }

        while(i != j)
        {
                while(a[j] >= key && i < j)//j从右往左,j指向找到的第一个比key大的数
                {
                        j--;
                }
                a[i] = a[j];
                while(a[i] <= key && i < j)//i从左往右,i指向找到的第一个比key小的数
                {
                        i++;
                }
                a[j] = a[i];

        }//到这交换完，此时i = j, a[i]已经排序完成

        //将排序好的a[i]归位

        a[i] = key;


        QuickSort(a , left , i-1);//以a[left]为基准再次对左边部分排序
        QuickSort(a , i+1 , right);//以a[i+1]为基准再次对右边部分排序

}

void Loading(ITEM item[] , float weight)//装载的物品，规定的最大装载重量
{
        int i = 0;
        int n = 0;//记录装载了几个物品
        int realweight = 0;//记录实际装载物品的总重量
        while(weight - item[i].weight > 0)
        {

                weight -= item[i].weight;
                realweight += item[i].weight;
                i++;
                n++;

        }

        printf("可以装进物体%d个，三个物体总重量为%d" , n , realweight);

}

int main(void)
{
        int i,n;
        printf("物体数量n = ");
        scanf("%d" , &n);
        float a[n];
        printf("物体的重量分别为：");
        for(i = 0 ; i < n ; i++)
        {
                scanf("%f" , &a[i]);
        }
        int virtualweight;
        printf("背包能装载的总重量：");
        scanf("%d",&virtualweight);

        ITEM item[n];
        //对n个物体按重量递增排序
        QuickSort(a , 0 , n-1);
        for(i = 0 ; i < n ; i++)
        {
               item[i].weight = a[i];
        }
        Loading(item , virtualweight);

}

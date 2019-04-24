/*求最长公共子序列，用动态规划~
只需建立一个长宽为两个字符串长度+1的二维数组
xy[i][j]表示String a的前i个字符构成的字符串和String b的前j个字符构成的字符串
这两者得到的最长公共子序列的长度为xy[i][j]~~~所以第0行和第0列所有的数都为0~
*/
#include <stdio.h>
int max(int a,int b)
{
        if(a >= b){return a;}
        return b;
}

int main(void)
{
        char x[] = "abcdefghijklmnopqrstuvwxyz0123456789";
        char y[] = "bcikostuz23";

        //获得字符串的长度
        int x_length;
        int y_length;
        for(x_length = 0 ; x[x_length] != NULL ; x_length++){}
        for(y_length = 0 ; y[y_length] != NULL ; y_length++){}

        /*算法可改进之处：在计算c[i][j]时，只用到数组c的第i行和第i-1行。
        因此，用2行的数组空间就可以计算出最长公共子序列的长度。
        进一步的分析还可将空间需求减至O(min(m,n))。*/

        int xy[x_length+1][y_length+1];//用于存放x,y的最长公共子序列的长度,xy[]的大小至少为[x_length+1][y_length+1]

        int i , j;

        for(i = 0 ; i < x_length+1 ; i++)
        {
                for(j = 0 ; j < y_length+1 ; j++)
                {
                        xy[i][j] = 0;
                }
        }


        //求最长公共子序列的长度
        for( i = 1 ; i <= x_length ; i++)
        {
                for( j = 1 ; j <= y_length ; j++)
                {
                        if(x[i-1] == y[j-1])
                        {
                                xy[i][j] = xy[i-1][j-1] + 1;
                        }else{xy[i][j] = max(xy[i][j-1],xy[i-1][j] );  }
                        printf("xy[%d][%d] = %d\n", i , j , xy[i][j]);
                }
        }

        printf("最长公共子序列长度为：%d\n" , xy[x_length][y_length]);
        return 0;
}

#include <vector>
using namespace std;
// 非递归版本的归并排序仅MergeSort函数不同,Merge函数不做修改
const int MAX_LEN = 10086;
vector<int> help(MAX_LEN, 0);
void Merge(vector<int> &arry, int left, int mid, int right);

void MergeSort(vector<int> &arry)
{
    int n = arry.size();
    // 用移位代替乘法提升效率
    for (int left, mid, right, step = 1; step < n; step <<= 1)
    {
        left = 0;
        while (left < n)
        {
            // r....m....r
            // 中间的小点代表step
            mid = left + step - 1;
            if (mid + 1 > n)
            {
                break;
            }
            // 同上
            right = min(left + (step << 1) - 1, n - 1);
            Merge(arry, left, mid, right);
            // 更新left位置,直到这一次循环跑到数组尾巴
            left = right + 1;
        }
    }
}

void Merge(vector<int> &arry, int left, int mid, int right)
{
    // 用于为左边排序定位
    int i = left;
    // 左边区域的索引
    int a = left;
    // 右边区域的索引
    int b = mid + 1;
    while (a <= mid && b <= right)
    {
        // 被拷贝了的就索引加1
        help[i] = arry[a] <= arry[b] ? arry[a++] : arry[b++];
        i++;
    }
    // 将剩余的没拷贝完的部分全部拷贝
    while (a <= mid)
    {
        help[i++] = arry[a++];
    }

    while (b <= right)
    {
        help[i++] = arry[b++];
    }
    // 将辅助数组的值放入传入数组
    for (i = left; i <= right; i++)
    {
        arry[i] = help[i];
    }
}
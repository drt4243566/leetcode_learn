#include <vector>
#include <iostream>
using namespace std;

// 选择排序,不稳定的排序,时间复杂度最好N^2,最坏N^2,平均N^2
void selectSort(vector<int>& a){
    int n = a.size();
    for(int i=0;i<n;i++){
        int k=i;
        // 每一步都找出最小值
        for(int j=i+1;j<n;j++){
            if(a[j]<a[k]) k=j;
        }
        // 将最小值放到排序的末尾
        if(k>i){
            int temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
}
// 冒泡排序，稳定的排序,时间复杂度最好N,最坏N^2,平均N^2
void bubble(vector<int>& a){
    int n = a.size();
    // 控制n-1次的冒泡
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            // 比较相邻的两个元素
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
// 插入排序 时间复杂度最好N,最坏N^2,平均N^2, 稳定
void InsertSort(vector<int>& a){
    int n = a.size();
    // 以第一个元素为基准，从第2个元素开始插入
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            int j=i-1;     // 从i-1开始
            int x = a[i];  // 设置哨兵
            while(j>=0&&x<a[j]){
                a[j+1] = a[j];  // 向右移动，为第i个空出位置
                j--;
            }
            // 当j越界，或者遇到更小的数字，插入到j+1位置
            a[j+1] = x;
        }
    }
}

// 归并排序 -- 稳定排序，时间复杂度O(NlogN)
void merge(vector<int>& a,int L,int mid,int R){
    vector<int> help(R-L+1);
    int i=0,p1=L,p2=mid+1;
    while(p1<=mid&&p2<=R){
        help[i++] = a[p1]<=a[p2]?a[p1++]:a[p2++];
    }
    while(p1<=mid){
        help[i++] = a[p1++];
    }
    while(p2<=R){
        help[i++] = a[p2++];
    }
    for(int i=0;i<help.size();i++){
        a[L+i] = help[i];
    }
}

void GbinSort(vector<int>& a,int L,int R){
    // 范围[L,R],左闭右闭
    if(L==R) return;
    int mid = L+(R-L)/2;
    GbinSort(a,L,mid);
    GbinSort(a,mid+1,R);
    merge(a,L,mid,R);
}

// 堆排序 不稳定，时间复杂度O(NlogN)
void heapInsert(vector<int>& a,int index){  //插入时默认[0,index-1]上已经维持为大根堆
    // 不会发生越界
    while(a[index]>a[(index-1)/2]){
        int temp = a[index];
        a[index] = a[(index-1)/2];
        a[(index-1)/2] = temp;
        index = (index-1)/2;
    }
}
void heapify(vector<int>& a,int index,int heapSize){ //调整时需要知道开始位置和有效区范围 [0,heapSize)
    int left = 2*index+1;
    while(left<heapSize){
        // 保存最大值的索引
        int largest = (left+1)<heapSize&&(a[left]<a[left+1])?left+1:left;
        largest = a[largest]>a[index]?largest:index;
        if(largest==index){
            break;
        }
        int temp = a[largest];
        a[largest] = a[index];
        a[index] = temp;
        index = largest;
        left = 2*index+1;
    }
}
void swap(vector<int>&a,int num1,int num2){
    int temp = a[num1];
    a[num1] = a[num2];
    a[num2] = temp;
}
void heapSort1(vector<int>& a){
    for(int i=0;i<a.size();i++){
        heapInsert(a,i);
    }
    int heapSize = a.size();
    // 交换根节点和最后一个节点
    swap(a,0,--heapSize);
    while(heapSize>0){
        heapify(a,0,heapSize);
        swap(a,0,--heapSize);
    }
}
void heapSort2(vector<int>& a){
    for(int i=a.size()-1;i>=0;i--){
        heapify(a,i,a.size());
    }
    int heapSize = a.size();
    // 交换根节点和最后一个节点
    swap(a,0,--heapSize);
    while(heapSize>0){
        heapify(a,0,heapSize);
        swap(a,0,--heapSize);
    }
}

// 快速排序
vector<int> partition(vector<int>& a,int L,int R){     // 经典划分函数，以数组最后一个元素a[R]作为划分的标准,返回等于区域的左右边界;(这里实际上是左闭右开)
    int less = L-1;
    int more = R;
    // L接触到大于区边界停止
    while(L<more){
        if(a[L]<a[R]) swap(a,++less,L++);
        else if(a[L]>a[R]) swap(a,--more,L);
        else L++;
    }
    swap(a,more,R);
    return {less+1,more};
}
void RandomFastSort(vector<int>& a,int L,int R){   //[L,R]
    if(L<R){
        swap(a,rand()%(R-L+1),R);
        vector<int> p = partition(a,L,R);
        RandomFastSort(a,L,p[0]-1);
        RandomFastSort(a,p[1]+1,R);
    }
}

void printNum(const vector<int> a){
    for(int num:a){
        cout<<num<<" ";
    }
    cout << endl;
}

int main(){
    vector<int> a = {2,3,5,4,6,9,8};
    RandomFastSort(a,0,a.size()-1);
    printNum(a);
}
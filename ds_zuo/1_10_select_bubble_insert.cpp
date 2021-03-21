#include <iostream>
#include <stdio.h>
#include <string>
#define MAXNUM 1000
using namespace std;
struct Student{
    string name;
    int score;
};
int M;
int flag;
Student arr[MAXNUM];

void swap(Student *p1, Student *p2){
    Student temp;
    temp = *p1;
    p1->name = p2->name;
    p1->score = p2->score;
    p2->name = temp.name;
    p2->score = temp.score;
    
}

/****选择排序 不稳定******/
void selectionSort(Student arr[],int N)
{
    int minIndex;
    for(int i=0;i<N-1;i++)
    {
        minIndex = i;
        for(int j=i+1;j<N;j++){
            if(arr[j].score<arr[minIndex].score){
                minIndex = j;
            }
        }
        swap(&arr[i],&arr[minIndex]);
    }
}
/****冒泡排序 稳定******/
void bubbleSort(Student arr[],int N)
{
    for(int i=N-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j].score>arr[j+1].score){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void bubbleSortInv(Student arr[],int N)
{
    for(int i=N-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j].score<arr[j+1].score){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
/****插入排序 稳定******/
void insertionSort(Student arr[],int N)
{
    for(int i=1;i<N;i++)
    {
        Student temp = arr[i];
        int j;
        for(j=i;j>0&&(arr[j-1].score>temp.score);j--)
            arr[j] = arr[j-1];
        arr[j] = temp;
    }
}
int main()
{
    while(cin>>M>>flag)
    {
        for(int i=0;i<M;i++)
        {
            cin>>arr[i].name;
            cin>>arr[i].score;
        }
        if(flag)
        {
            bubbleSort(arr,M);
            //insertionSort(arr,M);
        }
         
        else
        {
            bubbleSortInv(arr,M);
            //insertionSort(arr,M);
        }
        

        for(int i=0;i<M;i++)
        {
            cout<<arr[i].name<<" ";
            cout<<arr[i].score<<endl;
        }
    }
    return 0;
}



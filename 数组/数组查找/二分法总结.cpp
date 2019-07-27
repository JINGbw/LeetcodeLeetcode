#include "mainwindow.h"
#include <QApplication>
#include <vector>
#include <iostream>
using namespace std;
//下面是我的总结：
//0. =key
//1. 第一个等于key
//2.最后一个等于key
//3. 最后一个小于key
//4. 最后一个小于等于key
//5. 第一个大于Key
//6. 第一个大于等于

// dp[mid]< VS <= key
// left = mid+1;

//向左找 <
//向右找 <=


//找到数组中值为key的下标
int binaryk(vector<int>&dp , int left,int right ,int key){
    while (left<=right){
        int mid = (right+left)/2;
        if (dp[mid]==key)
            return mid;
        if (dp[mid]<key)
            left = mid+1;
        else
            right = mid-1;
    }
    return 0;
}

// 1. 找到数组中第一个与key相等的下标
//因为是要找第一个与key相等的，所以当dp[mid]=key的时候，right = mid-1 向左找
int binaryk2(vector<int>&dp , int left,int right ,int key){
    while (left<=right){
        int mid = (right+left)/2;
        //注意，这里因为是第一个，0-1就是-1了，就会超出范围
        //第一个元素是最左边的元素
        if(mid==0&&dp[mid]==key)
            return mid;
        //第一个元素不是最左边的元素
        if(dp[mid-1]<key&&dp[mid]==key)
            return mid;
        if (dp[mid]< key)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}

// 2. 找到数组中最后一个与key相等的下标
//因为是找最后一个，所以 当dp[mid]=key的时候，left = mid+1 向右找
int binaryk3(vector<int>&dp , int left,int right ,int key){
    while (left<=right){
        int mid = (right+left)/2;
        //在最右边
        if (right>=0&&dp[right]==key)
           return right;
        //不在最右边
        if (dp[mid]==key&&dp[mid+1]>key)
            return mid;
        if (dp[mid]<=key)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}
//3. 找到数组中最后一个小于等于key的下标
// 当dp[mid]=key的时候 , 向左找
int binaryk4(vector<int>&dp , int left,int right ,int key){
    while (left<=right){
        int mid = (right+left)/2;
        if(dp[mid]<key &&dp[mid+1]>=key)
            return mid;
        if (dp[mid]< key)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}
//4. 找到数组中最后一个小于等于key的下标
// 向右找
int binaryk5(vector<int>&dp , int left,int right ,int key){
    while (left<=right){
        int mid = (right+left)/2;
        //最右边
        if(right>=0&&dp[right]<=key)
            return right;
        //不在最右边
        if(dp[mid]<=key&&dp[mid+1]>key)
            return mid;
        if (dp[mid]<= key)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}
//5. 找到数组中第一个大于key的下标 大于key的里面最小的
// 相等的时候向右找 <=
int binaryk6(vector<int>&dp , int left,int right ,int key){
    while (left<=right){
        int mid = (right+left)/2;
        //第一个
        if(mid==0&&dp[mid]>key)
            return mid;
        //不是第一个
        if(dp[mid]>key&&dp[mid-1]<=key)
            return mid;
        if (dp[mid]<= key)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}
//6. 找到数组中第一个大于等于key的下标 大于key的里面最小的
//查找第一个等于或者大于key的元素，也就是说等于查找key值的元素有好多个，返回这些元素最左边的元素下标；
//如果没有等于key值的元素，则返回大于key的最左边元素下标。
// 相等的时候向左找
int binaryk7(vector<int>&dp , int left,int right ,int key){
    while (left<=right){
        int mid = (right+left)/2;
        //第一个
        if(mid==0&&dp[mid]>=key)
            return mid;
        //不是第一个
        if(dp[mid]>=key&&dp[mid-1]<key)
            return mid;

        if (dp[mid]< key)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}
int main(int argc, char *argv[])
{

    vector<int>A;
    for(int i =0;i<3;i++){
        A.push_back(0);
    }

    for(int i =0;i<4;i++){
        A.push_back(i);
    }
    for(int i =0;i<3;i++){
        A.push_back(4);
    }
    for(int i =0;i<3;i++){
        A.push_back(5);
    }
    for(int i = 0;i<A.size() ; i++){
        cout<<A[i]<<" ";

    }
    int a = binaryk(A,0,A.size()-1, 3);
    cout<<"key_index:"<<a<<endl;
//第一个等于
    int b = binaryk2(A,0,A.size()-1, 4);//输入5 返10 //输入4返回 //输入0 返回 0
    cout<<"key_index2:"<<b<<endl;
//最后一个等于
    int c = binaryk3(A,0,A.size()-1, 4);//输入5 返回 12 //输入4返回9
    cout<<"key_index3:"<<c<<endl;
//最后一个小与key的
    int d = binaryk4(A,0,A.size()-1,1);//输入5 返回 9 //输入1返回3 //输入4返回6
    cout<<"key_index4:"<<d<<endl;
//最后一个小于等于Key的
    int e = binaryk5(A,0,A.size()-1,8);//输入5 返回 12 //输入1返回3 //输入4返回9//8-12
    cout<<"key_index5:"<<e<<endl;
//第一个一个大于Key的
    int f = binaryk6(A,0,A.size()-1,4);//输入0 返回4  //输入1返回5 //输入4返回10//
    cout<<"key_index6:"<<f<<endl;
//第一个大于等于key的
    int g = binaryk7(A,0,A.size()-1,1);//输入0 返回0 //输入1返回4 //输入5返回10//4-7//
    cout<<"key_index7:"<<g<<endl;

    return 0;
}

/*
    无向图最小路径问题模拟
*/

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector< vector<int> > A(10, vector<int> (10));
unordered_map<int, vector<int>> maps;

vector<int> A0(10); // A0 到达各位置的期望数组

void my_rand(void) { // 随机初始化值
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            A[i][j] = rand() % 100;
        }
    }
}

bool cmpl(vector<int> a, vector<int> b) { // 定义排序规则: 依靠各节点对于目标 A00 的直接距离排序
    return a[0] < b[0];
}

int main(void) {
    my_rand(); //初始化

    sort(A.begin(), A.end(), cmpl); // 排序 在实际应用中 是用有序序列维护 每次在合适的位置插入 二分查找插入复杂度为 long(n)
    A[0][0] = 0; A0[0] = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << A[i][j] << ' '; // 打印结果以便观察
        }
        cout << endl;
    }
    
    for (int i = 1; i < 10; i++) { // 算法主程序: 每次考察下一个到 A00 的直接距离最短的 节点 到 A00 位置的真实最短距离
        int min_ = 100;
        for (int j = 0; j < i; j++) {
            min_ = min(A[i][j] + A0[j], min_); // 使用已经更新好的序列 更新最小值
        }
        A0[i] = min_;
    }

    cout << endl;
    for (int i : A0) {
        cout << i << ' '; // 打印结果
    }
    return 0;
}
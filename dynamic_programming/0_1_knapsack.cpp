// 0-1 Knapsack problem - Dynamic programming
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// void Print(int res[20][20], int i, int j, int capacity)
//{
//	if(i==0 || j==0)
//	{
//		return;
//	}
//	if(res[i-1][j]==res[i][j-1])
//	{
//		if(i<=capacity)
//		{
//			cout<<i<<" ";
//		}
//
//		Print(res, i-1, j-1, capacity-i);
//	}
//	else if(res[i-1][j]>res[i][j-1])
//	{
//		Print(res, i-1,j, capacity);
//	}
//	else if(res[i][j-1]>res[i-1][j])
//	{
//		Print(res, i,j-1, capacity);
//	}
//}
//
template <typename twoD>
void show_table(twoD arr, int row, int col) {
    for(int i=0;i<=row;i++){
        for(int j=0; j<=col; j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int Knapsack2(int capacity, int n, int weight[], int value[]) {
    //int dp[20][20];
    int dp[n+1][capacity+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=capacity; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if (j>=weight[i-1]){
                dp[i][j] = max(dp[i-1][j-weight[i-1]] + value[i-1], dp[i][j-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
                //dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    //show_table(dp, n, capacity);
    for(int i=0;i<=n;i++){
        for(int j=0; j<=capacity; j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    return dp[n][capacity];
}


int Knapsack(int capacity, int n, int weight[], int value[]){
    int dp[capacity+1][n+1];
    for(int i=0;i<=capacity;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(weight[j-1] <= i){
                dp[i][j] = max(dp[i-weight[j-1]][j-1]+value[j-1], dp[i][j-1]);
            }else
                dp[i][j] = dp[i][j-1];
        }
    }
    return dp[capacity][n];
}



int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    int weight[n], value[n];
    cout << "Enter weights: ";
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    cout << "Enter values: ";
    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }
    int capacity;
    cout << "Enter capacity: ";
    cin >> capacity;
    cout << Knapsack2(capacity, n, weight, value);
    return 0;
}

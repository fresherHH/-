//n块积木堆积木，要求上面的积木重量减去下面积木的重量不能超过x，有k块额外积木重量随意变换
//使得积木堆数越少越好
//
//测试样例
//n, k, x   n [1, 200000] x, k[0, 1e9]
//
//13 0 37
//20 20 80 70 70 70 420 5 1 5 1 60 90
//结果3
//
//1 1 5 5 20 20 
//60 70 70 70 80 90
//420
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 2e5 + 10;
int v[N], w[N], s[N], f[N];
int n, x, k, cnt = 0;
// 思路是先将数组进行排序分堆，得出相邻堆之间需要几个额外的积木才能合并，
// 然后用k个积木去填充这些堆，求取填充堆的最大数， 这里可以转化成0 1 背包问题
// 每个堆的价值是 1 体积是需要填充的个数

int main(){
    
    cin >> n >> k >> x;
    for(int i = 0; i < n; i ++) cin >> s[i];
    sort(s, s + n); // 从小到大排序
    
    if(x == 0){
        for(int i = 1; i < n; i ++){
            if(s[i] - s[i - 1] <= x) continue;
            cnt ++;
        }
        cout << cnt + 1 << endl;
    }else{
        for(int i = 1; i < n; i ++){
            if(s[i] - s[i - 1] <= x) continue;
            
            v[cnt] = (s[i] - s[i - 1] - 1) / x; // 相邻堆之间合并需要额外的积木数
            w[cnt ++] = 1;
        }
        
        f[0] = 0;   // f[k] 表示用K个积木最多可以填充多少个堆 
        for(int i = 0; i < n; i ++){
            for(int j = k; j >= s[i]; j --) f[j] = max(f[j], f[j - s[i]] + v[i]);
        }
        cout << cnt + 1 - f[k] << endl;  // 原始堆数是cnt + 1 
    }
    return 0;    
}


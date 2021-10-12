//        3 2 1 2 2 3 的众数个数
//        求出字串的 众数个数与 原始数组的众数个数相同的最短长度
//答案    2 5
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
PII p[N];
int n, s[N];
// 用空间换时间，开一个pair<int,int> p[N], p[i].x, p[i].y 表示数字i 在数组中的最左下标，和最右下标
// 这样只需查表就可以得到结果，时间复杂度是o(n)；
// 题目中给出答案唯一，可能众数不唯一， 最短长度唯一， 如果说明众数唯一的话 可以使用通票法求出众数，左右遍历求出下标；
int main(){
    cin >> n;
    int rmax = 0;
    unordered_map<int, int> h;
    
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
        h[s[i]] ++;    // 记录s[i]出现的次数
        rmax = max(rmax, h[s[i]]);  // 求出众数的个数
        if(p[s[i]].x == 0) p[s[i]].x = i; // s[i] 在数组的最左边下标
        p[s[i]].y = i;                    // s[i] 在数组的最右边下标
    }
    int l = 1, r = n;
    for(auto c : h){
        if(c.y == rmax){
           int tl = p[c.x].x, tr = p[c.x].y;
           if(r - l >= tr - tl) r = tr, l = tl;
        }
    }
    cout << l << ' ' << r << endl;
    return 0;
}

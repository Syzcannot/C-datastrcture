#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int a[50000];
int f[200001];
int v[200001];

void build_tree(int k, int l, int r) {
    v[k] = 0;
    if (l == r) {
        f[k] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build_tree(k + k, l, m);
    build_tree(k + k + 1, m + 1, r);
    f[k] = f[k + k] + f[k + k + 1];
}

////���Ϊk������[l,r]����[x,y] ��ÿ��������z
inline void insert(int k, int l, int r, int x, int y, long long z) {
    if (l == x && r == y) {
        v[k] += z;
        f[k] = f[k]; //���ø�
        return;
    }
    if (v[k]!=0){
        v[k+k]+=v[k];
        v[k+k+1]+=v[k];
        v[k]=0;
    } //����·�

    int m = (l + r) >> 1;
    if (y <= m) insert(k + k, l, m, x, y, z);
    else if (x > m) insert(k + k + 1, m + 1, r, x, y, z);
    else {
        insert(k + k, l, m, x, m, z);
        insert(k + k + 1, m + 1, r, m + 1, y, z);
    }
    f[k]=f[k+k]+v[k+k]*(m-l+1) + f[k+k+1]+v[k+k+1]*(r-m);

}

long long calc(int k, int l, int r, int s, int t) { //�±�Ϊk������[l,r]��������[s,t]�ĺ�,v�ĺ�Ϊp
    if (l == s && r == t) return   f[k]+v[k] * (r - l + 1);
    if (v[k]!=0){
        v[k+k]+=v[k];
        v[k+k+1]+=v[k];
        v[k]=0;
    } //����·�
    int m = (l + r) >> 1;
    long long res=0;
    if (t <= m) res=calc(k + k, l, m, s, t);
    else if (s >= m + 1)  res=calc(k + k + 1, m + 1, r, s, t);
    else res=calc(k + k, l, m, s, m) + calc(k + k + 1, m + 1, r, m + 1, t);
    f[k]=f[k+k]+v[k+k]*(m-l+1) + f[k+k+1]+v[k+k+1]*(r-m);
    return res;
}

////����ǵ��߶���v ��¼�����ڵ�·���ϵ�v����v�·ţ��ݹ����֮�����f
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    return 0;
}

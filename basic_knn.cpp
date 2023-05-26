#include <bits/stdc++.h>

using namespace std;

long double x[17170][17];
long double low[17], high[17], diff[17];
double y[17170];
long double gam = 1.0;

long double dis(int a, int b){
    long double diss = 0.0;
    for(int i = 0; i < 17; ++i) if(x[a][i] != -1.0) diss += fabsl(x[a][i] - x[b][i]);
    return sqrtl(diss);
}


int main(){
    FILE *fin = fopen("train", "rb");
    int tmp;
    vector<int> v;
    set<int> s;
    for(int i = 0; i < 17170; ++i){
        fscanf(fin, "%d", &tmp);
        int cnt = 0;
        for(int j = 0; j < 17; ++j) fscanf(fin, "%Lf", &x[i][j]);
        for(int j = 0; j < 17; ++j) cnt += (x[i][j] == -1.0);
        if(!cnt) v.push_back(i), s.insert(i);
        fscanf(fin, "%lf", &y[i]);
    }
    fclose(fin);
    int err = 0;
    cout << v.size() << endl;
    for(int i = 0; i < 17170; ++i) if(!s.count(i)){
        vector<pair<long double, int>> vv;
        for(int j = 0; j < v.size(); ++j) vv.push_back({dis(i,v[j]), (int)y[v[j]]});
        sort(vv.begin(), vv.end());
        int cnt[10] = {};
        for(int j = 0; j < 20; ++j) cnt[vv[j].second]++;
        int ma = 0;
        for(int j = 1; j < 10; ++j) if(cnt[ma] < cnt[j]) ma = j;
        if(ma != (int)y[i]) err++;
    }
    cout << err << endl;
    return 0;
}

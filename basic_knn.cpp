#include <bits/stdc++.h>

using namespace std;

long double x[17170][17];
long double low[17], high[17], diff[17];
double y[17170];

long double dis(int a, int b){
    long double diss = 0.0;
    for(int i = 0; i < 17; ++i) if(x[a][i] != -1.0) diss += fabsl(x[a][i] - x[b][i]);
    return diss;
}

int main(){
    FILE *fin = fopen("train", "rb");
    FILE *fin2 = fopen("test", "rb");
    vector<int> v;
    set<int> s;
    for(int i = 0; i < 17170; ++i){
        int cnt = 0;
        for(int j = 0; j < 17; ++j) fscanf(fin, "%Lf", &x[i][j]);
        for(int j = 0; j < 17; ++j) cnt += (x[i][j] == -1.0);
        if(!cnt) v.push_back(i), s.insert(i);
        fscanf(fin, "%lf", &y[i]);
    }
    fclose(fin);
    float err = 0.0;
    for(int i = 0; i < 17170; ++i) if(!s.count(i)){
        vector<pair<long double, int>> vv;
        for(int j = 0; j < v.size(); ++j) vv.push_back({dis(i,v[j]), (int)y[v[j]]});
        sort(vv.begin(), vv.end());
        int cnt[10] = {};
        for(int j = 0; j < 5; ++j) cnt[vv[j].second]++;
        int ma = 0;
        for(int j = 1; j < 10; ++j) if(cnt[ma] < cnt[j]) ma = j;
        err += ma > y[i] ? ma - y[i] : y[i] - ma;
    }
    cout << err / 17170<< endl;
    return 0;
}

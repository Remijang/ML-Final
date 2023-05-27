#include <bits/stdc++.h>
#define n 17170 - 9
using namespace std;

long double x[n][17];
double y[n];

long double dis(int a, int b){
    long double diss = 0.0;
    for(int i = 0; i < 17; ++i) if(x[a][i] != -1.0) diss += fabsl(x[a][i] - x[b][i]);
    return diss;
}

int main(){
    FILE *fin = fopen("train.scale", "rb");
    FILE *fout = fopen("train.svm", "wb");
    int tmp;
    vector<int> v;
    set<int> s;
    for(int i = 0; i < n; ++i){
        int cnt = 0;
        for(int j = 0; j < 17; ++j) fscanf(fin, "%Lf", &x[i][j]);
        for(int j = 0; j < 17; ++j) cnt += (x[i][j] == -1.0);
        if(!cnt) v.push_back(i), s.insert(i);
        fscanf(fin, "%lf", &y[i]);
    }
    fclose(fin);
    int siz = N;
    for(int i = 0; i < n; ++i){
        if(!s.count(i)){
            vector<pair<long double, int>> vv;
            for(int j = 0; j < v.size(); ++j) vv.push_back({dis(i,v[j]), v[j]});
            sort(vv.begin(), vv.end());
            long double mean[17];
            for(int j = 0; j < 17; ++j) mean[j] = (long double)0.0;
            for(int j = 0; j < siz; ++j){
                for(int k = 0; k < 17; ++k){
                    mean[k] += x[vv[j].second][k];
                }
            }
            for(int k = 0; k < 17; ++k) if(x[i][k] == (long double)-1.0) x[i][k] = mean[k] / siz;
        }
        if(i) fprintf(fout, "\n");
        fprintf(fout, "%+d ", (int)y[i]);
        for(int k = 0; k < 17; ++k){
            fprintf(fout, "%d:%Lf ", k+1, x[i][k]);
        }
    }
    fclose(fout);
    return 0;
}

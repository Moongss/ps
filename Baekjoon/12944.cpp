#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
const int mx=1000006;
typedef pair<int, pair<int, pair<int, int>>> piii;
vector<piii> v;
int x[mx], l[mx], C[mx];
set<int> s[3];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int i, j;
    cin>>n;
    for(i=0; i<n; i++) cin>>x[i];
    for(i=0; i<n; i++) cin>>l[i];
    for(i=0; i<n; i++){
        char c; cin>>c;
        if(c=='R') c=0;
        if(c=='Y') c=1;
        if(c=='B') c=2;
        C[i]=c;
    }
    for(i=0; i<n; i++){
        v.push_back({x[i]-l[i], {0, {C[i], i+1}}});
        v.push_back({x[i]+l[i], {1, {C[i], i+1}}});
    } sort(v.begin(), v.end());


    for(i=0; i<v.size(); i++){
        int loc, op, color, idx;
        loc=v[i].first;
        op=v[i].second.first;
        color=v[i].second.second.first;
        idx=v[i].second.second.second;
        if(op==0){
            for(j=0; j<3; j++){
                if(color==j) continue;
                if(!s[j].empty()){
                    cout<<"YES\n";
                    cout<<*s[j].begin()<<' '<<idx;
                    return 0;
                }
            }
            s[color].insert(idx);
        }
        else{
            s[color].erase(idx);
        }
    }
    cout<<"NO";
}
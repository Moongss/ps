#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int sa[505050];
int lcp[505050];
int pos[505050];
int tmp[505050];

string s;
int d;

bool cmp(int i, int j) {
    // 1. 처음 SA를 만들때 pos의 의미는 group#임.
    // 2. LCP를 구하기 위해 SA를 만든 뒤에는, pos배열은 SA에서 몇번째에 위치하는지를 의미함.
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i += d; j += d;

    // 조건이 안맞을때, 작은 suffix(앞에와야하는거)가 idx가 큼. 그래서 조건이 I>J
    // 문제 조건에 따라 다르겠지만, suffix 크게하고싶으면 이걸 바꾸면 될듯. group num은 유지하고 i<j로.
    return (i < s.length() && j < s.length()) ? (pos[i] < pos[j]) : (i > j);
}

// SA
void init() {
    // sa: 사전순 정렬된 i번째 접미사(S[i:])의 시작위치
    // pos: i번째 접미사(S[i:])가 SA에서 몇번째에 위치하는지. 약간 역함수 개념.

    for (int i = 0; i < s.length(); i++) {
        sa[i] = i;
        pos[i] = s[i]; // 처음 돌때는 첫 글자를 pos로 잡음.
    }

    for (d=1; ;d*=2) {
        // 길이 d만큼의 suffix상의 prefix를 보고 정렬함.
        // 처음 돌땐 아까 따놨던 첫 글자 기준으로 정렬시킴. 이후 루프를 돌리면서 pos업데이트한걸 재정렬하면서 N개 될때까지 진행.
        sort(sa, sa + s.length(), cmp);

        memset(tmp, 0, sizeof(tmp));
        // 처음엔 pos에 들어가있는 캐릭터('a', 'b' ...)로 체크하고, 다음 글자 체크함. 
        // 두번째, 그리고 그 이후엔 미리 세팅한 그룹번호로 계속 돌림
        for (int i = 0; i < s.length()-1; i++) {
            tmp[i+1] = tmp[i] + cmp(sa[i], sa[i+1]);
        }

        for (int i=0; i < s.length(); i++) {
            pos[sa[i]] = tmp[i];
        }

        if (tmp[s.length()-1] == s.length()-1) break;
    }
}

// LCP
void init2() {
    // 아래가 성립함. 
    // pos[sa[i]] = i.
    // pos has suffix's position(S[i:]) in SA.
    for (int i = 0, k = 0; i < s.length(); i++, k = max(k-1, 0)) {
        // pos : is first SUFFIX?
        // i번째 시작한 suffix가 SA에서 몇번째에 위치하는지 체크하기 위함..
        if (pos[i] == 0) continue;

        // suffix S[i:] pos   : pos[i]
        // suffix S[i+1:] pos : pos[i] + 1
        // and check common prefix

        // do not check i+k<N && j+k<N?
        // 오버플로 안나나 이거? 무조건 안난다고 보장이 되나 null땜에
        for (int j = sa[pos[i]-1]; s[i+k] == s[j+k]; k++) {
            ;
        }

        // cout << "pos[i] : " << pos[i] << ", sa[i] : " << s.substr(sa[pos[i]]) << ", k : " << k << endl;

        // i-th lcp 체크. pos가 약간 중간에서 어뎁터 느낌으로 인덱스를 관리해주니,
        // SA의 위치를 알려주는 pos를 이용해 lcp를 세팅함.
        lcp[pos[i]] = k;
    }
}

int main() {
    fastio;

    cin >> s;
    init();
    init2();
    
    for (int i = 0; i < s.length(); i++) {
        cout << sa[i] + 1<< " ";
    } cout << endl;

    // to debug
    // for (int i = 0; i < s.length(); i++) {
    //     cout << pos[i]<< " ";
    // } cout << endl;

    for (int i = 0; i < s.length(); i++) {
        if (i == 0) cout << "x ";
        else cout << lcp[i] << " ";
    } cout << endl;
    return 0;
}
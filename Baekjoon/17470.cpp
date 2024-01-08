#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M, R;
int arr[100][100];
int tmp[100][100];
int result[100][100];

pii compressMapInfo[4][4];
pii compressMapTmp[4][4];

void input() {
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
}

void compress() {
    int x[] = {0, (N / 2) - 1, N / 2, N - 1};
    int y[] = {0, (M / 2) - 1, M / 2, M - 1};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            compressMapInfo[i][j] = {x[i], y[j]};
        }
    }
}

void rotation(int operate, int W, int H, bool isCompressed) {
    if (operate == 1) {
        for (int i = 0; i < W / 2; i++) {
            for (int j = 0; j < H; j++) {
                if (isCompressed)
                    swap(compressMapInfo[i][j], compressMapInfo[W - i - 1][j]);
                else
                    swap(arr[i][j], arr[W - i - 1][j]);
            }
        }
        return;
    } 
    if (operate == 2) {
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H / 2; j++) {
                if (isCompressed)
                    swap(compressMapInfo[i][j], compressMapInfo[i][H - j - 1]);
                else
                    swap(arr[i][j], arr[i][H - j - 1]);
            }
        }
        return;
    }
    if (operate == 3) {
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                if (isCompressed)
                    compressMapTmp[j][W - i - 1] = compressMapInfo[i][j];
                else
                    tmp[j][W - i - 1] = arr[i][j];
            }
        }
        swap(N, M);
        swap(W, H);
    }
    if (operate == 4) {
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                if (isCompressed)
                    compressMapTmp[H - j - 1][i] = compressMapInfo[i][j];
                else
                    tmp[H - j - 1][i] = arr[i][j];
            }
        }
        swap(N, M); 
        swap(W, H);
    }
    if (operate == 5) {
        int dx[] = {0, 0, W / 2, W / 2};
        int dy[] = {0, H / 2, H / 2, 0};
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < W / 2; i++) {
                for (int j = 0; j < H / 2; j++) {
                    if (isCompressed)
                        compressMapTmp[i + dx[k]][j + dy[k]] = compressMapInfo[i + dx[(k + 3) % 4]][j + dy[(k + 3) % 4]];
                    else
                        tmp[i + dx[k]][j + dy[k]] = arr[i + dx[(k + 3) % 4]][j + dy[(k + 3) % 4]];
                }
            }
        }
    }
    if (operate == 6) {
        int dx[] = {0, 0, W / 2, W / 2};
        int dy[] = {0, H / 2, H / 2, 0};
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i < W / 2; i++) {
                for (int j = 0; j < H / 2; j++) {
                    if (isCompressed)
                        compressMapTmp[i + dx[k]][j + dy[k]] = compressMapInfo[i + dx[(k + 1) % 4]][j + dy[(k + 1) % 4]];
                    else
                        tmp[i + dx[k]][j + dy[k]] = arr[i + dx[(k + 1) % 4]][j + dy[(k + 1) % 4]];
                }
            }
        }
    }

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (isCompressed)
                compressMapInfo[i][j] = compressMapTmp[i][j];
            else
                arr[i][j] = tmp[i][j];
        }
    }
}

void mappingArray(int sX, int sY, int eX, int eY, int squareNum) {
    int arrX[] = {0, 0, N / 2, N / 2};
    int arrY[] = {0, M / 2, 0, M / 2};

    //point (p1, p2, p3)
    //[1] [2]
    //[3]  4
    pii p1 = compressMapInfo[sX][sY];
    pii p2 = compressMapInfo[eX][sY];
    pii p3 = compressMapInfo[sX][eY];

    int p1_X = p1.first, p1_Y = p1.second;
    int p2_X = p2.first, p2_Y = p2.second;
    int p3_X = p3.first, p3_Y = p3.second;

    //1 2
    //3 4
    if (p1_X < p2_X && p1_Y < p3_Y) {
        for (int i = p1_X, X = arrX[squareNum]; i <= p2_X; i++, X++) {
            for (int j = p1_Y, Y = arrY[squareNum]; j <= p3_Y; j++, Y++) {
                result[X][Y] = arr[i][j];
            }
        }
    }

    //2 1
    //4 3
    if (p1_X > p2_X && p1_Y < p3_Y) {
        for (int i = p1_X, X = arrX[squareNum]; i >= p2_X; i--, X++) {
            for (int j = p1_Y, Y = arrY[squareNum]; j <= p3_Y; j++, Y++) {
                result[X][Y] = arr[i][j];
            }
        }
    }

    //4 3
    //2 1
    if (p1_X > p2_X && p1_Y > p3_Y) {
        for (int i = p1_X, X = arrX[squareNum]; i >= p2_X; i--, X++) {
            for (int j = p1_Y, Y = arrY[squareNum]; j >= p3_Y; j--, Y++) {
                result[X][Y] = arr[i][j];
            }
        }
    }

    //3 4
    //1 2
    if (p1_X < p2_X && p1_Y > p3_Y) {
        for (int i = p1_X, X = arrX[squareNum]; i <= p2_X; i++, X++) {
            for (int j = p1_Y, Y = arrY[squareNum]; j >= p3_Y; j--, Y++) {
                result[X][Y] = arr[i][j];
            }
        }
    }

    //ROTATION, (FOR(Y, X) -> [j][i])
    //4 2
    //3 1
    if (p1_X > p3_X && p1_Y > p2_Y) {
        for (int i = p1_Y, X = arrX[squareNum]; i >= p2_Y; i--, X++) {
            for (int j = p1_X, Y = arrY[squareNum]; j >= p3_X; j--, Y++) {
                result[X][Y] = arr[j][i];
            }
        }
    }

    //3 1
    //4 2
    if (p1_X > p3_X && p1_Y < p2_Y) {
        for (int i = p1_Y, X = arrX[squareNum]; i <= p2_Y; i++, X++) {
            for (int j = p1_X, Y = arrY[squareNum]; j >= p3_X; j--, Y++) {
                result[X][Y] = arr[j][i];
            }
        }
    }

    //1 3
    //2 4
    if (p1_X < p3_X && p1_Y < p2_Y) {
        for (int i = p1_Y, X = arrX[squareNum]; i <= p2_Y; i++, X++) {
            for (int j = p1_X, Y = arrY[squareNum]; j <= p3_X; j++, Y++) {
                result[X][Y] = arr[j][i];
            }
        }
    }

    //2 4
    //1 3
    if (p1_X < p3_X && p1_Y > p2_Y) {
        for (int i = p1_Y, X = arrX[squareNum]; i >= p2_Y; i--, X++) {
            for (int j = p1_X, Y = arrY[squareNum]; j <= p3_X; j++, Y++) {
                result[X][Y] = arr[j][i];
            }
        }
    }
}

void print(bool isCompressed) {
    if (!isCompressed) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        mappingArray(0, 0, 1, 1, 0); //top-left square
        mappingArray(0, 2, 1, 3, 1); //top-right square
        mappingArray(2, 0, 3, 1, 2); //bottom-left square
        mappingArray(2, 2, 3, 3, 3); //bottom-right square
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int main() {
    fastio;
    
    input();
    compress();

    bool isCompressed = (N >= 4) && (M >= 4);
    while (R--) {
        int operate; cin >> operate;
        if (isCompressed) 
            rotation(operate, 4, 4, isCompressed);
        else
            rotation(operate, N, M, isCompressed);
    }
    print(isCompressed);
    return 0;
}
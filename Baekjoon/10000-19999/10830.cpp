#include <iostream>

int N;
long long B;
int arr[5][5] = {0, };
int result[5][5] = {0, };

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
}


void matmul(int dest[5][5], int src[5][5]) {

    int tmp[5][5];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < N; k++) {
                tmp[i][j] += (dest[i][k] * src[k][j]) % 1000;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dest[i][j] = tmp[i][j] % 1000;
        }
    }
}


int main() {
    std::cin >> N >> B;

    for (int i = 0; i < N; i++) {
        // 대각행렬 설정
        result[i][i] = 1;
        for (int j = 0; j < N; j++) {
            std::cin >> arr[i][j];
        }
    }

    //분할정복? 재귀로 하지 않아도 되나.. -> 곱셈 순서가 중요하질 않아서?
    //-> 대각행렬 하나로 처리할 수 있어서?
    while (B > 0) {
        //result = arr * arr (arr^2)
        if (B % 2 == 1) {
            matmul(result, arr);
        }
        //result = result * arr 
        matmul(arr, arr);
        B /= 2;
    }

    print();        
    return 0;
}
#include <iostream>
using namespace std;

int N;

int* sorting(int m[]) {
    int max;
    int index;
    for (int i = N-1; i >= 0; i--){
        max = m[i];
        index = i;
        for (int j = 0; j <= i; j++){
            if(m[j] > max){
                max = m[j];
                index = j;
            }
        }
        m[index] = m[i];
        m[i] = max;
    }
    return m;
}

float f(int m[]) {
    m = sorting(m);
    for (int i = 0 ; i < N; i++)
        cout << m[i] << endl;
    return N % 2 == 1 ? float(m[N/2]) : (float(m[N/2]) + float(m[N/2-1]))/2;
}

int main() {
    cout << "N=";
    cin >> N;
    int m[N];
    for (int i = 0; i < N; ++i) {
        cout << "m[" << i << "]=";
        cin >> m[i];
    }
    cout << f(m);
}

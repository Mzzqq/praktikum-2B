#include <iostream>
using namespace std;

const int MAX_N = 100; // ukuran maksimal array

void rotateMatrix(int arr[MAX_N][MAX_N], int N) {
    // memutar array 90 derajat searah jarum jam
    for (int i = 0; i < N/2; i++) {
        for (int j = i; j < N-i-1; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[N-j-1][i];
            arr[N-j-1][i] = arr[N-i-1][N-j-1];
            arr[N-i-1][N-j-1] = arr[j][N-i-1];
            arr[j][N-i-1] = temp;
        }
    }
}

int main() {
    int N; // ukuran array
    int arr[MAX_N][MAX_N]; // deklarasi array
    cout << "Masukkan ukuran array: ";
    cin >> N;

    // meminta input nilai elemen array dari user
    cout << "\nMasukkan nilai elemen array: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "input element array index ke[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    // mencetak nilai array sebelum dirotasi
    cout << "\nArray sebelum dirotasi: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "[ ";
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "]" << endl;
    }

    // memutar array menggunakan function
    rotateMatrix(arr, N);

    // mencetak nilai array setelah dirotasi
    cout << "\nArray setelah dirotasi: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "[ ";
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

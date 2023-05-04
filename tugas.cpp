#include <iostream>
#include <cstring>

using namespace std;

// Definisikan struktur Queue
struct Queue {
    char data;
    Queue* next;
};

// Fungsi enqueue untuk menambahkan elemen ke dalam queue
void enqueue(Queue** rear, Queue** front, char data) {
    // Buat node baru
    Queue* newNode = new Queue;
    newNode->data = data;
    newNode->next = NULL;

    // Jika queue kosong, node baru akan menjadi node pertama dan terakhir
    if (*rear == NULL) {
        *rear = newNode;
        *front = newNode;
    } else {
        // Jika tidak kosong, tambahkan node baru ke ujung rear
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Fungsi dequeue untuk menghapus elemen dari queue dan mengembalikan data yang dihapus
char dequeue(Queue** front) {
    if (*front == NULL) {
        return '\0'; // Jika queue kosong, kembalikan karakter null
    }

    char data = (*front)->data;
    Queue* temp = *front;
    *front = (*front)->next;
    delete temp;

    return data;
}

// Fungsi is_palindrome untuk memeriksa apakah sebuah string merupakan palindrome
bool isPalindrome(string str) {
    Queue* rear = NULL;
    Queue* front = NULL;

    // Masukkan setengah dari string ke dalam queue
    for (int i = 0; i < str.length() / 2; i++) {
        enqueue(&rear, &front, str[i]);
    }

    // Jika panjang string ganjil, lewati karakter tengahnya
    if (str.length() % 2 != 0) {
        dequeue(&front);
    }

    // Bandingkan karakter di queue dengan karakter di sisa string
    while (front != NULL) {
        if (dequeue(&front) != str[str.length() - 1]) {
            return false;
        }
        str.pop_back(); // Hapus karakter terakhir dari string
    }

    return true;
}

int main() {
    string str;
    cout << "Masukkan string: ";
    cin >> str;
    
    if (isPalindrome(str)) {
        cout << str << " adalah palindrome." << endl;
    } else {
        cout << str << " bukan palindrome." << endl;
    }
    return 0;
}

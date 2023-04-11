#include <iostream>

using namespace std;

int compress(char* chars, int n) {
    int i = 0; // pointer untuk menunjuk karakter yang sedang diproses
    int j = 0; // pointer untuk menunjuk posisi hasil kompresi yang akan ditulis
    int count; // jumlah kemunculan karakter yang sedang diproses

    while (i < n) {
        chars[j] = chars[i]; // tulis karakter yang sedang diproses pada posisi hasil kompresi
        count = 1; // reset jumlah kemunculan karakter
        while (i + 1 < n && chars[i] == chars[i+1]) { // hitung kemunculan karakter
            count++;
            i++;
        }
        if (count > 1) { // jika kemunculan karakter lebih dari 1, tambahkan angka setelah karakter
            string count_str = to_string(count);
            for (int k = 0; k < count_str.length(); k++) {
                chars[++j] = count_str[k];
            }
        }
        i++;
        j++;
    }

    return j; // kembalikan panjang array hasil kompresi
}

int main() {
    char chars[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int n = sizeof(chars) / sizeof(chars[0]);

    int len = compress(chars, n);

    cout << "Output: " << len << ", [";
    for (int i = 0; i < len; i++) {
        cout << "\"" << chars[i] << "\"";
        if (i < len-1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}

#include <iostream>

using namespace std;

int compress(char* karakter, int n) {
    int i = 0;
    int j = 0;
    int count;

    while (i < n) {
        karakter[j++] = karakter[i++];
        count = 1;
        while (i < n && karakter[i] == karakter[i-1]) {
            i++;
            count++;
        }
        if (count > 1) {
            string count_str = to_string(count);
            for (char c : count_str) {
                karakter[j++] = c;
            }
        }
    }

    return j;
}

int main() {
    char karakter[] = {'a', 'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int n = sizeof(karakter) / sizeof(karakter[0]);

    int len = compress(karakter, n);

    cout << "Output: " << len << ", [";
    for (int i = 0; i < len; i++) {
        cout << "\"" << karakter[i] << "\"";
        if (i < len-1) {
            cout << ",";
        }
    }

    cout << "]" << endl;

    return 0;
}

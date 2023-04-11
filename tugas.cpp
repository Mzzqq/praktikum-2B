#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struct Nilai
struct nilai {
    int absen;
    int tugas;
    int uts;
    int uas;
    float akhir;
    char huruf;
};

// Struct Mahasiswa
struct mahasiswa {
    string npm;
    string nama;
    nilai nilai;
};

mahasiswa data[20];
int jumlah = 0;

// Fungsi Input
void input() {
    cout << "\nMasukkan jumlah data : ";
    cin >> jumlah;

    // Validasi jumlah data
    while (jumlah > 20){
        cout << "Maksimal 20 Mahasiswa!" << endl;
        cout << "\nMasukkan jumlah data : ";
        cin >> jumlah;
    }

    // Input data
    for (int i = 0; i < jumlah; i++) {
        cout << "Data ke-" << i + 1 << endl;
        cout << "NPM : ";
        cin >> data[i].npm;
        cout << "Nama : ";
        cin >> data[i].nama;
        cout << "Nilai Absen : ";
        cin >> data[i].nilai.absen;
        cout << "Nilai Tugas : ";
        cin >> data[i].nilai.tugas;
        cout << "Nilai UTS : ";
        cin >> data[i].nilai.uts;
        cout << "Nilai UAS : ";
        cin >> data[i].nilai.uas;
        
        // Menghitung nilai akhir
        data[i].nilai.akhir = (data[i].nilai.absen * 0.1) + (data[i].nilai.tugas * 0.2) + (data[i].nilai.uts * 0.3) + (data[i].nilai.uas * 0.4);
        
        // Menghitung nilai huruf
        if (data[i].nilai.akhir > 80) {
            data[i].nilai.huruf = 'A';
        } else if (data[i].nilai.akhir > 70) {
            data[i].nilai.huruf = 'B';
        } else if (data[i].nilai.akhir > 60) {
            data[i].nilai.huruf = 'C';
        } else {
            data[i].nilai.huruf = 'D';
        }
    }
    cout << "\n" << endl;
}

// Fungsi Tampil
void tampil() {
    cout << "\nNPM\tNama\tAbsen\tTugas\tUTS\tUAS\tAkhir\tHuruf" << endl;

    // Tampil data
    for (int i = 0; i < jumlah; i++) {
        cout << data[i].npm << "\t" << data[i].nama << "\t" << data[i].nilai.absen << "\t" << data[i].nilai.tugas << "\t" << data[i].nilai.uts << "\t" << data[i].nilai.uas << "\t" << data[i].nilai.akhir << "\t" << data[i].nilai.huruf << endl;
    }
    cout << "\n" << endl;
}

// Fungsi Edit
void edit() {
    string cari;
    cout << "\nMasukkan NPM yang akan diedit : ";
    cin >> cari;

    // Validasi NPM
    for (int i = 0; i < jumlah; i++) {
        if (data[i].npm == cari) {
            cout << "NPM : ";
            cin >> data[i].npm;
            cout << "Nama : ";
            cin >> data[i].nama;
            cout << "Nilai Absen : ";
            cin >> data[i].nilai.absen;
            cout << "Nilai Tugas : ";
            cin >> data[i].nilai.tugas;
            cout << "Nilai UTS : ";
            cin >> data[i].nilai.uts;
            cout << "Nilai UAS : ";
            cin >> data[i].nilai.uas;
            
            // Menghitung nilai akhir
            data[i].nilai.akhir = (data[i].nilai.absen * 0.1) + (data[i].nilai.tugas * 0.2) + (data[i].nilai.uts * 0.3) + (data[i].nilai.uas * 0.4);
            
            // Menghitung nilai huruf
            if (data[i].nilai.akhir > 80) {
                data[i].nilai.huruf = 'A';
            } else if (data[i].nilai.akhir > 70) {
                data[i].nilai.huruf = 'B';
            } else if (data[i].nilai.akhir > 60) {
                data[i].nilai.huruf = 'C';
            } else {
                data[i].nilai.huruf = 'D';
            }
        }
    }
    cout << "\n" << endl;
}

// Fungsi Hapus
void hapus() {
    string cari;
    cout << "\nMasukkan NPM yang akan dihapus : ";
    cin >> cari;
    
    // Validasi NPM
    for (int i = 0; i < jumlah; i++) {
        if (data[i].npm == cari) {
            for (int j = i; j < jumlah; j++) {
                data[j] = data[j + 1];
            }
            jumlah--;
        }
    }
    cout << "\n" << endl;
}

int main() {
    int pilih;
    
    // Menu
    do {
        cout << "1. Input Data" << endl;
        cout << "2. Tampil Data" << endl;
        cout << "3. Edit Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                input();
                break;
            case 2:
                tampil();
                break;
            case 3:
                edit();
                break;
            case 4:
                hapus();
                break;
            case 5:
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
        }
    } while (pilih != 5);

    return 0;
}

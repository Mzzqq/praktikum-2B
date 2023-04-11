#include <iostream>
using namespace std;

// Membuat struct node untuk menyimpan data dan pointer ke node selanjutnya
struct Node {
  int data;
  Node* next;
};

// Fungsi untuk menambahkan node baru ke linked list
void input(Node** head_ref, int new_data) {
  // Membuat node baru dan mengisi data-nya
  Node* new_node = new Node;
  new_node->data = new_data;
  // Mengisi pointer next-nya dengan NULL
  new_node->next = NULL;

  // Jika linked list kosong, jadikan node baru sebagai head-nya
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  // Jika linked list tidak kosong, iterasi dari head hingga mencapai node terakhir
  Node* last = *head_ref;
  while (last->next != NULL) {
    last = last->next;
  }

  // Tambahkan node baru setelah node terakhir
  last->next = new_node;
  return;
}

// Fungsi untuk mencetak isi linked list
void printList(Node* node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
}

// Fungsi untuk membalik isi linked list
void reverseList(Node** head_ref) {
  Node* current = (*head_ref);
  Node* prev = NULL;
  Node* next = NULL;

  // Iterasi linked list sambil membalik setiap pointer next-nya
  while (current != NULL) {
    next = current->next; // Simpan node selanjutnya sebelum dibalik
    current->next = prev; // Balik pointer next dari node saat ini
    prev = current; // Simpan node saat ini sebagai node sebelumnya
    current = next; // Lanjut ke node selanjutnya
  }

  // Jadikan node terakhir sebagai head linked list
  (*head_ref) = prev;
}

int main() {
  Node* head = NULL;
  int n, data;

  // Meminta jumlah data yang akan dimasukkan
  cout << "Masukkan jumlah data: ";
  cin >> n;

  // Meminta data dan memasukkannya ke linked list
  for (int i = 0; i < n; i++) {
    cout << "Masukkan data ke-" << i+1 << ": ";
    cin >> data;
    input(&head, data);
  }

  // Mencetak isi linked list sebelum dibalik
  cout << "\nList awal: ";
  printList(head);

  // Memanggil fungsi reverseList untuk membalik isi linked list
  reverseList(&head);

  // Mencetak isi linked list setelah dibalik
  cout << "\nList terbalik: ";
  printList(head);

  return 0;
}

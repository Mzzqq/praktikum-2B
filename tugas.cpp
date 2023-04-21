#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *top = NULL;

void push(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = top;   // menambahkan data ke atas tumpukan
    top = temp;
    cout << "Menambahkan " << data << " ke atas tumpukan. Tumpukan saat ini: ";
    node *curr = top;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void pop()
{
    node *temp = top;   // menyimpan data paling atas tumpukan
    top = top->next;    // menghapus data paling atas dari tumpukan
    cout << "Menghapus " << temp->data << " dari atas tumpukan. Tumpukan saat ini: ";
    delete temp;        // menghapus data dari memori
    node *curr = top;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

/*void display()
{
    cout << "Tumpukan saat ini: ";
    node *temp = top;   // menyimpan data paling atas tumpukan
    while (temp != NULL)
    {
        cout << temp->data << " ";  // menampilkan data dari atas ke bawah tumpukan
        temp = temp->next;
    }
    cout << endl;
}*/

void hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "Memindahkan batu " << n * 10 << " dari " << from << " ke " << to << endl;   // kasus dasar untuk satu batu
        pop();
        return;
    }
    hanoi(n - 1, from, aux, to);    // pindahkan n-1 batu dari 'from' ke 'aux', menggunakan 'to' sebagai bantuan
    cout << "Memindahkan batu " << n * 10 << " dari " << from << " ke " << to << endl;   // pindahkan batu n dari 'from' ke 'to'
    pop();
    hanoi(n - 1, aux, to, from);    // pindahkan n-1 batu dari 'aux' ke 'to', menggunakan 'from' sebagai bantuan
}

int main()
{
    int n = 3; // jumlah batu
    for (int i = n; i >= 1; i--)
    {
        push(i*10);    // menambahkan batu ke tumpukan
    }
    //display();
    cout << "\nMenara Hanoi dengan " << n << " batu" << endl;
    hanoi(n, 'A', 'C', 'B');   // memindahkan batu-batu dari tiang A ke tiang C, menggunakan tiang B sebagai bantuan
    getch();
    return 0;
}

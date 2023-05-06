#include <iostream>
#include <cstring>
using namespace std;

 
char stack[20];		        // stack untuk menampung karakter dari string
char queue[20];			    // queue untuk menampung karakter dari string
int top = 0;			    // inisialisasi top dengan nilai 0
int front = -1, rear = -1;	// inisialisasi front dan rear dengan nilai -1

// fungsi untuk menambahkan karakter ke dalam stack
void pushCharacter (char ch){
    top++;
    stack[top] = ch;
} 
 
// fungsi untuk menambahkan karakter ke dalam queue
void enqueueCharacter (char ch){
    if (front == -1){
        front = rear = 0;
        queue[rear] = ch;
    }else{
        rear++;
        queue[rear] = ch;
    }
}

// fungsi untuk mengambil karakter dari stack
char popCharacter (){
    char p;
    p = stack[top];
    top--;
    
    return p;

}

// fungsi untuk mengambil karakter dari queue
char dequeueCharacter (){
    char d;
    d = queue[front];
    front++;
    
    return d;
}

int main (){
    // membaca string s dari input
    string s;
    cout << "Masukkan string: ";
    getline (cin, s);
    
    // menambahkan setiap karakter dari string s ke dalam stack dan queue
    for (int i = 0; i < s.length (); i++){
        pushCharacter (s[i]);
        enqueueCharacter (s[i]);
    } 

    bool isPalindrome = true;
  
  
    //mengambil karakter teratas dari stack dan mengambil karakter pertama dari queue. lalu membandingkan kedua karakter tersebut. 

    for (int i = 0; i < s.length () / 2; i++){
        if (popCharacter () != dequeueCharacter ()){
            isPalindrome = false;
            break;
            
        }
        
    }
  
    // menampilkan apakah string s merupakan palindrome atau tidak
    if (isPalindrome){
        cout << s << ", adalah palindrome.";
        
    }else{
        cout << s << ", bukan palindrome.";
        
    }
    
    return 0;
}

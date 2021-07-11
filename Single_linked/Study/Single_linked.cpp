/* Danh sách liên kết đơn

    |Data|Next| -> |Data|Next| -> |Data|Next| -> Null
    Dữ liệu|pointer -> Dữ liệu|pointer
    Next được gọi là Node:
    Node 1 chứa địa chỉ Node 2!
    Node 2 chứa địa chỉ Node 3! ...
    Node n chứa địa chỉ của Node n (nhưng k pk là đâu) nên return Null

    Uu diem: (so vs mang: vi mang va lien ket don deu la du lieu tuyen tinh)
    - Kích thước của liên kết đơn là kích thước động (co the chen va xoa don gian)
    - Thao tác vơi liên kết đơn nhuần nhuyễn, đơn giản

    Nhuoc diem:
    - Truy cap tuan tu (muon truy cap phan tu ke tiep thi phai biet phan tu phia truoc no)
    - Ton them bo nho de luu tru pointer
    - Khong duoc than thien voi bo nho cache

*/


#include <iostream>
//#include <string>

using namespace std;
//lien ket don su dung kieu du lieu struct
struct Node{ 
    int data; // tuy du lieu minh dung
    Node *next; //pointer dùng liên kết giữa các node với nhau
};

int main() {
    // created 3 Node
    Node *head = new Node();
    head -> data = 1;
    head -> next = NULL;

    Node *second = new Node();
    second -> next = NULL;
    second -> data = 2;

    Node *third = new Node();
    third -> data = 3;
    third -> next = NULL;


    // linking 3 nodes
    head -> next = second;
    second -> next = third;


    // truy cap 
    // phan tu head
    int data = head -> data;
    cout << data << endl;

    //truy cap tat ca phan tu node
    Node *p =head; //temp
    while (p != NULL)
    {
        /* code */
        data = p -> data;
        p = p->next;
        cout << data << " -> ";
    }
    
    
    return 0;
}
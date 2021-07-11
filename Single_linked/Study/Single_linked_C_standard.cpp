#include <iostream>

using namespace std;
// Bai toan: nhap vao danh sach lien ket don. Tim gia tri lon nhat trong danh sach


//---------KHAI BAO DANH SACH LIEN KET DON CAC SO NGUYEN --------------
//Struct cua mot node:  |Data|pNext| -> |Data|pNExt| -> |Data|pNext| -> Null
//                          pHead                           pTail
struct Node
{
    /* data */
    int data; //sử dụng dữ liệu là số nguyên
    struct Node *pNext; //con trỏ đến dữ liệu tiếp theo;

};
typedef struct Node NODE; //thay thế struct Node = NODE;

//tạo danh sách phẩn tử quản lý liên kết (cấu trúc liên kết đơn)
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST; // THAY THE struct list = LIST



//===============KHOI TAO DANH SACH LIEN KET DON ============
void KhoiTao(LIST &l)
{
    //Khởi tạo -> chưa chứa phần tử nào cả
    //cho 2 node trở đến NULL - vì danh sách liên kết đơn chưa có phần tử
    l.pHead = NULL;
    l.pTail = NULL;
}


//HÀM KHỞI TẠO 1 NODE
NODE *KhoiTaoNODE(int x)  //Danh sách so nguyên nên dữ liệu vào là int
{
    NODE *p = new NODE; // cấp phát vùng nhớ cho NODE p
    p -> data = x; // truyền giá trị x vào data
    p -> pNext = NULL; // đầu tiên khai báo node thì node đó chưa có liên kết => con trỏ -> NULL

    return p; //Trả về NODE p vừa khởi tạo
}


//Thêm NODE p vào đầu danh sách
void Themvaodau(LIST &l, NODE *p)
{
    //DANH SÁCH ĐANG RỖNG -> pHead == NULL
    if (l.pHead == NULL)
    {
        /* code */
        l.pHead = l.pTail = p; // node đầu cũng chính là node cuối và là p
    }
    else
    {
        p->pNext = l.pHead; //Cho con trỏ của node cần thêm là node p liên kết đến node đầu - p Head
        l.pHead = p; //pHead chính là node p
    }
}


//Thêm NODE p vào cuối danh sách:
void Themvaocuoi(LIST &l,NODE *p)
{
    //DANH SÁCH ĐANG RỖNG -> pHead == NULL
    if (l.pHead == NULL)
    {
        /* code */
        l.pHead = l.pTail = p; // node đầu cũng chính là node cuối và là p
    }
    else
    {
        l.pTail -> pNext = p; //cho con trỏ của pTail liên kết với p
        l.pTail = p; // cập nhật lại p là node Tail

    }
}



//HÀM XUẤT DANH SÁCH LIÊN KẾT ĐƠN
void xuatDanhSach(LIST l)
{
    // for (int i = 0; i < n; i++)
    for (NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        /* code */
        cout << k->data << " -> ";
    }
    
}



//HAM TIM MAX TRONG DANH SACH LIEN KET DON
int TimMAX(LIST l)
{
    int max = l.pHead->data; //giả sử node đầu là node lớn nhất

    /*bắt đầu duyệt từ node thứ 2*/
    for (NODE *k = l.pHead->pNext; k != NULL ; k = k->pNext) 
    {
        if (max < k->data)
        {
            max = k->data;
        }
        
    }

    return max;
}


int main() {

    LIST l;
    KhoiTao(l); //khởi tạo danh sách liên kết đơn

    int n;
    cout << "\nNHAP SO LUONG NODE CAN THEM: ";
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x;
        cout << "\nNHAP GIA TRI DU LIEU SO NGUYEN X: "; //nhập dữ liệu cho NODE
        cin >> x;
        NODE *p = KhoiTaoNODE(x); //Khởi tạo 1 Node số nguyên
        Themvaodau(l,p); //Thêm NODE p vào đầu danh sách liên kết đơn;
        

    }
    
    cout << "\n\nDANH SACH LIEN KET DON:";
    xuatDanhSach(l);


    cout << "\n\nGIA TRI LON NHAT: " << TimMAX(l);


    return 0;
}
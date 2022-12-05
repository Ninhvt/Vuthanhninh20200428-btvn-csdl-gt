#include <bits/stdc++.h>
using namespace std;

struct Ngay
{
	int ngay, thang, nam;
};

struct SinhVien
{
	char maSV[8];
	char hoTen[50];
	int gioiTinh;
	Ngay ngaySinh;
	char diaChi[100];
	char lop[12];
	char khoa[7];
};

void nhapSinhVien(SinhVien *A)
{
    cout << "ID: "; cin >> A->maSV;
    cout << "Full Name: "; cin >> A->hoTen;
    cout << "SEX: "; cin >> A->gioiTinh;
    cout << "Birthday: "; cin >> A->ngaySinh.ngay >> A->ngaySinh.thang >> A->ngaySinh.nam;
    cout << "Address: "; cin >> A->diaChi;
    cout << "Class: "; cin >> A->lop;
    cout << "Department: "; cin >> A->khoa;
}

void printSV(SinhVien *A)
{
    cout << "ID: " << A.maSV << endl;
    cout << "Full Name: " << A.hoTen << endl;
    cout << "SEX: " << A.gioiTinh << endl;
    cout << "Birthday: " << A.ngaySinh.ngay << "/" << A.ngaySinh.thang << "/" << A.ngaySinh.nam << endl;
    cout << "Address: " << A.diaChi << endl;
    cout << "Class: "  << A.lop << endl;
    cout << "Department: " << A.khoa << endl;
}

struct Node
{
	SinhVien data;
	Node *link;
};

struct List
{
 	Node *first;
	Node *last;
};

//khoi tao danh sach sinh vien
void LIST(List *l) {
    l->first = l->last = NULL;
}

//tao mot node moi
Node* callNode(SinhVien A)
{
    Node* p;
    p = new Node;
    if (p == NULL) return NULL;
    p->data = A;
    p->link = NULL;
    return p;
}

//Gan Node p vao danh sach
void addNode(List* lDT, Node*p) {
    if (lDT->first == NULL) { lDT->first = lDT->last = p;}
    else
    {
        lDT->last->link = p; //gan dia chi nut cuoi bang p
        lDT->last = p; //chuyen p thanh nut cuoi
    }
}

void attachNode(List*lDT, SinhVien A) {
    Node* pDT = callNode(A);
    if (pDT == NULL) return;
    addNode(lDT, pDT);
}

//tao sinh vien
void createList(List *lDT) {
    SinhVien A;
    int i = 0; //dem so phan tu
    cout << "DANH SACH SINH VIEN " << endl ;
    do
    {
    i++;
    cout << "Enter the student number " << i << endl;
    cout << "Enter information about the student " << i << endl;
    nhapSinhVien(&A);
    attachNode(lDT,A);
    cout << endl;
    } while (A.maSV == "");
    cout << "END" << endl;
}

void printList(List lDT) {
    Node* p;
    p = lDT.first;
    while (p != NULL) {
    printSV(p->data);
    p = p->link;
    }
}

int main()
{
    List DS1;
    LIST(&DS1);
    createList(&DS1);
    printList(DS1);
}
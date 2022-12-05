#include <iostream>
#include<string.h>
using namespace std;

struct Ngay
{
    int ngay,thang,nam;
};
struct SinhVien
{
    char MaSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};
struct Node
{
	SinhVien data;
	Node* link;
};

struct LinkedList
{
	Node* first;
	Node* last;
};
Node* Taonode(SinhVien Ninh)
{
	Node* node = new Node;
	node->data = Ninh;
	node->link = NULL;
	return node;
}

void Taonode(LinkedList& l)
{
	l.first = NULL;
	l.last = NULL;
}

void Addnode(LinkedList& l, Node* node)
{
	if (l.first == NULL)
	{
		l.first = node;
		l.last = node;
	}
	else
	{
		node->link = l.first;
		l.first = node;
	}
}

void Add(LinkedList& l, Node* node)
{
	if (l.first == NULL)
	{
		l.first = node;
		l.last = node;
	}
	else
	{
		l.last->link = node;
		l.last = node;
	}
}

void Insert(LinkedList& l, Node* m, Node* n)
{
	if (n != NULL)
	{
	    	cout<<1<<":T";
		m->link = n->link;
		n->link = m;
		if (l.last == n)
			l.last = m;
	}
	else
		Add(l, m);
}

int Xoa(LinkedList& l, SinhVien& A)
{
	if (l.first != NULL)
	{
		Node* node = l.first;
		A = node->data;
		l.first = node->link;
		delete node;
		if (l.first == NULL)
			l.last = NULL;
		return 1;
	}
	return 0;
}

int RemoveAfterQ(LinkedList& l, Node* n, SinhVien& A)
{
	if (n != NULL)
	{
		Node* m = n->link;
		if (m != NULL)
		{
			if (l.last == m)
				l.last = n;
			n->link = m->link;
			A = m->data;
			delete m;
			return 1;
		}
		return 0;
	}
	return 0;
}

Node* GetNode(LinkedList l, int index)
{
	Node* node = l.first;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->link;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
}
void XuatNode(Node* node)
{
    cout << "Ma SV   "<<node->data.MaSV;
	cout <<" Te  "<<node->data.hoTen;
	cout <<" Gioi tinh  "<<node->data.gioiTinh;
	cout <<" Ngay "<<node->data.ngaySinh.ngay;
	cout <<" Thang "<<node->data.ngaySinh.thang;
	cout <<" Nam  "<<node->data.ngaySinh.nam;
    cout <<" Dia chi  "<<node->data.diaChi;
    cout <<" Lop  "<<node->data.lop;
    cout <<" Khoa "<<node->data.khoa<< endl;
			
}
void Inlist(LinkedList l)
{
	if (l.first != NULL)
	{
		Node* node = l.first;
		while (node != NULL)
		{
            XuatNode(node);
			node = node->link;
		}
	}
}


Node* timkiem(LinkedList l, SinhVien A)
{
	Node* node = l.first;
	while (node != NULL && strcmp(node->data.MaSV,A.MaSV)<0)
		{

		node = node->link;
		}
	if (node != NULL)
		return node;
	return NULL;
}
void Sapxeplist(LinkedList &list)
{
  
 for(Node *pTmp=list.first;pTmp!=NULL;pTmp=pTmp->link)
 {

  for(Node *pTmp2=pTmp->link;pTmp2!=NULL;pTmp2=pTmp2->link)
  {
    if(strcmp(pTmp->data.MaSV,pTmp2->data.MaSV)>0) 
     {
       SinhVien tmp=pTmp->data;
       pTmp->data=pTmp2->data;
       pTmp2->data=tmp;
     }
  }
 }
}
int dodailist(LinkedList l)
{
	int count = 0;
	Node* node = l.first;
	while (node != NULL)
	{
		count++;
		node = node->link;
	}
	return count;
}

void Xoalist(LinkedList& l)
{
	SinhVien A;
	Node* node = l.first;
	while (node != NULL)
	{
		Xoa(l, A);
		node = l.first;
	}
	l.last = NULL;
}
void NhapSv(SinhVien &sv)
{
    cout<<"Nhap MaSV: ";fflush(stdin);gets(sv.MaSV);
    cout<<"Nhap HoTen: ";fflush(stdin);gets(sv.hoTen);
    cout<<"Nhap gioi tinh: (Nam:1 Nu:0)";cin>>sv.gioiTinh;
    cout<<"Nhap ngay sinh: ";fflush(stdin);cin>>sv.ngaySinh.ngay;
    cout<<"Nhap thang sinh: ";fflush(stdin);cin>>sv.ngaySinh.thang;
    cout<<"Nhap nam sinh: ";fflush(stdin);cin>>sv.ngaySinh.nam;
    cout<<"Nhap dia chi: ";fflush(stdin);gets(sv.diaChi);
    cout<<"Nhap lop: ";fflush(stdin);gets(sv.lop);
    cout<<"Nhap khoa: ";fflush(stdin);gets(sv.khoa);
}
void SinhViensameNgaySinh(LinkedList list)
{   int len=dodailist(list);
    bool Check[len]={};
    int i=0,j;
    bool checkNull=false;
    cout<<"Danh sach Sinh Vien cung ngay sinh"<<endl;
    for(Node *pTmp=list.first;pTmp!=NULL;pTmp=pTmp->link)
    {
        bool checkdelete=false;
        j=i+1;
        if(!Check[i])
        {
            XuatNode(pTmp);
        }
        for(Node *pTmp2=pTmp->link;pTmp2!=NULL;pTmp2=pTmp2->link)
        {
            if(pTmp->data.ngaySinh.ngay==pTmp2->data.ngaySinh.ngay and !Check[j]) 
            { RemoveAfterQ(list,pTmp2,pTmp->data);
			 XuatNode(pTmp2);
			 Check[j]=true;
			 checkNull=true;
			 checkdelete=true;
            }
            j++;
        }
        if(checkdelete)
        {
            RemoveAfterQ(list,pTmp,pTmp->data);
        }
        i++;
        cout<<"-------------------------------------------------------"<<endl;

    }
    if(!checkNull)
    {
        cout<<"khong co sinh vien nao cung ngay sinh"<<endl;
    }
}
int main()
{
	LinkedList list;
	Taonode(list);
	Node* node;
    SinhVien sv;
    int len1;
    cout<<"Nhap vao so luong danh sach: ";cin>>len1;
	for (auto i = 1; i <=len1; i++)
	{
	    NhapSv(sv);
		node = Taonode(sv);
		Add(list, node);
	}
    Sapxeplist(list);
	Inlist(list);
	cout << endl;
	int len = dodailist(list);
	cout << "Do dai cua list: " << len << endl;
    Xoalist(list);
	return 0;
}
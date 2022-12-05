#include<iostream>
using namespace std;
struct  node
{
    int player;
    struct node*next;
};
struct node *start,*ptr,*new_node;
int main () {
    int M,N,i,count;
   cout << "Nhap N" << endl;
   cin >> N;
   cout << "Nhap M" << endl;
   cin >> M;
   node* start = new node;
   start -> player=1;
   ptr = start;
   for ( i=2; i<=N; i++){
    node* new_node = new node;
    ptr-> next = new_node;
    new_node -> player = i;
    new_node->next=start;
    ptr=new_node;
   }
   for (count = N; count >1; count --){
       for (i=0; i<M; ++i){
       ptr= ptr->next;
       } 
        ptr->next = ptr->next->next;
}
    cout<< " Nguoi thang la "<< ptr->player<< endl;
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
struct LinkedList
{
	int data;
	struct LinkedList * next;
};

typedef struct LinkedList *node; //T? gi? dùng ki?u d? li?u LinkedList có th? thay b?ng node cho ng?n g?n
 
node CreateNode(int value){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // Cap phát vùng nho dùng malloc()
    temp->next = NULL;// Cho next tro toi NULL
    temp->data = value; // Gán giá tri cho Node
    return temp;//Tra ve node moi dã có giá tri
}


//add a node on head of the LinkedList

node addHead(node head, int value){
	node temp = CreateNode(value) ; // Khoi tao node temp voi data = value
	if(head == NULL){
		head = temp; // Neu LinkedList dang trong thi node temp la head luon
	}
	else
	{
		temp->next = head;//tro next cua temp = head hien tai
		head = temp; //head moi ching la temp
	}
	return head;

}

int main(){
	node n1;
	n1 = CreateNode(10);
	printf("data: %d\n", n1->data);

	return 0;
}
/*
Nama Program    : exercise-02
Nama            : Fauzan Akmal Hariz
NPM             : 140810180005
Tanggal buat    : 14 Mei 2019
Deskripsi       : Praktikum - Queue Using Linked List
**********************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct elemen{
	char data[10];
	elemen* next;
};

typedef elemen* pointer;
typedef pointer List;

struct queue{
	List head;
	List tail;
};
queue q;

void createQueue(queue& q)
{
	q.head=NULL;
	q.tail=NULL;
}

void createElement(pointer& pBaru)
{
	pBaru=new elemen;
	cout<<"Data: ";
	cin>>pBaru->data;
	pBaru->next=NULL;
}

void insertQueue(queue& q, pointer pBaru)
{
	if(q.head==NULL && q.tail==NULL)
    {
		q.head=pBaru;
		q.tail=pBaru;
	}
	else
	{
		q.tail->next=pBaru;
		q.tail=pBaru;
	}
}

void deleteQueue(queue& q, pointer& pHapus)
{
	if(q.head==NULL && q.tail==NULL)
    {
		pHapus=NULL;
		cout<<"Queue Kosong, Tidak Ada Yang Dihapus."<<endl;
	}
	else if(q.head->next==NULL)
	{
		pHapus=q.head;
		q.head=NULL;
		q.tail=NULL;
	}
	else
	{
		pHapus=q.head;
		q.head=q.head->next;
		pHapus->next=NULL;
	}
}

void cetakQueue(queue q)
{
	pointer pBantu;
	if(q.head==NULL)
    {
		cout<<"Queue Kosong" <<endl;
	}
	else
	{
		pBantu=q.head;
		cout<<"Data"<<endl;
		do
		{
			cout<<pBantu->data<<endl;
			pBantu=pBantu->next;
		}
		while(pBantu!=q.tail->next);
	}
}

int main()
{
	queue q;
	pointer pBaru, pHapus;
	int pilih;

	cout<<"=======================================================" <<endl;
    cout<<"Selamat Datang Di Program Queue Menggunakan Linked List" <<endl;
    cout<<"=======================================================" <<endl <<endl;
    system("pause");

	createQueue(q);

	do
    {
        system("cls");
        cout<<"===================="<<endl;
		cout<<"   Pilihan Menu     "<<endl;
		cout<<"===================="<<endl;
		cout<<"1. Insert Data"<<endl;
		cout<<"2. Delete Data"<<endl;
		cout<<"3. Cetak Data"<<endl;
		cout<<"4. Keluar"<<endl <<endl;
		cout<<"Silahkan Masukan Pilihan : "; cin>>pilih; cout<<endl;

		switch(pilih)
		{
			case 1:
				createElement(pBaru);
				insertQueue(q,pBaru);
				cout<<"Data berhasil ditambah" <<endl<<endl;
				break;
			case 2:
				deleteQueue(q,pHapus);
				cout<<"Data berhasil dihapus" <<endl<<endl;
				break;
			case 3:
				cetakQueue(q);
				cout<<endl;
				break;
            case 4:
                cout<<"Terima Kasih Telah Menggunakan Program Ini" <<endl;
                return 0;
                break;
            default:
                cout<<"Maaf Pilihan Anda Tidak Tersedia" <<endl;
                break;
		}
        system("pause");
	} while(pilih!=4);
	return 0;
}

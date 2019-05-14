/*
Nama Program    : exercise-01
Nama            : Fauzan Akmal Hariz
NPM             : 140810180005
Tanggal buat    : 14 Mei 2019
Deskripsi       : Praktikum - Queue Using Array
****************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

const int maxElemen=255;

struct elemen
{
	char data[10];
};

struct queue{
	elemen isi[maxElemen];
	int head;
	int tail;
};
queue q;

void createQueue(queue& q)
{
	q.head=0;
	q.tail=-1;
}

void createElement(elemen& baru)
{
	cout<<"Masukkan data: "; cin>>baru.data;
}

void insertQueue(queue& q, elemen baru)
{
	if(q.tail==maxElemen-1)
    {
		cout<<"Antrian penuh"<<endl;
	}
	else
	{
		q.tail = q.tail+1;
		q.isi[q.tail] = baru;
	}
}

void deleteQueue(queue& q, elemen& hapus)
{
    cout<<"Delete Queue (Antrian) "<<endl;
    if (q.head>q.tail)
    {
        cout<<"Antrian kosong"<<endl;
    }
    else
    {
        hapus=q.isi[q.head];
        for (int i=0;i<q.tail;i++)
        {
            q.isi[i]=q.isi[i+1];
        }
        q.tail=q.tail-1;
    }
}

void cetakQueue(queue q)
{
	int i=0;
	cout<<"Data"<<endl;
	while(i!=q.tail+1)
    {
		cout<<q.isi[i].data <<endl;
		i++;
	}
}

int main()
{
	queue q;
	elemen baru,hapus;
	int pilih;

    cout<<"=================================================" <<endl;
    cout<<"Selamat Datang Di Program Queue Menggunakan Array" <<endl;
    cout<<"=================================================" <<endl <<endl;
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

		cout<<"Masukkan pilihan : "; cin>>pilih;

		switch(pilih)
        {
			case 1:
				createElement(baru);
				insertQueue(q,baru);
				cout<<"Data Berhasil Ditambah" <<endl <<endl;
				break;
			case 2:
				deleteQueue(q,hapus);
				cout<<"Data Berhasil Dihapus" <<endl <<endl;
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

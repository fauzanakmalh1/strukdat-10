/*
Nama Program    : exercise-03
Nama            : Fauzan Akmal Hariz
NPM             : 140810180005
Tanggal buat    : 14 Mei 2019
Deskripsi       : Praktikum - Binary Search Tree
*****************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct simpul{
	int info;
	simpul* left;
	simpul* right;
};

typedef simpul* pointer;
typedef pointer Tree;

void createBinaryTree(Tree& root)
{
	root=NULL;
}

void createSimpul(pointer& pBaru)
{
	pBaru=new simpul;
	cout<<"Info	: "; cin>>pBaru->info;
	pBaru->left=pBaru->right=NULL;
}

void insertBST(Tree& root, pointer pBaru)
{
	if(root==NULL)
    {
		root=pBaru;
		cout<<root->info<<" ";
	}
	else if(pBaru->info < root->info)
	{
		insertBST(root->left,pBaru);
		cout<<root->info<<" ";
	}
	else if(pBaru->info > root->info)
	{
		insertBST(root->right,pBaru);
		cout<<root->info<<" ";
	}
	else
	{
		cout<<"Data Sudah Ada"<<endl;
		cout<<root->info<<" ";
	}
}

void preOrder(Tree root)
{
	if(root!=NULL)
    {
		cout<<root->info<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Tree root)
{
	if(root!=NULL){
		inOrder(root->left);
		cout<<root->info<<" ";
		inOrder(root->right);
	}
}

void postOrder(Tree root)
{
	if(root!=NULL)
    {
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->info<<" ";
	}
}

int depth(Tree root)
{
	if(root==NULL)
    {
		return 0;
	}
	int a=depth(root->left);
	int b=depth(root->right);

	if(a>b)
    {
        return a+1;
    }
	else
    {
        return b+1;
    }
}

void tingkat(Tree root, int level)
{
	if(root==NULL)
    {
		return;
	}
	if(level==1)
	{
		cout<<root->info<<" ";
	}
	else if(level>1)
    {
		tingkat(root->left, level-1);
		tingkat(root->right, level-1);
	}
}

void levelOrder(Tree root)
{
    int h=depth(root);
    for(int i=1; i<=h; i++)
    {
    	tingkat(root, i);
    }
}


int main()
{
	Tree root;
	pointer pBaru;
	int pilih;

    cout<<"============================================" <<endl;
    cout<<"Selamat Datang Di Program Binary Search Tree" <<endl;
    cout<<"============================================" <<endl <<endl;
    system("pause");

	createBinaryTree(root);

	do
    {
        system("cls");
        cout<<"========================="<<endl;
		cout<<"        Pilihan Menu     "<<endl;
		cout<<"========================="<<endl;
		cout<<"1. Tambah Data"<<endl;
		cout<<"2. Traversal PreOrder"<<endl;
		cout<<"3. Traversal InOrder"<<endl;
		cout<<"4. Traversal PostOrder"<<endl;
		cout<<"5. Traversal Level Order"<<endl;
		cout<<"6. Kedalaman Pohon"<<endl;
		cout<<"7. Keluar"<<endl <<endl;

		cout<<"Masukkan pilihan : "; cin>>pilih; cout<<endl;

		switch(pilih)
		{
            case 1:
                createSimpul(pBaru);
                insertBST(root,pBaru);
                cout<<endl <<"Data Baru Berhasil Ditambah" <<endl;
                break;
            case 2:
                preOrder(root);
                cout<<endl;
                break;
            case 3:
                inOrder(root);
                cout<<endl;
                break;
            case 4:
                postOrder(root);
                cout<<endl;
                break;
            case 5:
                levelOrder(root);
                cout<<endl;
                break;
            case 6:
                cout<<"Kedalaman pohon : " <<depth(root)<<endl;
                break;
            case 7:
                cout<<"Terima Kasih Telah Menggunakan Program Ini" <<endl;
                return 0;
                break;
            default:
                cout<<"Maaf Pilihan Anda Tidak Tersedia" <<endl;
                break;
        }
        system("pause");
	} while(pilih!=7);
	return 0;
}

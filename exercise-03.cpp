/*
Nama Program    : exercise-03
Nama            : Fauzan Akmal Hariz
NPM             : 140810180005
Tanggal buat    : 14 Mei 2019
Deskripsi       : Praktikum - Binary Search Tree
***********************************************/

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
	cout<<"Masukan Simpul : "; cin>>pBaru->info;
	pBaru->left=NULL;
	pBaru->right=NULL;
}

void insertBST(Tree& root, pointer pBaru)
{
	if(root==NULL)
    {
		root=pBaru;
	}
	else if(pBaru->info < root->info)
	{
		insertBST(root->left,pBaru);
	}
	else if(pBaru->info > root->info)
	{
		insertBST(root->right,pBaru);
	}
	else
	{
		cout<<"Sudah Ada"<<endl;
	}
}

void notasiKurung (Tree root)
{
    if (root!=NULL)
    {
        cout<<"(";
        cout<<root->info <<" ";
        notasiKurung(root->left);
        notasiKurung(root->right);
        cout<<")";
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
	int n, pilih;

    cout<<"============================================" <<endl;
    cout<<"Selamat Datang Di Program Binary Search Tree" <<endl;
    cout<<"============================================" <<endl <<endl;

 	createBinaryTree(root);

    cout<<"Masukan Banyak Simpul : "; cin>>n; cout<<endl;
    for(int i=0; i<n; i++)
    {
        createSimpul(pBaru);
        insertBST(root,pBaru);
    }
    cout<<"Tree : "; notasiKurung(root); cout<<endl;

    system("pause");

	do
    {
        system("cls");
        cout<<"========================="<<endl;
		cout<<"        Pilihan Menu     "<<endl;
		cout<<"========================="<<endl;
		cout<<"1. Traversal PreOrder"<<endl;
		cout<<"2. Traversal InOrder"<<endl;
		cout<<"3. Traversal PostOrder"<<endl;
		cout<<"4. Traversal Level Order"<<endl;
		cout<<"5. Kedalaman Pohon"<<endl;
		cout<<"6. Keluar"<<endl <<endl;

		cout<<"Masukkan pilihan : "; cin>>pilih; cout<<endl;

		switch(pilih)
		{
            case 1:
                preOrder(root);
                cout<<endl;
                break;
            case 2:
                inOrder(root);
                cout<<endl;
                break;
            case 3:
                postOrder(root);
                cout<<endl;
                break;
            case 4:
                levelOrder(root);
                cout<<endl;
                break;
            case 5:
                cout<<"Kedalaman pohon : " <<depth(root)<<endl;
                break;
            case 6:
                cout<<"Terima Kasih Telah Menggunakan Program Ini" <<endl;
                return 0;
                break;
            default:
                cout<<"Maaf Pilihan Anda Tidak Tersedia" <<endl;
                break;
        }
        system("pause");
	} while(pilih!=6);
	return 0;
}

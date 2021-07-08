#include <stdio.h>
#include <stdlib.h>

#include "tree_pegawai.h"

int Menu() {
	
	int x = -1;
	system("cls");
	printf (" PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("1. Cek Semua Data Pegawai\n");
	printf ("2. Tambah Data Pegawai\n");
	printf ("3. Hapus Data Pegawai\n");
	printf ("4. Cari Data Pegawai\n");
	printf ("0. Keluar Aplikasi\n");
	
	scanf ("%d", &x);
	fflush(stdin);
	
	return x;
}

void searchPegawai(Tree *T) {
	infotype X;
	address temp;
	
	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("                 CEK DATA PEGAWAI               \n");
	printf ("ID Pegawai : ");
	scanf ("%d", &X.id);
		
	if(CariPegawaiDenganID(T->root, X.id)==NULL){
		puts("Data pegawai tidak ditemukan");
	}else{
		temp = CariPegawaiDenganID(T->root, X.id);
		puts("Pegawai Ditemukan!!");
		printf("%d %s\n", temp->info.id, temp->info.nama);
	}
	puts("Press Any Key to continue...");
	getch();
}

void removePegawai(address node, Tree T) {
	infotype X;
	
	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("                 HAPUS PEGAWAI               \n");
	printf ("ID Pegawai : ");
	scanf ("%d", &X.id);
		
	HapusPegawai(T,&node);
}

void addPegawai(Tree *root) {
	
	infotype X;
	X.nama = malloc(255);

    printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
    printf ("--------------------------------------------\n");
    printf ("                TAMBAH PEGAWAI               \n");
    printf ("Nama Pegawai : ");
    scanf ("%[^\n]", X.nama);
    fflush(stdin);
    printf ("ID Pegawai : ");
    scanf ("%d", &X.id);
    fflush(stdin);

    TambahPegawai(root,Alokasi(X));
    
    free(X.nama);
}



int main()
{
	int ch;
	Tree T;
	address P;
	infotype data;

	BuatDaftarKosong(&T);
		
	while (1) {
		ch = Menu ();
		switch (ch) {		
			case 1: //Liat Tree
				CetakPegawaiPreorder(T.root);
				getch();
				break;
			case 2: //Tambah Pegawai
				addPegawai(&T);
				break;
			case 3: //Delete Pegawai
				removePegawai(P,T);
				break;
			case 4: //Liat Data pegawai tertentu
				searchPegawai(&T);
				break;
			case 0: //Exit Aplikasi	
				return 0;
		}	
	}
}

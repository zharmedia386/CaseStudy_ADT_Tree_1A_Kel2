#include <stdio.h>
#include <stdlib.h>

#include "tree_pegawai.h"
#include "tree_pegawai.c"

int Menu() {
	
	int x = -1;
	
	printf (" PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("1. Cek Semua Data Pegawai\n");
	printf ("2. Tambah Data Pegawai\n");
	printf ("3. Hapus Data Pegawai\n");
	printf ("4. Cari Data Pegawai\n");
	printf ("0. Cari Data Pegawai\n");
	
	while (x > 4 && x<0)
		scanf ("%d", &x);
	
	return x;
}

void addPegawai(Tree *T) {
	infotype X;
	address temp;
	
	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("                 CEK DATA PEGAWAI               \n");
	printf ("ID Pegawai : \n");
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
	printf ("ID Pegawai : \n");
	scanf ("%d", &X.id);
		
	HapusPegawai(T,&node);
}

void searchPegawai(address node) {
	
	infotype X;
	
	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("                 CEK DATA PEGAWAI               \n");
	printf ("ID Pegawai : \n");
	scanf ("%d", &X.id);
		
	CariPegawaiDenganID(node, &X.id);
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
				CetakPegawaiPreorder(P);
			case 2: //Tambah Pegawai
				addPegawai(&T);
			case 3: //Delete Pegawai
				removePegawai(P,T);
			case 4: //Liat Data pegawai tertentu
				searchPegawai(P);
			case 0: //Exit Aplikasi	
				return 0;
		}	
	}
}

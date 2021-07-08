#include <stdio.h>
#include <stdlib.h>

#include "tree_pegawai.h"
#include "tree_pegawai.c"

void addPegawai() {
	infotype X;
	
	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("--------------------------------------------\n");
	printf ("                TAMBAH PEGAWAI               \n");
	printf ("Nama Pegawai :\n ");
	scanf ("%[^\n]", X.nama);
	fflush(stdin);
	printf ("ID Pegawai : \n");
	scanf ("%d", &X.id);
	fflush(stdin);
	
	TambahPegawai(&root,X);
}

void removePegawai() {
	infotype X;
	
	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("                 HAPUS PEGAWAI               \n");
	printf ("ID Pegawai : \n");
	scanf ("%d", &X.id)
		
	HapusPegawai(&root, address node);
}

void searchPegawai() {
	
	infotype X;
	
	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("                 CEK DATA PEGAWAI               \n")
	printf ("ID Pegawai : \n");
	scanf ("%d", &X.id)
		
	CariPegawaiDenganID(P, id);
}



int main()
{
	int ch;
	Tree T;
	infotype data;

	BuatDaftarKosong(&T, data);
	
	while (1) {
		scanf ("%c", &ch);
		switch (ch) {		
			case 1: //Liat Tree
				CetakPegawaiPreorder(T);
			case 2: //Tambah Pegawai
				addPegawai();
			case 3: //Delete Pegawai
				removePegawai();
			case 4: //Liat Data pegawai tertentu
				searchPegawai();
			case 0: //Exit Aplikasi	
				return 0;
		}	
	}
}

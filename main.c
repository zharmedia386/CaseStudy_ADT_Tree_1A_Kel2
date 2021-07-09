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

	printf("\nPilih : "); scanf ("%d", &x);
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

void removePegawai(Tree daftarPegawai) {
	int id;

	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("                 HAPUS PEGAWAI               \n");
	printf ("ID Pegawai : ");
	scanf  ("%d", &id);

	HapusPegawai(daftarPegawai.root, id);
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

void showPegawai(address root) {
    if(root == NULL) {
        printf("Daftar Pegawai masih kosong\n");
        printf("Tekan apa saja untuk kembali.....\n");
        return;
    }

    printf("\n%-3s   %-12s", "ID", "Nama Pegawai\n");
    CetakPegawaiInorder(root);
    printf("Tekan apa saja untuk kembali.....\n");
}


int main()
{
	int ch;
	Tree daftarPegawai;

	BuatDaftarKosong(&daftarPegawai);

	while (1) {
		ch = Menu ();
		switch (ch) {
			case 1: //Liat Tree
				showPegawai(daftarPegawai.root);
				getch();
				break;
			case 2: //Tambah Pegawai
				addPegawai(&daftarPegawai);
				break;
			case 3: //Delete Pegawai
				removePegawai(daftarPegawai);
				break;
			case 4: //Liat Data pegawai tertentu
				searchPegawai(&daftarPegawai);
				break;
			case 0: //Exit Aplikasi
				return 0;
		}
	}
}

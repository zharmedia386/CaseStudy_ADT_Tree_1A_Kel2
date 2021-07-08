#include <stdio.h>
#include <stdlib.h>

void addPegawai() {
	
	infotype X;
	
	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("--------------------------------------------\n");
	printf ("                TAMBAH PEGAWAI               \n");
	printf ("Nama Pegawai :\n ");
	scanf ("%[^\n]", X.nama);
	fflush(stdin);
	printf ("ID Pegawai : \n");
	scanf ("%d", &X.id)
	fflush(stdin);
	
	TambahPegawai(Tree *root, infotype data);
}

remove removePegawai() {
	
	infotype X;
	
	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("                 HAPUS PEGAWAI               \n");
	printf ("ID Pegawai : \n");
	scanf ("%d", &X.id)
		
	HapusPegawai(Tree *root, address node);
}

remove searchPegawai() {
	
	infotype X;
	
	printf ("PENDATAAN PEGAWAI PERUSAHAAN CIWARUGA CORP\n");
	printf ("------------------------------------------------\n");
	printf ("                 CEK DATA PEGAWAI               \n")
	printf ("ID Pegawai : \n");
	scanf ("%d", &X.id)
		
	CariPegawaiDenganID(Tree P, int id);
}



int main()
{
	int ch;
	Tree T;
	
	CreateEmpty (&T);
	
	while (1) {
		scanf ("%c", &ch);
		switch (ch) {		
			case 1: //Liat Tree
				CetakPegawaiPreorder(Tree P);
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

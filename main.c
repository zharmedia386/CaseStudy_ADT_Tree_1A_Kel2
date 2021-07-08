#include <stdio.h>
#include <stdlib.h>









int main()
{
	int ch;
	Tree T;
	
	CreateEmpty (&T);
	
	
	
	while (1) {
		scanf ("%c", &ch);
		switch (ch) {		
			case 1: //Liat Tree
				CekListPegawai();
			case 2: //Tambah Pegawai
				
			case 3: //Delete Pegawai
			
			case 4: //Liat Data pegawai tertentu
			
			case 0: //Exit Aplikasi	
				return 0;
		}	
	}
	
}

#include "tree_pegawai.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

address Alokasi(infotype X){
	address result = (address)malloc(sizeof(ElmtNode));
	if(!result)
		return NULL;
		
	//menyalin data dari X ke dalam node
	result->info.id = X.id;
	result->info.nama = malloc(strlen(X.nama));
	strcpy(result->info.nama, X.nama);
	
	//mengosongkan pointer child
	result->left = NULL;
	result->right = NULL;
	
	return result;
}

bool isEmpty(tree root){
	return (tree->root);
}

void Dealokasi(address node){
	free(node->info.nama);
	free(node);
}

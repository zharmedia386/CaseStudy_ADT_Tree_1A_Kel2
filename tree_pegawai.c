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

void createEmpty(address root){
	tree->root = NULL;
}

bool isEmpty(Tree root){
	return (root.root);
}

void Dealokasi(address node){
	free(node->info.nama);
	free(node);
}

bool TambahPegawai(Tree *root, address node){
	if(isEmpty(*root)){
		root->root = node;
		return true;
	}

	address current = root;

	while (current != NULL){
		//cek apakah id sama atau tidak
		if(current->info.id == node->info.id)
			return false;

		if(node->info.id < current->info.id)
			current = current->left;
		else
			current = current->right;
	}

	current = node;
	return true;
}

void CetakPegawaiPreorder(Tree P){
	if(P != NULL) {
		printf("Id : %d\n", P.root->info.id);
		printf("Nama : %s\n", P.root->info.nama);
		CetakPegawaiPreorder(P.root->left);
		CetakPegawaiPreorder(P.root->right);
	}
}

void CetakPegawaiInorder(Tree P){
	if(P != NULL) {
		CetakPegawaiInorder(P.root->left);
		printf("Id : %d\n", P.root->info.id);
		printf("Nama : %s\n", P.root->info.nama);
		CetakPegawaiInorder(P.root->right);
	}
}

void CetakPegawaiPostorder(Tree P){
	if(P != NULL) {
		CetakPegawaiPostorder(P.root->left);
		CetakPegawaiPostorder(P.root->right);
		printf("Id : %d\n", P.root->info.id);
		printf("Nama : %s\n", P.root->info.nama);
	}
}

address GetLeft(Tree P){
	return P.root->left;
}

address GetRight(Tree P){
	return P.root->right;
}


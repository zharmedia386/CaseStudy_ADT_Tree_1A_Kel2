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

void BuatDaftarKosong(Tree *P, infotype data){
	address P = Alokasi(data);
	P->root->left = NULL;
	P->root->right = NULL;
	P->root = P;
}

bool isEmpty(Tree root){
	return (root.root);
}

void Dealokasi(address node){
	free(node->info.nama);
	free(node);
}

address GetLeft(Tree P){
	return P.root->left;
}

address GetRight(Tree P){
	return P.root->right;
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

void CetakPegawaiPreorder(address node){
	if(node != NULL) {
		printf("Id : %d\n", node->info.id);
		printf("Nama : %s\n", node->info.nama);
		CetakPegawaiPreorder(node->left);
		CetakPegawaiPreorder(node->right);
	}
}

void CetakPegawaiInorder(address node){
	if(node != NULL) {
		CetakPegawaiInorder(node->left);
		printf("Id : %d\n", node->info.id);
		printf("Nama : %s\n", node->info.nama);
		CetakPegawaiInorder(node->right);
	}
}

void CetakPegawaiPostorder(address node){
	if(node != NULL) {
		CetakPegawaiPostorder(node->left);
		CetakPegawaiPostorder(node->right);
		printf("Id : %d\n", node->info.id);
		printf("Nama : %s\n", node->info.nama);
	}
}

address GetLeft(Tree P){
	return P.root->left;
}

address GetRight(Tree P){
	return P.root->right;
}

address CariPegawaiDenganID(address root, int id){
	if (root->left==Nil && root->right==Nil)
	{
		return Nil;
	}
	else
	{
		if (id == root->info.id) // id yang dicari ditemukan
		{
			return root;
		}
		else
		{
			if (id < root->info.id) // id < Info(root)
			{
				CariPegawaiDenganID(Left(root)), id);
			}
			else
			{ /* id > Info(root)  */
				CariPegawaiDenganID(Right(root)), id);
			}
		}
	}
}

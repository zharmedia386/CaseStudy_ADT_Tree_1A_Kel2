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

bool isEmpty(Tree root){
	return (root.root);
}

void Dealokasi(address node){
	free(node->info.nama);
	free(node);
}

bool AddNode(Tree *root, address node){
	if(isEmpty(*root)){
		root->root = node; 
		return true;
	} 
	
	address current = Tree->root;
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

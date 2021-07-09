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

void BuatDaftarKosong(Tree *P){
	P->root = NULL;
}

bool isEmpty(Tree root){
	return !(root.root);
}

void Dealokasi(address node){
	free(node->info.nama);
	free(node);
}

address GetLeft(address node){
	return node->left;
}

address GetRight(address node){
	return node->right;
}

bool TambahPegawai(Tree *root, address node){
	if(isEmpty(*root)){
		root->root = node;
		return true;
	}
	address current = root->root;
	while (current != NULL){
		//cek apakah id sama atau tidak
		if(current->info.id == node->info.id)
			return false;
		if(node->info.id < current->info.id){
			//jika tidak ada anak, maka masukkan node
			if(current->left == NULL){
				current->left = node;
				return true;
			}
			current = current->left;
		}
		else{
			//jika tidak ada anak, maka masukkan node
			if(current->right == NULL){
				current->right = node;
				return true;
			}
			current = current->right;
		}
	}
	return false;
}

address HapusPegawai(address root, int id) {

    if(root == Nil) {
        printf("tidak ada pegawai dengan id %d\n", id);
        return Nil;
    }

    if(root->info.id < id) {
        root->right = HapusPegawai(root->right, id);
        return root;
    }
    else if (root->info.id > id){
        root->left = HapusPegawai(root->left, id);
        return root;
    }
    else {
        if(root->left == Nil) {
            address temp = root->right;
            Dealokasi(root);
            return temp;
        } else if(root->right == Nil) {
            address temp = root->left;
            Dealokasi(root);
            return temp;
        }

        address temp = MinValue(root->right);
        root->info.id = temp->info.id;
        free(root->info.nama);
        root->info.nama = malloc(strlen(temp->info.nama));
        strcpy(root->info.nama, temp->info.nama);

        root->right = HapusPegawai(root->right, temp->info.id);

        return root;
    }
}

void CetakPegawaiPreorder(address node){
	if(node != NULL) {
		printf("%-3d - %-30s\n", node->info.id, node->info.nama);
		CetakPegawaiPreorder(node->left);
		CetakPegawaiPreorder(node->right);
	}
}

void CetakPegawaiInorder(address node){
	if(node != NULL) {
		CetakPegawaiInorder(node->left);
		printf("%-3d - %-30s\n", node->info.id, node->info.nama);
		CetakPegawaiInorder(node->right);
	}
}

void CetakPegawaiPostorder(address node){
	if(node != NULL) {
		CetakPegawaiPostorder(node->left);
		CetakPegawaiPostorder(node->right);
		printf("%-3d - %-30s\n", node->info.id, node->info.nama);
	}
}

void HapusDaftar(address root) {
    if(root == NULL)
        return;

    HapusDaftar(root->left);
    HapusDaftar(root->right);
    Dealokasi(root);
}

address MinValue(address node) {
    address current = node;

    while(current->left != NULL) {
        current = current->left;
    }

    return current;
}

/* mengemalikan address dari SuccessorInOrder*/
address SuccessorInOrder(Tree P, address node) {
    if(node->right != NULL) {
        return MinValue(node->right);
    }

    address current = P.root;
    address successor = Nil;

    while(current != Nil) {
        if(node->info.id < current->info.id) {
            successor = current;
            current = current->left;
        } else if (node->info.id > current->info.id) {
            current = current->right;
        } else
            break;
    }

    return successor;
}

address CariPegawaiDenganID(address root, int id){
	if (root==Nil)
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
				CariPegawaiDenganID((root->left),id);
			}
			else
			{ /* id > Info(root)  */
				CariPegawaiDenganID((root->right),id);
			}
		}
	}
}

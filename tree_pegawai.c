#include "tree_pegawai.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
* @author :
* @initialState :
* @finaState :
*/
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

/*
* @author :
* @initialState :
* @finaState :
*/
void BuatDaftarKosong(Tree *P){
	P->root = NULL;
}

/*
* @author :
* @initialState :
* @finaState :
*/
bool isEmpty(Tree root){
	return !(root.root);
}

/*
* @author :
* @initialState :
* @finaState :
*/
void Dealokasi(address node){
	free(node->info.nama);
	free(node);
}

/*
* @author :
* @initialState :
* @finaState :
*/
address GetLeft(address node){
	return node->left;
}

address GetRight(address node){
	return node->right;
}

/*
* @author :
* @initialState :
* @finaState :
*/
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

/*
* @author : Reihan Reinaldi Suryaman
* @initialState : Tree terdefinisi, node dengan id : 'id' mungkin saja tidak ada dalam tree
* @finaState : Jika node dengan id : 'id' ada maka node dihapus, jika tidak ada maka tampilkan pesan
*/
address HapusPegawai(Tree *t, address root, int id) {

    //base rekursif, jika mencapai kondisi ini maka node dengan id 'id' tidak ada dalam tree
    if(root == Nil) {
        printf("tidak ada pegawai dengan id %d\n", id);
        return Nil;
    }

    //Cari ke kanan jika id > root->info.id
    if(root->info.id < id) {
        root->right = HapusPegawai(t, root->right, id);
        return root;
    }
    //Cari ke kanan jika id < root->info.id
    else if (root->info.id > id){
        root->left = HapusPegawai(t, root->left, id);
        return root;
    }
    else {
        //Jika root tidak memiliki child left
        if(root->left == Nil) {
            address temp = root->right;
            //Jika root ternyata sama dengan tree root dan child right tidak null, maka child right jadi tree root baru
            if(root == t->root && root->right != Nil) {
                //Menyalin nilai dari child right ke tree root
                t->root->info.id = temp->info.id;
                free(t->root->info.nama);
                t->root->info.nama = malloc(strlen(temp->info.nama));
                strcpy(t->root->info.nama, temp->info.nama);

                //Hapus right child dari tree root
                t->root->right = HapusPegawai(t, t->root->right, temp->info.id);
                return t->root;
            }

            //Jika child right dari tree node null, maka tree menjadi tree kosong
            else if (root == t->root && root->right == Nil) {
                t->root = Nil;
                return Nil;
            }

            //Jika root bukan tree root
            Dealokasi(root);
            return temp;
        }

        //Jika root tidak memiliki child right
        else if(root->right == Nil) {
            address temp = root->left;
             //Jika root ternyata sama dengan tree root dan child left tidak null, maka child left jadi tree root baru
            if(root == t->root && root->left != Nil) {
                //Menyalin nilai dari child right ke tree root
                t->root->info.id = temp->info.id;
                free(t->root->info.nama);
                t->root->info.nama = malloc(strlen(temp->info.nama));
                strcpy(t->root->info.nama, temp->info.nama);

                //Hapus left child dari tree root
                t->root->left = HapusPegawai(t, t->root->left, temp->info.id);
                return t->root;
            }

            //Jika child left dari tree node null, maka tree menjadi tree kosong
            else if (root == t->root && root->left == Nil) {
                t->root = Nil;
                return Nil;
            }

            //Jika root bukan tree root
            Dealokasi(root);
            return temp;
        }

        //root memiliki 2 anak, maka yang menggantikan root adalah inorder successor dari root
        address temp = MinValue(root->right);
        //Menyalin nilai dari inorder successor ke root
        root->info.id = temp->info.id;
        free(root->info.nama);
        root->info.nama = malloc(strlen(temp->info.nama));
        strcpy(root->info.nama, temp->info.nama);

        //hapus inorder successor
        root->right = HapusPegawai(t, root->right, temp->info.id);

        return root;
    }
}

/*
* @author :
* @initialState :
* @finaState :
*/
void CetakPegawaiPreorder(address node){
	if(node != NULL) {
		printf("%-3d - %-30s\n", node->info.id, node->info.nama);
		CetakPegawaiPreorder(node->left);
		CetakPegawaiPreorder(node->right);
	}
}

/*
* @author :
* @initialState :
* @finaState :
*/
void CetakPegawaiInorder(address node){
	if(node != NULL) {
		CetakPegawaiInorder(node->left);
		printf("%-3d - %-30s\n", node->info.id, node->info.nama);
		CetakPegawaiInorder(node->right);
	}
}

/*
* @author :
* @initialState :
* @finaState :
*/
void CetakPegawaiPostorder(address node){
	if(node != NULL) {
		CetakPegawaiPostorder(node->left);
		CetakPegawaiPostorder(node->right);
		printf("%-3d - %-30s\n", node->info.id, node->info.nama);
	}
}

/*
* @author :
* @initialState :
* @finaState :
*/
void HapusDaftar(address root) {
    if(root == NULL)
        return;

    HapusDaftar(root->left);
    HapusDaftar(root->right);
    Dealokasi(root);
}

/*
* @author : Reihan Reinaldi Suryaman
* @initialState : node terdefinisi
* @finaState : mengembalikan nilai paling kecil dari anak anak node
*/
address MinValue(address node) {
    address current = node;

    //node paling kecil ada di anak paling kiri
    while(current->left != NULL) {
        current = current->left;
    }

    return current;
}

/*
* @author : Reihan Reinaldi Suryaman
* @initialState : node terdefinisi, P terdefinisi
* @finaState : mengembalikan successor inorder dari node
*/
address SuccessorInOrder(Tree P, address node) {

    //Jika node memiliki right child maka successor inorder terdapat di nilai paling kecil dari anak anak child right node
    if(node->right != NULL) {
        return MinValue(node->right);
    }

    //Jika tidak memiliki anak kanan, maka successor adalah parent dari node
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

/*
* @author :
* @initialState :
* @finaState :
*/
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

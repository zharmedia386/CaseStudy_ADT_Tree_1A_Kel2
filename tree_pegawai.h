/* File       : bintree.h 	*/
/* Desk       : Deklarasi Binary Tree secara rekursif  	*/
/* Oleh       : ANI RAHMANI / 23501007  			*/
/* Modifikasi : Kelompok 2A / 8 Juli 2021
/* Tgl	      : 21 / 11 / 2001	     			*/

#ifndef TREE_PEGAWAI_H
#define TREE_PEGAWAI_H

#include <stdlib.h>
#include <stdbool.h>

#define Nil NULL
#define Info(P)  (P).root->info
#define Left(P)  (P).root->left
#define Right(P) (P).root->right

typedef struct {
  int id;
  char* nama;
}infotype;

typedef struct tElmtNode *address;

typedef struct tElmtNode {
  infotype info;
  address left;
  address right;
} ElmtNode;

typedef struct{
  address root;
}Tree;

address Alokasi(infotype data);
/* Menghasilkan  address hasil alokasi sebuah  Node 	*/
/* Jika alokasi berhasil, maka  address tidak NIl   	*/
/* Info(P)=data, Left(P)=Nil,Right(P)=Nil	*/
/* Jika alokasi gagal mengembalikan Nil  		*/

void BuatDaftarKosong(Tree *P);
/* membuat tree kosong*/

bool IsEmpty(Tree root);
/* Mengembalikan true jika pohon kosong */

void DeAlokasi(address node);
/*Menghapus satu node di alamat address*/

address GetLeft(address node);
/* Mengirimkan anak kiri pohon biner P  */

address GetRight(address node);
/* Mengirimkan anak kanan pohon biner P  */

bool TambahPegawai(Tree *root, address node);
/* tambah comment nanti */

address HapusPegawai(Tree *t, address root, int id);
/*
* @author : Reihan Reinaldi Suryaman
* @initialState : Tree terdefinisi, node dengan id : 'id' mungkin saja tidak ada dalam tree
* @finaState : Jika node dengan id : 'id' ada maka node dihapus, jika tidak ada maka tampilkan pesan
*/

void CetakPegawaiPreorder(address node);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Preorder; akar, kiri */
/*        kanan (dengan Proses (P)) 				    */

void CetakPegawaiInorder(address node);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Inorder; kiri, akar  */
/*        kanan (dengan Proses (P)) 				    */

void CetakPegawaiPostorder(address node);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Postorder; kiri,     */
/* 	  kanan, akar (dengan Proses (P)) 			    */

address CariPegawaiDenganID(address root, int id);
/* I.S  : root dan id terdefinisi   					    */
/* F.S  : Mengembalikan address node jika id ditemukan  */
/*        Mengembalikan NULL jika id tidak ditemukan */
/* tambah comment nanti */

void HapusDaftar(address root);
/* tambah comment nanti */

address MinValue(address node);
/*
* @author : Reihan Reinaldi Suryaman
* @initialState : node terdefinisi
* @finaState : mengembalikan nilai paling kecil dari anak anak node
*/

address SuccessorInOrder(Tree P, address node);
/*
* @author : Reihan Reinaldi Suryaman
* @initialState : node terdefinisi, P terdefinisi
* @finaState : mengembalikan successor inorder dari node
*/


#endif //TREE_PEGAWAI_H

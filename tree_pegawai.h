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
#define Info(P)  (P)->info
#define Left(P)  (P)->left
#define Right(P) (P)->right

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

typedef address Tree;

address_node Alokasi(infotype data);
/* Menghasilkan  address hasil alokasi sebuah  Node 	*/
/* Jika alokasi berhasil, maka  address tidak NIl   	*/
/* Info(P)=data, Left(P)=Nil,Right(P)=Nil	*/
/* Jika alokasi gagal mengembalikan Nil  		*/

bool IsEmpty(Tree root);
/* Mengembalikan true jika pohon kosong */

void CreateEmpty(Tree root);
/* Membuat  Tree   kosong  */

void DeAlokasi(address node);
/*Menghapus satu node di alamat address*/

address GetLeft(Tree P);
/* Mengirimkan anak kiri pohon biner P  */

address GetRight(Tree P);
/* Mengirimkan anak kanan pohon biner P  */

void AddNode(Tree root, infotype data);
/* tambah comment nanti */

void DeleteNode(Tree root, address node);
/* tambah comment nanti */

void PrintPreorder(Tree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Preorder; akar, kiri */
/*        kanan (dengan Proses (P)) 				    */

void PrintInorder(Tree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Inorder; kiri, akar  */
/*        kanan (dengan Proses (P)) 				    */

void PrintPostorder(Tree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Postorder; kiri,     */
/* 	  kanan, akar (dengan Proses (P)) 			    */
						   */
address SearchNodeByID(Tree P, int id);
/* tambah comment nanti */

void DestructTree(Tree P);
/* tambah comment nanti */

#endif //TREE_PEGAWAI_H

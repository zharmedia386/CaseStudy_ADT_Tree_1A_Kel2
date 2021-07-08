/* File       : bintree.h 	*/
/* Desk       : Deklarasi Binary Tree secara rekursif  	*/
/* Oleh       : ANI RAHMANI / 23501007  			*/
/* Modifikasi : Kelompok 2A / 8 Juli 2021
/* Tgl	      : 21 / 11 / 2001	     			*/

#ifndef TREE_PEGAWAI_H
#define TREE_PEGAWAI_H

#include <stdlib.h>
#include "boolean.h"

#define Nil NULL
#define Info(P)  (P)->info
#define Left(P)  (P)->left
#define Right(P) (P)->right
#define Next(P) (P)->next

typedef structure infotype{
  int id;
  char* nama;
};
typedef struct tElmtNode *address;
typedef struct tElmtNode {
  infotype info;
  address left;
  address right;
} ElmtNode;

typedef address Tree;

address Alokasi(infotype X);
/* Menghasilkan  address hasil alokasi sebuah  Node 	*/
/* Jika alokasi berhasil, maka  address tidak NIl   	*/
/* Info(P)=X, Left(P)=Nil,Right(P)=Nil, dan Count(P)=0 	*/
/* Jika alokasi gagal mengembalikan Nil  		*/

boolean IsEmpty(BinTree P);
/* Mengembalikan true jika pohon kosong */

void CreateEmpty(BinTree *P);
/* Membuat  Tree   kosong  */

infotype GetAkar(BinTree P);
/* Mengirimkan nilai Akar pohon biner P */

BinTree GetLeft(BinTree P);
/* Mengirimkan anak kiri pohon biner P  */

BinTree GetRight(BinTree P);
/* Mengirimkan anak kanan pohon biner P  */

/* ******** KONSTRUKTOR ************ */
BinTree Tree(infotype X, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon Biner dari A, L, dan R jika Alokasi berhasil */
/* Menghasilkan pohon kosong Nil, jika alokasi gagal 			  */

void MakeTree(char Y, BinTree L, BinTree R, BinTree *P);
/* I.S   : Sembarang 	*/
/* F.S   : Menghasilkan sebuah pohon biner P dari A,L,dan R, jika alokasi */
/*         berhasil; Menghasilkan pohon P yang kosong jika alokasi gagal  */

void MakeTree2(infotype X, char Y, BinTree L, BinTree R, BinTree *P);
/* I.S   : Sembarang 	*/
/* F.S   : Menghasilkan sebuah pohon biner P dari A,L,dan R, jika alokasi */
/*         berhasil; Menghasilkan pohon P yang kosong jika alokasi gagal  */


/* ********* PREDIKAT PENTING  **************  */

boolean IsUnerLeft(BinTree P);
/* Mengirimkan True jika pohon biner tidak kosong; P adalah pohon  */
/* unerleft : hanya mempunyai subpohon kiri 			   */

boolean IsUnerRight(BinTree P);
/* Mengirimkan True jika pohon biner tidak kosong; P adalah pohon  */
/* unerright : hanya mempunyai subpohon kanan          		   */

boolean IsBiner(BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong; P adalah pohon */
/* biner : mempunyai subpohon kiri dan subpohon kanan 		  */

/* ************* TRAVERSAL   ************* */

void Preorder(Tree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Preorder; akar, kiri */
/*        kanan (dengan Proses (P)) 				    */

void Inorder(Tree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Inorder; kiri, akar  */
/*        kanan (dengan Proses (P)) 				    */

void Postorder(Tree P);
/* I.S  : P terdefinisi   					    */
/* F.S  : semua simpul P sudah diproses secara Postorder; kiri,     */    
/* 	  kanan, akar (dengan Proses (P)) 			    */

void PrintTree(Tree P);
/* I.S  : P terdefinisi, h adalah jarak indentasi	*/
/* F.S  : semua simpul P sudah ditulis 			*/


/* ************ SEARCH **************** */
boolean Search(Tree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

boolean SearchHur(Tree P, infotype X);
/* Mengirimkan true jika ada node dari P yang berhuruf X */

/* ************* FUNGSI LAIN *************** */
int NbElmt(Tree P);
/* Mengirimkan banyaknya elemen (Node) pohon biner P */

int NbDaun(Tree P);
/* Mengirimkan banyaknya daun (Node) pohon biner P */

boolean IsSkewLeft (Tree P);
/* Mengirimkan true jika P adalah pohon condong kiri */

boolean IsSkewRight(Tree P);
/* Mengirimkan true jika P adalah pohon condong kanan */

int Level(Tree P, infotype X);
/* Mengirinkan level dari Node X yang merupakan salah satu simpul */
/* dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P  tidak */
/* kosong 	*/

/* ********* OPERASI LAIN ********* */
void AddDaunTerkiri(BinTree *P, infotype X);
/* I.S   : P boleh kosong 	*/
/* F.S   : P bertambah simpulnya, dengan X sbg simpul daun terkiri */  		

void AddDaun(Tree *P, infotype X, infotype Y, boolean InputKiri);
/* I.S   : P boleh kosong 	*/
/* F.S   : P bertambah simpulnya, dengan Y sbg anak kiri X 		*/
/*	   jika kiri); atau sebagai anak kanan X (jika Not Kiri)	*/

void DelDaunTerkiri(Tree *P, infotype X);
/* I.S   : P tidak kosong 	*/
/* F.S   : P dihapus   daun terkirinya, dan didealokasi dengan X adalah  */
/*         info yang semula disimpan pada daun terkiri yang dihapus      */

void DelDaun(Tree *P, infotype X);
/* I.S   : P tidak kosong; X adalah salah  satu daun 	*/
/* F.S   : X dihapus dari P    */



address MakeListDaun(BinTree  P);
/* Jika P adalah pohon kosong, maka menghasilkan list kosong   */
/* Jika P bukan pohon kosong, menghasilkan list yang elemennya  */
/* adalah semua daun pohon P; Jika semua alokasi berhasil.      */
/* Menghasilkan list kosong jika ada alokasi yang gagal 	*/

address MakeListPreoder(BinTree  P);
/* Jika P adalah pohon kosong, maka menghasilkan list kosong     */
/* Jika P bukan pohon kosong, menghasilkan list yang elemennya   */
/* adalah semua elemen pohon P dengan urutan Preorder,  jk semua */
/* alokasi berhasil 						 */
/* Menghasilkan list kosong jika ada alokasi yang gagal 	 */


address MakeListLevel(BinTree  P, int N);
/* Jika P adalah pohon kosong, maka menghasilkan list kosong    */
/* Jika P bukan pohon kosong, menghasilkan list yang elemennya  */
/* adalah semua elemen pohon P yang levelnya N; Jika semua      */
/* alokasi berhasil. Menghasilkan list kosong jika ada alokasi  */
/* yang gagal 	*/

/* *********** MEMBENTUK BALANCE TREE ************* */
Tree BuildBalanceTree(int n);
/* Menghasilkan sebuah balance tree dengan n node, nilai setiap node dibaca 							*/

/* ************** TERHADAP BINARY SEARCH TREE *************** */
boolean BSearch(Tree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X   */

void InsSearchTree(Tree *P, infotype X);
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan X. Belum ada simpul P yang bernilai X 			  */

void DelBTree(BinTree *P, infotype X);
/* I.S  : Pohon P tidak kosong 					   */
/* F.S  : Nilai yang dihapus pasti ada, sebuah node dengan nilai X */
/*        dihapus 						   */

#endif //TREE_PEGAWAI_H

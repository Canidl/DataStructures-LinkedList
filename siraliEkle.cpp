#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct siraliEkle{
	int data;
	siraliEkle * next;
};

void ekranaBas(siraliEkle * r){
		while(r != NULL){
		printf("%d\n", r -> data);
		r = r-> next;
		}	
}

siraliEkle * elemanEkle(siraliEkle * r, int eleman){
	siraliEkle * temp= (siraliEkle * ) malloc(sizeof(siraliEkle));	
	temp -> data = eleman;
	if (r -> data > temp -> data) // küçük olma durumu
	{
		temp -> next = r;
		r = temp;
		return r;
	}
	
	siraliEkle * iter = r;
	while(iter -> next != NULL && iter -> next -> data < temp -> data){
		iter = iter -> next;		
	}
	temp -> next = iter -> next;
	iter -> next = temp;
	return r;


}


siraliEkle * elemanSil(siraliEkle * r, int silinecek)
{
	siraliEkle*temp;
	if(r -> data == silinecek){
		temp = r;
		r = r -> next;
		free(temp);
		return r;
	}
	
	siraliEkle * iter = r;
	while (iter -> next != NULL && iter -> next -> data != silinecek){
		iter = iter -> next;		
	}	
	if(iter -> next == NULL){
		printf("Eleman Bulunamadi (%d)\n", silinecek);
		return r;
	}
	temp = iter -> next;
	iter -> next = iter -> next -> next;
	
	free(temp);
	return r;
}




int main(){
	
	siraliEkle * root = (siraliEkle * )malloc(sizeof(siraliEkle));
	root -> data = 166;
	root -> next = NULL;
	
	root = elemanEkle(root,58);
	root = elemanEkle(root,111);
	root = elemanEkle(root,200);
	
	ekranaBas(root);
	
	root = elemanSil(root, 58);
	root = elemanSil(root, 111);
	root = elemanSil(root, 99);
	root = elemanSil(root, 200);
	ekranaBas(root);
	
	
}

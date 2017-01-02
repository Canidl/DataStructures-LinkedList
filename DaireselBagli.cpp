#include<stdio.h>
#include<stdlib.h>
typedef struct daireselBagli{
	int data;
	daireselBagli * next;
};

void ekranaBas(daireselBagli * r){
	printf("%d ", r -> data);
	daireselBagli * iter = r;
	iter = iter -> next;
	while(iter != r){
		printf("%d ", iter -> data);
		iter = iter -> next;
	}
	printf("\n");
}

void elemanEkle(daireselBagli * r, int eleman){
	daireselBagli * iter = r;
	while(iter -> next != r){
		iter = iter -> next;
	}
	iter -> next = (daireselBagli * ) malloc(sizeof(daireselBagli));
	iter -> next -> next = r;
	iter -> next -> data = eleman;
}

daireselBagli * siraliEkle(daireselBagli * r, int eleman){
	daireselBagli * temp = (daireselBagli * )malloc(sizeof(daireselBagli));
	temp -> data = eleman;
	daireselBagli * iter;
	iter = r;
	if(iter -> data > temp -> data){ //kücük olma durumu
		while(iter -> next != r){
			iter = iter -> next;
		}
		temp -> next = r;
		r = temp;
		iter -> next = temp;
		return r;		
	}
	while(iter -> next != r && iter -> next -> data < temp -> data){
		iter = iter -> next;
	}
	temp -> next = iter -> next;
	iter -> next = temp;
	return r;	
}

daireselBagli * elemanSil(daireselBagli * r, int eleman){
	daireselBagli * iter = r;
	daireselBagli * temp;
	if(iter -> data == eleman && iter == r){
		while(iter -> next != r)
		{
			iter = iter -> next;
		}
		temp = r;
		r = r -> next ;
		iter -> next = r;
		free(temp);
		return r;
	}
	while(iter -> next -> data != eleman){
		iter = iter -> next;
	}
	temp = iter -> next;
	iter -> next = temp -> next;
	free(temp);
	return r;
	
}


int main(){
	daireselBagli * root = (daireselBagli * )malloc(sizeof(daireselBagli));
	root -> data = 158;
	root -> next = root;
	
	elemanEkle(root, 172);
	ekranaBas(root);	
	root = siraliEkle(root, 180);
	root = siraliEkle(root, 81);
	root = siraliEkle(root, 160);
	ekranaBas(root);
	
	root = elemanSil(root, 81);
	root = elemanSil(root, 180);
	ekranaBas(root);
}

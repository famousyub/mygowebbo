#include<iostream>
#include <string>
#include<cstdlib>


#include <stdio.h>
#include<string.h>
#include<stdlib.h>




typedef struct Node Node ;




typedef  struct data  data;

struct data  {
      int x ;
      char username[255] ; 
      char password[255] ;
      char  _email[255] ; 
      int duration ;
      char  phonenumber[10];

};


 struct Node   {

      int x ;
      char username[255] ; 
      char password[255] ;
      char  _email[255] ; 
      int duration ;
      char  phonenumber[10];
      Node *next ;

};


void desallocate(Node ** root)
{

    Node *cur = *root ; 
    while (cur!=NULL){
        Node *aux = cur ;
        cur  = cur->next ;
        free(aux);
    }
    *root =NULL;
}



void insert_Atend(Node **root , data _data )
{


   Node  *new_node = (Node *) malloc(sizeof(Node));

   if(new_node ==NULL){

       exit(-1);
   }



   new_node ->next =NULL;
   new_node->x = _data.x;
   new_node->duration = _data.duration ;

   strcpy(new_node->username, _data.username);
     strcpy(new_node->password, _data.password);
       strcpy(new_node->phonenumber, _data.phonenumber);
         strcpy(new_node->_email, _data._email);
       if(*root ==NULL){
        *root = new_node ;
        return;
       }
       Node *cur = *root ;
       while(cur->next !=NULL){
        cur=cur->next ;

       }
       cur->next = new_node;
   
}



void serialize(Node *root)
{

    FILE *file =fopen("filsdata.txt", "a+");

    if(!file) exit(1);
    data _data ;
    Node  *cur  =root ;
    for(cur ; cur!=NULL; cur=cur->next){
         fprintf(file,"<username> : %s  \t <phonenumber : >  %s  <password_ > :  %s <_email :> %s  <value :> %d  <duration > :%d \n" ,cur->username, cur->phonenumber,cur->password, cur->_email,cur->x, cur->duration );


    }
    fclose(file);
}

void deserialize(Node** root) {
    FILE* file = fopen("filsdata.txt", "r");
    if (file == NULL) {
        exit(2);
    }

    int val;
    data cur ;
    while(fscanf(file,"%s %s %s  %s %d %d \n" ,cur.username, cur.phonenumber,cur.password, cur._email,&cur.x, &cur.duration )> 0) {
        insert_Atend(root, cur);
    }
    fclose(file);
}


int main(int argc , const char *argv[])

{

     Node* root = NULL;
    Node* root2 = NULL;
     data data_ ;
     
     printf("enter  username");
     fflush(stdin);
     fflush(stdout);
      scanf("%s",data_.username );


        printf("enter  email");
     fflush(stdin);
     fflush(stdout);
     scanf("%s",data_._email );


        printf("enter  phonenumber  >");
     fflush(stdin);
     fflush(stdout);
 scanf("%s",data_.phonenumber  );

         printf("enter  password");
     fflush(stdin);
     fflush(stdout);
 scanf("%s",data_.password );

    // insert_end(&root, -2);
    // insert_end(&root, 11);
    // insert_end(&root, 22);
    // serialize(root);


     printf("enter  duration   >");
     fflush(stdin);
     fflush(stdout);

     scanf("%d" , &data_.duration );

     data_.x = 1;

 

    insert_Atend(&root, data_);

    serialize(root);



    deserialize(&root);

    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d\n", curr->x);
    }
    
    desallocate(&root);
    // deallocate(&root2);
    
    return 0;
}
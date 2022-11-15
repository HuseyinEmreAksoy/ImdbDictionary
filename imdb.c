#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct Star { 
  char *name;
  char *moviename;

};
struct Star star;
struct Movie { 
  char *name;
  char *starname;  
};

struct Movie movie;

typedef struct Node { 
  struct Star  num; 
  struct Node *next; 
}StarNode;

StarNode *makenode (struct Star x);
void append (StarNode *p);
void delete (StarNode *p);
void insert_after (StarNode *p, StarNode *p2);
void print();
StarNode *search(char *x, char *y);
StarNode *head = NULL;  
StarNode *tail = NULL;
StarNode *makenode (struct Star x) { 
  StarNode *new; 
  if ( (new = (StarNode *) malloc( sizeof(StarNode) ) )!= NULL) { 
    new->num =  x; 
    new -> next = NULL; 
  } 
  else { 
    printf("Out of memory!\n"); 
    exit(0); 
  } 
  return new; 
}
void append (StarNode *p) { 
 
  if (head == NULL) { 
    head = p; 
    tail = p; 
  } 
  else { 
    tail->next = p; 
    tail = p; 
  } 
}
void delete (StarNode *p) { 
  StarNode *tmp, *prev; 
  if ((p == head) && (p == tail)) 
    head = tail = NULL; 
  else if (p == head) 
    head = p->next; 
  else { 
    for(tmp=head, prev=NULL; tmp!=p; prev=tmp, tmp=tmp->next);  
    if (p == tail) 
      tail = prev; 
    prev->next = p->next; 
 } 
 free(p); 
}
/* insert a node p after p2 */ 
void insert_after (StarNode *p, StarNode *p2) { 
  p->next = p2->next; 
 
  if (p2 == tail) 
    tail = p; 
 
  p2->next = p; 
}
void print() { 
  StarNode *tmp; 
  int i = 0; 
  for (tmp = head; tmp != NULL; tmp = tmp->next){
    printf("%d- %s \n", i + 1, tmp->num.name); 
    i++;
    }
    if(i == 0)
    	printf("No star found.\n"); 
  printf("\n"); 
}
void prints(char *x) { 
  StarNode *tmp; 
  int i = 0; 
  for (tmp = head; tmp != NULL; tmp = tmp->next){
  	if (strcmp(tmp->num.name,x) == 0)
		printf("%s,", tmp->num.moviename); 
    i++;
    }
    if(i == 0)
    	printf("No star found.\n"); 
  printf("\n"); 
}
StarNode *search(char *x, char *y) { 
char temp;
  StarNode *tmp;
  int i = 0;
  while(1){
	  for (tmp = head; tmp != NULL; tmp = tmp->next) 
	  	 
	    if (strcmp(tmp->num.name,x) == 0){
		
	    	tmp->num.moviename = y;

	      	return tmp; 
	      	i++;
	      }
	      if(i == 0){
		      	printf("Enter valid star names:");
		      	scanf("%c",&temp);
			scanf("%[^\n]", x);
		     }else
		     	break;
	}
  return NULL; 
}
/////////////////////////////
typedef struct Node2 { 
  struct Movie num2; 
  struct Node2 *next2; 
}MovieNode;

MovieNode *makenode2 (struct Movie x);
void append2 (MovieNode *p);
void delete2 (MovieNode *p);
void insert_after2 (MovieNode *p, MovieNode *p2);
void print2();
MovieNode *search2(char *x, char *y);
MovieNode *head2 = NULL;  
MovieNode *tail2 = NULL;
MovieNode *makenode2 (struct Movie x) { 
  MovieNode *new; 
  if ( (new = (MovieNode *) malloc( sizeof(MovieNode) ) )!= NULL) { 
    new->num2 =  x; 
    new -> next2 = NULL; 
  } 
  else { 
    printf("Out of memory!\n"); 
    exit(0); 
  } 
  return new; 
}
void append2 (MovieNode *p) { 
 
  if (head2 == NULL) { 
    head2 = p; 
    tail2 = p; 
  } 
  else { 
    tail2->next2 = p; 
    tail2 = p; 
  } 
}
void delete2 (MovieNode *p) { 
  MovieNode *tmp, *prev; 
  if ((p == head2) && (p == tail2)) 
    head2 = tail2 = NULL; 
  else if (p == head2) 
    head2 = p->next2; 
  else { 
    for(tmp=head2, prev=NULL; tmp!=p; prev=tmp, tmp=tmp->next2);  
    if (p == tail2) 
      tail2 = prev; 
    prev->next2 = p->next2; 
 } 
 free(p); 
}
/* insert a node p after p2 */ 
void insert_after2 (MovieNode *p, MovieNode *p2) { 
  p->next2 = p2->next2; 
 
  if (p2 == tail2) 
    tail2 = p; 
 
  p2->next2 = p; 
}
void print2() { 
  MovieNode *tmp; 
  int i = 0;
  for (tmp = head2; tmp != NULL; tmp = tmp->next2){
    printf("%d- %s \n", i + 1, tmp->num2.name); 
    i++;
    }
    if(i == 0)
    	printf("No movie found.\n"); 
  printf("\n"); 
}
void printm(char *x) { 
  MovieNode *tmp3; 
  int i = 0; 
  for (tmp3 = head2; tmp3 != NULL; tmp3 = tmp3->next2){
  	if (strcmp(tmp3->num2.name,x) == 0){
    		printf("%s,", tmp3->num2.starname); 
    	}
    i++;
    }
    if(i == 0)
    	printf("No movie found.\n"); 
  printf("\n"); 
}
MovieNode *search2(char *x, char *y) { 
  MovieNode *tmp2;
  int i = 0;
  char temp;
  while(1){
	  for (tmp2 = head2; tmp2 != NULL; tmp2 = tmp2->next2) 
	   	 
	    if (strcmp(tmp2->num2.name,x) == 0){
	    	tmp2->num2.starname = y;
		 
	      	return tmp2;
	      	i++; 
	      }
	      
	    if(i == 0){
	      	printf("Enter valid movie names:");
	      	scanf("%c",&temp);
		scanf("%[^\n]", x);
	     }else
	     	break;
    }
  return NULL; 
}


/////////////////////////////
int main(){
	char c[512];
	char a[512];
	
	char temp;

	while(strcmp(a,"exit") != 0){
		printf("Enter a command:");
		scanf("%s", a);
		while(strcmp(a,"add") != 0 && strcmp(a,"print") != 0 && strcmp(a,"search") != 0 && strcmp(a,"exit") != 0){
		
		printf("Enter a valid command:");
		scanf("%s", a);
		
		}
		if(strcmp("add",a) == 0){
			printf("Enter add type(s/m/r):");
			scanf("%s", c);
			
			if(strcmp("s",c) == 0){
				printf("Enter star names:");
				scanf("%c",&temp);
				scanf("%[^\n]", c);
				int count = strlen(c);
				int i = 0;
				int j;
				for (j=0; j<count; j++)
					if(c[j] == ',')
						i++;
				char *tmp;
				j = 0;
				tmp = strtok(c, ",");
				star.name = strdup(tmp);
				append(makenode(star));
					
				for (int k=0; k < i; k++){
					tmp = strtok(NULL, ",");

				int l;
				    for(l = 0; l < strlen(tmp); l++) {
					*(tmp+l) = *(tmp+l+1);
				    }


					star.name = strdup(tmp);
					append(makenode(star));
				}
			}else if(strcmp("m",c) == 0){
				char s[512];
				printf("Enter movie names:");
				scanf("%c",&temp);
				scanf("%[^\n]",s );
				int count = strlen(s);
				int i = 0;
				int j;
				for (j=0; j<count; j++)
					if(s[j] == ',')
						i++;
				j = 0;
				char *tmp2;
				tmp2 = strtok(s, ",");
				movie.name = strdup(tmp2);
				append2(makenode2(movie));
				
				for (int k=0; k < i; k++){
					tmp2 = strtok(NULL, ",");
					int l;
					    for(l = 0; l < strlen(tmp2); l++) {
						*(tmp2+l) = *(tmp2+l+1);
					    }

					movie.name = strdup(tmp2);
					append2(makenode2(movie));
				}
			}
			else if(strcmp("r",c) == 0){
				char s[512];
				printf("Enter star names:");
				scanf("%c",&temp);
				scanf("%[^\n]", c );
				
				char *tmp2;
				int count = strlen(c);
				int i = 0;
				int j;
				for (j=0; j<count; j++)
					if(c[j] == ',')
						i++;
				
				tmp2 = strtok(c, ",");

				search(tmp2,s);
				for (int k=0; k < i; k++){
					
					tmp2 = strtok(NULL, ",");
					int l;
				    	for(l = 0; l < strlen(tmp2); l++) {
						*(tmp2+l) = *(tmp2+l+1);
				    	}
					search(tmp2,s);
				}
				printf("Enter movie names:");
				scanf("%c",&temp);
				scanf("%[^\n]",s );

				
				count = strlen(s);
				int i2 = 0;
				for (j=0; j<count; j++)
					if(s[j] == ',')
						i2++;


				char *tmp;
			
				j = 0;
				tmp = strtok(s, ",");

				search2(tmp,c);
				for (int k=0; k < i2; k++){
					
					tmp = strtok(NULL, ",");
					int l;
					    for(l = 0; l < strlen(tmp); l++) {
						*(tmp+l) = *(tmp+l+1);
					    }
					search2(tmp,c);
				}
		
				


				
			}
		
		}
		else if (strcmp("print",a) == 0){
			printf("Enter print type(s/m):");
			scanf("%s", c);
			if(strcmp("s",c) == 0)
				print();
			else if(strcmp("m",c) == 0)
				print2();
			
		}
		else if (strcmp("search",a) == 0){
			printf("Enter search type(s/m):");
				scanf("%s", c);
				if(strcmp("s",c) == 0){
					printf("Enter movie names:");
					scanf("%c",&temp);
					scanf("%[^\n]", c);
					printm(c);
				}
				else if(strcmp("m",c) == 0){
					printf("Enter star names:");
					scanf("%c",&temp);
					scanf("%[^\n]", c);
					prints(c);
				}
		}
	}

	return 0;
}

/*
Author : M.M.M.RILWAN (E/17/292)

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct NODE_T {
	double wrdamt;
	char  wrd[100];
	struct NODE_T * wnext;
} NODE;

typedef struct node_t {
	double chramt;
	char chr;
	struct node_t * cnext;
} node;


int main(int argc, char **argv){


		int ag,bg,cg;
		int b2,b3,t2;
		double dg;
// new
		FILE *txt, *fout, *fin;
				int z,z1,z2[100],j,t,s1,w1,w2,w3,z5;
		char bn[100],sn[100],sb[100];
		//double j,p,q;

		z1 = 0;
		t = 10; //
		s1=0;
		j=0;
		w1 = 0;
		w2 = 0;
		w3 = 1;
		for(z=1;z<argc;z++){
			strcpy(sn,argv[z]);

			//printf("%s",s);
			if(((sn[0]=='-')&&(strcmp(sn,"-l")))&&((sn[0]=='-')&&(strcmp(sn,"-c")))&&((sn[0]=='-')&&(strcmp(sn,"-w")))&&((sn[0]=='-')&&(strcmp(sn,"--scaled")))){//
				printf("Invalid option [%s]\n",argv[z]);
				printf("usage: freq [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n");
				return 0;
				}

			if((sn[0]!='-')&&(isalpha(sn[0]))){
				//printf("%c",s[1]);
				z1 = z1+1;
				z2[j]=z;
				j=j+1;
				}else if((sn[0]=='-')&&(sn[1]=='l')){

					if(argc<(z+2)){
						printf("Not enough options for [-l]\n");
						printf("usage: freq [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n");
						return 0;
						}
					//
					strcpy(sb,argv[z+1]);

						z5=0;
						t2 = 0;
						while(sb[z5]!='\0'){
						t2 = isalpha(sb[z5]);
						if(t2!=0){
							printf("Invalid option for [-l]\n");
							printf("usage: freq [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n");
							return 0;
							}
							z5++;
						}

					//printf("%d\n",t2);
					t = atoi(argv[z+1]);


					if((t<0)){
							//printf("%d\n",t); //
							printf("Invalid option for [-l]\n");
							printf("usage: freq [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n");
							return 0;
							}else if(t==0){
								return 0;
							}


			}else if(strcmp(sn,"--scaled")==0){

				s1 = 2;

			}
		}



		fout = fopen("test2.txt","w");

		for(z=0;z<z1;z++){

		fin = fopen(argv[z2[z]],"r");
		 if (fin == NULL)
       {
         printf("Cannot open one or more given files\n");

         return 0;
       }
		while(fscanf(fin,"%s",bn)!=EOF){
			fprintf(fout,"%s ",bn);

			}



			fprintf(fout,"%s","\n");
		}


		fclose(fout);


		txt = fopen("test2.txt","r");


//



		for(z=0;z<argc;z++){
			if(strcmp(argv[z],"-w")==0){
				w1 = 1;
				//w2 = 0;
				w3 = 0;
				}else if(strcmp(argv[z],"-c")==0){
					w2 = 1;
					//w1 = 0;
					w3 = 0;
					}
					if(w1*w2){
						printf("[-c] and [-w] cannot use together\n");
						printf("usage: freq [-l length] [-w | -c] [--scaled] filename1 filename2 ..\n");
						return 0;
						}
					}

			if(w1 || w3){


		NODE * head;
		NODE * current;
		NODE * current2;
		NODE * current3;
		NODE * s1current;
		NODE * s2current;
		NODE * head1;
		int c,c1,r,j1,i;
		char a[100],b[100];
		double j,p,q;



		head = NULL;
		head = (NODE *) malloc(sizeof(NODE));

		current = head;
		current->wnext = NULL;
		while(isalnum(b[0]=fgetc(txt))==0){
			}
			b[0] = tolower(b[0]);
		i=0;
		j1=1;
		j = 1;
		c = 1;
		fscanf(txt,"%s",a);
		while(a[i]!='\0'){
				if(isalnum(a[i])){
					a[i]=tolower(a[i]);
					b[j1]=a[i];
					j1=j1+1;
				}
				i = i+1;

				}
				b[j1]='\0';
		strcpy(current->wrd,b);
		current->wrdamt = 1;

		while(fscanf(txt,"%s",a)!=EOF){
			j1 = 0;
			i = 0;
			while(a[i]!='\0'){
				if(isalnum(a[i])){
					a[i]=tolower(a[i]);
					b[j1]=a[i];
					j1=j1+1;
				}
				i = i+1;

				}

			while(j1<1){
				fscanf(txt,"%s",a);
			j1 = 0;
			i = 0;
			while(a[i]!='\0'){
				if(isalnum(a[i])){
					a[i]=tolower(a[i]);
					b[j1]=a[i];
					j1=j1+1;
				}
				i = i+1;

				}
			}
				b[j1]='\0';
				j = j+1;
				//a = b;
		//	printf("%s ",b);

			r = 1;


			current3 = head;

			while(current3!=NULL){

				if(strcmp(current3->wrd,b) == 0){
					current3->wrdamt++;
					r = 0;
					//printf("%d",4);
				}
				 current3 = current3->wnext;

			}

			if(r){

					current2 = (NODE *) malloc(sizeof(NODE));
					current->wnext = current2;
					strcpy(current2->wrd,b);
					current2->wrdamt = 1;
					current2->wnext = NULL;
					current = current2;
					c = c+1;
				}


		}

		if(c<=1){

			current->wnext = NULL;
			current = head;
			while(current!=NULL){
			printf("%s %.2f\n",current->wrd,current->wrdamt);

		current = current->wnext;
		}
			}else {

		current2->wnext = NULL;


	current = head;
		while(current!=NULL){       // (current->cnext != NULL)

			p = current->wrdamt*100/j;
			current->wrdamt = p;
			//current->chrdamt = p;
			//printf("%s %.2f  ",current->wrd,current->wrdamt);
			current = current->wnext;
		}

		current = head;
		q=-1;
		while(current!=NULL){
			if((current->wrdamt) <= q || q == -1){
				q = current->wrdamt;
				s1current = current;

				}
			current = current->wnext;

			}
				current = head;

			while((current->wnext != s1current) && (s1current != head)){
			current = current->wnext;
			}
			if(head == s1current){
				head = head->wnext;
				}else{
			current->wnext = s1current->wnext;
				}
				s1current->wnext = NULL;


			//s3current = head;
			for(c1=1;c1<c;c1++){
			current = head;
			q = -1;
			while(current!=NULL){
				if((current->wrdamt) <= q || q == -1){
				q = current->wrdamt;
				s2current = current;

				}
			current = current->wnext;
				//printf("coming\n");
				}

				current = head;

			while((current->wnext != s2current) && (s2current != head)){
			current = current->wnext;
			}
			if(head == s2current){
				head = head->wnext;
				}else{
			current->wnext = s2current->wnext;
				}
				//printf("coming\n");
			s2current->wnext = s1current;
			s1current = s2current;
			//s3current = s3current->cnext;
		}

				//c1=c1+1;
			//}
			head1 = s2current;

			if(c<t){

				t = c;

				}
			//s3current->cnext = NULL;

			b3 = 0;
		current = head1;
			for(z=0;z<t;z++){
				b2 = strlen(current->wrd);
				if(b3<=b2){
				b3 = b2;
				}

				//current = current->wnext;
			//printf("%s %.2f\n",current->wrd,current->wrdamt);

		current = current->wnext;
	}
}

	//  graph

	current = head1;


	//printf("\033[80A");


	// printf("\033[2J");
	printf("\n");

	//
	for(ag=1;ag<((t*4)+1);ag++){

		if((ag%4)==2){
	printf(" %s",current->wrd);


	cg = strlen(current->wrd);
	printf("\033[%dC",(b3+1-cg));

	}else{
	printf("\033[%dC",b3+2);
	}


	printf("\u2502");
	if(ag%4){

		if(s1 == 2){
			dg = (current->wrdamt)*(71-b3)/(head1->wrdamt)-1;

    }else{
		dg = ((current->wrdamt)*(71-b3)/(100))-1;
		}
	for(bg=0;bg<dg;bg++){
	printf("\u2591");
	}
	}else{
		current = current->wnext;
		}
	if((ag%4)==2){
		printf("%.2f",current->wrdamt);
		putchar('%');

		}


	printf("\n");

}
	printf("\033[%dC",b3+2);
	printf("\u2514");
	for(ag=0;ag<(77-b3);ag++){
		printf("\u2500");
	}
	printf("\n");

	return 0;



	}else if(w2){


		node * current;
		node * current2;
		node * head;
		node * current3;
		node * s1current;
		node * s2current;
		//node * s3current;
		node * head1;
		int r,c,c1;
		double q,j,p;
		char a,b;

		head = NULL;
		head = (node *) malloc(sizeof(node));

		current = head;
		current->cnext = NULL;
		while(isalnum(b=fgetc(txt))==0){

		}
		b = tolower(b);
		current->chr = b;
		current->chramt = 1;
		j=1;
		c=1;

		while((a = fgetc(txt))!=EOF){
			r = 1;
			if(isalnum(a)){

				a = tolower(a);

			current3 = head;

			while(current3!=NULL){


				if(current3->chr == a){
					current3->chramt++;
					r = 0;
					//printf("%d",4);
				}
				 current3 = current3->cnext;

			}

			if(r){

					current2 = (node *) malloc(sizeof(node));
					c = c+1;
					current->cnext = current2;
					current2->chr = a;
					current2->chramt = 1;
					current2->cnext = NULL;
					current = current2;
					//printf("%c",current->chr);
				}

			j = j+1;
		}
	}

	if(c<=1){

			current->cnext = NULL;
			current = head;
			while(current!=NULL){
			//printf("%c %.2f\n",current->chr,current->chramt);

		current = current->cnext;
		}
			}else {

		current2->cnext = NULL;


		current = head;
		while(current!=NULL){       // (current->cnext != NULL)

			p = current->chramt*100/j;
			current->chramt = p;
			//current->chrdamt = p;
			//printf("%c %.2f  ",current->chr,current->chramt);
			current = current->cnext;
		}

		current = head;
		q=-1;
		while(current!=NULL){
			if((current->chramt) <= q || q == -1){
				q = current->chramt;
				s1current = current;

				}
			current = current->cnext;

			}
				current = head;

			while((current->cnext != s1current) && (s1current != head)){
			current = current->cnext;
			}
			if(head == s1current){
				head = head->cnext;
				}else{
			current->cnext = s1current->cnext;
				}
				s1current->cnext = NULL;


			//s3current = head;
			for(c1=1;c1<c;c1++){
			current = head;
			q = -1;
			while(current!=NULL){
				if((current->chramt) <= q || q == -1){
				q = current->chramt;
				s2current = current;

				}
			current = current->cnext;
				//printf("coming\n");
				}

				current = head;

			while((current->cnext != s2current) && (s2current != head)){
			current = current->cnext;
			}
			if(head == s2current){
				head = head->cnext;
				}else{
			current->cnext = s2current->cnext;
				}
				//printf("coming\n");
			s2current->cnext = s1current;
			s1current = s2current;
			//s3current = s3current->cnext;
		}

				//c1=c1+1;
			//}
			head1 = s2current;
			//s3current->cnext = NULL;

			if(c<t){

				t = c;

				}

		current = head1;
			while(current!=NULL){
		//	printf("%c %.2f\n",current->chr,current->chramt);

		current = current->cnext;
		}
		//printf("\n");
		//printf("%f\n",j);

		}

// graph
		b3 = 1;
		current = head1;

	//printf("\033[80A");


	// printf("\033[2J");
	printf("\n");    //

	//
	for(ag=1;ag<((t*4)+1);ag++){

		if((ag%4)==2){
	printf(" %c",current->chr);


	cg = 1;//strlen(current->wrd);
	printf("\033[%dC",(b3+1-cg));

	}else{
	printf("\033[%dC",b3+2);
	}


	printf("\u2502");
	if(ag%4){
		if(s1==2){
		dg = (current->chramt)*70/(head1->chramt)-1;
	}else{
		dg = ((current->chramt)*70/(100))-1;
		}
	for(bg=0;bg<dg;bg++){
	printf("\u2591");
	}
	}else{
		current = current->cnext;
		}
	if((ag%4)==2){
		printf("%.2f",current->chramt);
		putchar('%');

		}


	printf("\n");

}
	printf("\033[%dC",b3+2);
	printf("\u2514");
	for(ag=0;ag<(77-b3);ag++){
		printf("\u2500");
	}
	printf("\n");

		return 0;





		}



	return 0;
}

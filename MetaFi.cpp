#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define MAGENTA "\x1b[35m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))


char passs[100];
char email[100];
char username[100];
int z=0;
int counter=0;
int pos, val, tot, sto;
int flag=0;
int wait=0;
int jnt=0;

char dat[1000][1000];

void map(int p, char u[], int start);
void tes(int p, char u[]);
void his(int V, int P, int T, int S, int R, char u[], int p);

void fullscreen() {
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
	Sleep(100);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

struct candle{
	int openPrice;
	int closedPrice;
	int highestPrice;
	int lowestPrice;
	struct candle *next;
	struct candle *prev;
}*head=NULL, *tail=NULL;

struct dataUser {
    int Value;
    int Position;
    int TakeProfit;
    int StopLoss;
    int Reward;
    struct dataUser *next;
    struct dataUser *prev;
    struct candle *stick;
};

struct node {
    char namaAkun[100];
    char emailAkun[100];
    char passAkun[100];
    int uangAkun;
    struct dataUser *userData;
    struct node* next;
}*newNode[100];

void oo(){
	FILE *ptt;
	ptt=fopen("user.txt", "w");
	fprintf(ptt, " ");
	fclose(ptt);
	FILE *ptr;
	ptr=fopen("user.txt", "a");
	int bn=0;
	int ff=0;
	while(bn<=100){
		if(newNode[bn]!=NULL){
		struct node *temp = newNode[bn];
			while(temp!=NULL){
				fprintf(ptr, "%s#%s#%s#%d\n", temp->namaAkun, temp->emailAkun, temp->passAkun, temp->uangAkun);
				ff++;
				temp=temp->next;
			}
		}
		bn++;
	}	
				fclose(ptr);
}

void prin(int p, char u[]){
	int open, close, highCandle, lowCandle;
	struct node *temp = newNode[p];
    while (strcmp(temp->namaAkun, u) != 0) {
    	temp=temp->next;
    }
    
	int number=330;
	for(int a=0; a<=34; a++){
		struct candle *curr=head;
			for(int d=0; d<counter; d++){
			curr=curr->next;
			}
		for(int b=0; b<=130; b++){
			if(curr){
				close=curr->closedPrice;
				open=curr->openPrice;
				highCandle=curr->highestPrice;
				lowCandle=curr->lowestPrice;
			}
			else{
				close = open = -1;
			}
			if(a==0 && b==0){
				printf("%c", 201);
			}
			else if(b==124 && a==0){
				printf("%c", 203);
			}
			else if(b==124 && a==34){
				printf("%c", 202);
			}
			else if(b==0 && a==34){
				printf("%c", 204);
			}
			else if(b==130 && a==34){
				printf("%c", 185);
			}
			else if(b==107 && a==34){
				printf("%c", 203);
			}
			else if(b==39 && a==34){
				printf("%c", 203);
			}
			else if(a==34 && b==0){
				printf("%c", 200);
			}
			else if(a==34 && b==130){
				printf("%c", 188);
			}
			else if(a==0 && b==130){
				printf("%c", 187);
			}
			else if(a==0||a==34){
				printf("%c", 205);
			}
			else if (b==0||b==130){
				printf("%c", 186);
			}
			else if(b==124){
				printf("%c", 186);
			}
			else if(b==126){
				printf(" %-4d", number);
				number-=10; 
			}
			else if(b<124){
				if(number<=highCandle && number>=lowCandle && b>0 && curr!=NULL){
					if(number<=open && number>=close){
					printf(RED "%c" RESET, 219);
					}
					else if(number>=open && number <=close){
					printf(GREEN "%c" RESET, 219);	
					}
					else if (number<=highCandle && number>=lowCandle && open>=close){
					printf(RED "%c" RESET, 179);
					}
					else if (number<=highCandle && number>=lowCandle && close>=open){
					printf(GREEN "%c" RESET, 179);
				}
				}
				else{
				if(flag==1){
				if(number==pos){
					printf(MAGENTA "-" RESET);
				}
				else if(number==sto){
					printf(RED "-" RESET);
				}
				else if(number==tot){
					printf(GREEN "-" RESET);
				}
				else printf("-");
				}
				else{
				printf("-");	
				}
				}
			}
			
			if(curr!=NULL && b>0)
			{
			curr=curr->next;
			}
		}
		printf("\n");
	}
	printf("%c Welcome To METAFI, %-18s%c    Value       :            TP :                                  %c                      %c\n%c 1. New Day   3. Next  5. Short       %c    Position    :            SL :                                  %c $%-20d%c\n%c 2. Previous  4. Long  6. Logout >>   %c                                                                   %c                      %c\n", 186, temp->namaAkun,186,186,186,186, 186,186, temp->uangAkun, 186,186, 186, 186, 186);
	printf("%c", 200);
	for(int k=0; k<129; k++){
		if(k==38 || k==106){
			printf("%c", 202);
		}
		else printf("%c", 205);
	}
	printf("%c\n", 188);
			if(flag==1){
				if(((lowCandle <= sto && close>= sto)|| (lowCandle <= tot && close>= tot)|| (highCandle >= sto && open <= sto)|| (highCandle >= tot && open <= tot)) && wait==1){	
					gotoxy(0, 40);
					jnt=val;
					int k=pos;
					int l=close;
					
					int m=l-k;
					if(m<0){
						m*=-1;
					}
					jnt*=m;
					jnt/=100;
					if(tot>sto){
						jnt*=-1;	
					}
					else if(sto>tot){
						jnt*=-1;
					}
					int rr=temp->uangAkun;
					rr+=jnt;
					temp->uangAkun=rr;
					his(val, pos, tot, sto, jnt, u, p);
					gotoxy(0, 40);
					system("pause");
					flag=0;
					map(p, u, 0);			
				}	
				
	wait=1;
}
}

void his(int V, int P, int T, int S, int R, char u[], int p) {
	struct node *temp = newNode[p];
    while (strcmp(temp->namaAkun, u) != 0) {
    	temp=temp->next;
    } 
    struct dataUser *newOrHead = (struct dataUser*) malloc(sizeof(struct dataUser));
    newOrHead->Position = P;
    newOrHead->TakeProfit = T;
    newOrHead->StopLoss = S;
    newOrHead->Reward = R;
    newOrHead->Value = V;
    newOrHead->next = NULL;
    newOrHead->prev = NULL;
    if (temp->userData == NULL) {
        temp->userData=newOrHead;
    } else {
        struct dataUser *ptr = temp->userData;
        struct dataUser *prev = NULL;
        while (ptr != NULL && newOrHead->Reward <= ptr->Reward) {
            prev = ptr;
            ptr = ptr->next;
        }
        if (prev == NULL) {
            newOrHead->next = temp->userData;
            if (temp->userData != NULL) temp->userData->prev = newOrHead;
            temp->userData = newOrHead;
        } else {
            newOrHead->next = prev->next;
            newOrHead->prev = prev;
            if (prev->next != NULL) prev->next->prev = newOrHead;
            prev->next = newOrHead;
        }
    }
    oo();
}

void tes(int p, char u[], int pew, int op){
	struct node *temp = newNode[p];
    while (strcmp(temp->namaAkun, u) != 0) {
    	temp=temp->next;
    }
    if(pew==0){
	gotoxy(58, 36);
		scanf("%d", &val);
		if(val>temp->uangAkun){
			gotoxy(45, 38);
			printf(RED "Your balance is not enough!" RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
			if(op==4){
			tes(p, u, 0, 4);
			}
			else if(op==5){
				tes(p, u, 0, 5);
			}
		}
		else if (val<10){
			gotoxy(45, 38);
			printf(RED "Value must be between 10 and the currency" RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
			if(op==4){
			tes(p, u, 0, 4);
			}
			else if(op==5){
				tes(p, u, 0, 5);
			}
		}
		pew++;
	}
	
	if(pew==1){
		gotoxy(58, 36);
		printf("%d", val);
		gotoxy(58, 37);
		scanf("%d", &pos);
		if(pos>320 || pos<20){
			gotoxy(45, 38);
			printf(RED "Position should be between 20 and 320." RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
			if(op==4){
			tes(p, u, 1, 4);
			}
			else if(op==5){
				tes(p, u, 1, 5);
			}
		}
		else if(pos%10!=0){
			gotoxy(45, 38);
			printf(RED "Position should be in multiple of ten." RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
			if(op==4){
			tes(p, u, 1, 4);
			}
			else if(op==5){
				tes(p, u, 1, 5);
			}
		}
		pew++;
	}
	if(pew==2){
		gotoxy(58, 36);
		printf("%d", val);
		gotoxy(58, 37);
		printf("%d", pos);
		gotoxy(74, 36);
		scanf("%d", &tot);
		if(op==4){
		if(tot<pos){
			gotoxy(45, 38);
			printf(RED "Take profit must be higher than the position" RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
			tes(p, u, 2, 4);
			}
		}
	else if(op==5){
		if(tot>pos){
			gotoxy(45, 38);
			printf(RED "Take profit must be lower than the position" RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
		
				tes(p, u, 2, 5);
			
		}	
	}
		if(tot%10!=0){
			gotoxy(45, 38);
			printf(RED "Take profit should be in multiple of ten." RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
			if(op==4){
			tes(p, u, 2, 4);
			}
			else if(op==5){
				tes(p, u, 2, 5);
			}
		}
		else if(tot>330 || tot<10){
			gotoxy(45, 38);
			printf(RED "Take profit should be between 10 and 330." RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
			if(op==4){
			tes(p, u, 2, 4);
			}
			else if(op==5){
				tes(p, u, 2, 5);
			}
		}
		pew++;
	}
	
	if(pew==3){
	gotoxy(58, 36);
	printf("%d", val);
	gotoxy(58, 37);
	printf("%d", pos);
	gotoxy(74, 36);
	printf("%d", tot);
	gotoxy(74, 37);
		scanf("%d", &sto);
		if(op==4){
		if(sto>pos){
			gotoxy(45, 38);
			printf(RED "Stop loss must be lower than the position" RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
			tes(p, u, 3, 4);
		}
	}
	else if (op==5){
	if(sto<pos){
			gotoxy(45, 38);
			printf(RED "Stop loss must be higher than the position" RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
				tes(p, u, 3, 5);
		}	
	}
		else if(sto%10!=0){
			gotoxy(45, 38);
			printf(RED "Stop loss should be in multiple of ten." RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
			if(op==4){
			tes(p, u, 3, 4);
			}
			else if(op==5){
				tes(p, u, 3, 5);
			}
		}
		else if(sto>330 || sto<10){
			gotoxy(45, 38);
			printf(RED "Stop loss should be between 10 and 330." RESET);
			gotoxy(0, 40);
			system("pause");
			system("cls");
			prin(p, u);
			if(op==4){
			tes(p, u, 3, 4);
			}
			else if(op==5){
				tes(p, u, 3, 5);
			}
		}
		pew++;
	}
	flag=1;
	system("cls");
	map(p, u, 0);
}

void map(int p, char u[], int start){
	printf("\033[H");
	srand(time(NULL));
	struct node *temp = newNode[p];
    while (strcmp(temp->namaAkun, u) != 0) {
    	temp=temp->next;
    }
if(start==1){
    struct candle *newCandle = (struct candle*) malloc (sizeof(struct candle));
    newCandle->next=NULL;
    newCandle->prev=NULL;
    if(head==NULL){
    	int k=rand()%33*10+10;
    	newCandle->openPrice=k;
	}
	else{
		newCandle->openPrice=tail->closedPrice;
	}
    	int w=rand()%10+1;
    	int v=rand()%10+1;
    	if(w==1){
    		newCandle->closedPrice=newCandle->openPrice;
		}
		else{
			int j=rand()%6*10+10;
			int l=rand()%2+1;
			int cp=newCandle->openPrice;
			if(l==1){
				int z=cp-j;
				newCandle->closedPrice=z;
			}
			else if(l==2){
				int z=cp+j;
				newCandle->closedPrice=z;
			}
			if(newCandle->closedPrice>330){
				newCandle->closedPrice=330;
			}
			else if(newCandle->closedPrice<10){
				newCandle->closedPrice=10;
			}
		}
		if((newCandle->closedPrice >= newCandle->openPrice) && w<=3){
			newCandle->highestPrice=newCandle->closedPrice;
		}
		else if ((newCandle->closedPrice >= newCandle->openPrice) && w>3){
			int d=rand()%5*10;
			int e=newCandle->closedPrice;
			d+=e;
			newCandle->highestPrice=d;
		}
		else if(newCandle->closedPrice <= newCandle->openPrice && w<=3){
			newCandle->highestPrice=newCandle->openPrice;
		}
		else if (newCandle->closedPrice <= newCandle->openPrice && w>3){
			int d=rand()%5*10;
			int e=newCandle->openPrice;
			d+=e;
			newCandle->highestPrice=d;
		}
		
		if(newCandle->closedPrice >= newCandle->openPrice && v<=3){
			newCandle->lowestPrice=newCandle->openPrice;
		}
		else if (newCandle->closedPrice >= newCandle->openPrice && v>3){
			int d=rand()%5*10;
			int e=newCandle->openPrice;
			e-=d;
			newCandle->lowestPrice=e;
		}
		else if(newCandle->closedPrice <= newCandle->openPrice && v<=3){
			newCandle->lowestPrice=newCandle->closedPrice;
		}
		else if (newCandle->closedPrice <= newCandle->openPrice && v>3){
			int d=rand()%5*10;
			int e=newCandle->closedPrice;
			e-=d;
			newCandle->lowestPrice=e;
		}
		if(newCandle->highestPrice>330){
			newCandle->highestPrice=330;
		}
		if(newCandle->lowestPrice<10){
			newCandle->lowestPrice=10;
		}
		if(head==NULL){
    	head=tail=newCandle;
		}
    	else{
    		tail->next=newCandle;
    		newCandle->prev=tail;
    		tail=newCandle;
		}
}
	prin(p, u);
	gotoxy(38, 38);
	scanf("%d", &z);
	if(z==1){
	map(p, u, 1);
	}
	else if(z==2){
		counter++;
		map(p, u, 0);
	}
	else if(z==3){
		if(counter>0) counter--;
		map(p, u, 0);
	}
	else if(z==4){
		if(flag==1){
			map(p, u, 0);
		}
		tes(p, u, 0, 4);
	}
	else if(z==5){
		if(flag==1){
			map(p, u, 0);
		}
		tes(p, u, 0, 5);
	}
	else if(z==6){
		return;
	}
}

void start(char u[], int p) {
	int no=0;
	struct node *temp = newNode[p];
    while (strcmp(temp->namaAkun, u) != 0) {
    	temp=temp->next;
    }
    struct dataUser *ptr = temp->userData;
    if(ptr==NULL){
    	system("cls");
    	printf("No trade history\n");
    	system("pause");
	}
	else{
		while(ptr!=NULL){
			no++;
			printf("No: %d\n", no);
			printf("Value: %d\n", ptr->Value);
			printf("Position: %d\n", ptr->Position);
			printf("Take Profit: %d\n", ptr->TakeProfit);
			printf("Stop Loss: %d\n", ptr->StopLoss);
			printf("Reward: %d\n\n", ptr->Reward);
			ptr=ptr->next;
		}
		system("pause");
	}
}

void gui(){
	system("cls");
	printf("What Is Forex?\n\"Forex\", short for foreign exchange, is a global decentralized marketplace for trading currencies.\nIn forex trading, participants buy one currency by selling another currency simultaneously, with the aim of profiting from fluctuations in exchange rates.\nIt is one of the largest and most liquid financial markets in the world, operating 24 hours a day, five days a week.\n\nWhat Is Candle Stick?\n\"Canlde Stick\" in charts are a type of financial chart used to represent price movements in trading markets, including forex.\nThey visually display the open, high, low, and close prices for a specific period.\nif the close price is higher than the open price, the candle color will be green\nthen if the close price is less than the open price, the candle color will be red.\nshadow or tick is the highest and the lowest price of a candle.\n\n\nWhat Is Position?\n");
	printf("\"Position\" in forex trading refers to where we want to enter the market at certain price point\n\nWhat Is Long?\n\"Long\" in forex trading refers to a trading position where a trader buys a currency pair\nwith the expectation that its value will increase over time.\n\n\nWhat Is Short?\n\"Short\" in forex trading refers to a trading position where a trader sells a currency pair\nwith the expectation that its value will decrease over time.\n\n\nWhat is Take Profit?\n\"Take Profit\" in forex trading refers to where we will leave the market at the specified price point\nour position will automatically closed after the market price hit our take profit price\n\n\nWhat Is Stop Loss?\n\"Stop Loss\" in forex trading refers to where we will leave the market at the specified price point\nit's used to make sure that we don't loss all of our money and many more\nsame like take profit, our position will automatically closed after the market price hit our take profit price\n\n");
	system("pause");
	return;
}

void domain(char u[], int p){
	int k;
	while(true){
	system("cls");
	puts("Metafi - User\'s Menu");
	puts("---------------------");
	puts("1. Start Trade");
	puts("2. Trade History");
	puts("3. Guide");
	puts("4. Log Out");
	printf(">>");
	scanf("%d", &k);
	if(k==1){
		map(p, u, 1);
	}
	else if(k==2){
		start(u, p);
	}
	else if(k==3){
		gui();
	}
	else if(k==4){
		flag=0;
		wait=0;
		jnt=0;
		return;
	}
}
}

void ch(char u[], int p, char emailCheck[], char passCheck[], int uang) {
    if (newNode[p] == NULL) {
        newNode[p] = (struct node*)malloc(sizeof(struct node));
        strcpy(newNode[p]->namaAkun, u);
        strcpy(newNode[p]->emailAkun, emailCheck);
        strcpy(newNode[p]->passAkun, passCheck);
        newNode[p]->uangAkun=uang;
        newNode[p]->next = NULL;
        newNode[p]->userData = NULL;
         domain(u, p);
        return;
    } 
    
    struct node* temp = newNode[p];
    while (temp != NULL) {
        if (strcmp(temp->namaAkun, u) == 0) {
            if (temp->userData != NULL) {
                printf("Value: %d\n", temp->userData->Value);
                printf("TakeProfit: %d\n", temp->userData->TakeProfit);
                printf("StopLoss: %d\n", temp->userData->StopLoss);
                printf("Reward: %d\n", temp->userData->Reward);
                printf("Position: %d\n", temp->userData->Position);
            }
            domain(u, p);
            return;
        }
        
        if (temp->next == NULL) {
            temp->next = (struct node*)malloc(sizeof(struct node));
            temp = temp->next;
            strcpy(temp->namaAkun, u);
            strcpy(temp->emailAkun, emailCheck);
            strcpy(temp->passAkun, passCheck);
            temp->uangAkun=uang;
            temp->next = NULL;
            temp->userData = NULL;
             domain(u, p);
            return;
        }
        temp = temp->next;
    }
}

void hash(char username[], char emailCheck[], char passCheck[], int uang){
	int p=0;
	for(int a=0; a<strlen(username); a++){
		p+=username[a];
	}
	p%=26;
	ch(username, p, emailCheck, passCheck, uang);
}

void login(){
	char email2[1000];
	char emailCheck[1000];
	char pass[1000];
	char passCheck[1000];
	char userCheck[1000];
	int uang;
	system("cls");
	printf("Email (0 To Exit) : ");
	scanf("%s", email2);
	if(strcmp(email2, "0")==0) return;
	system("cls");
	printf("Password (0 To Exit) : ");
	scanf("%s", pass);
	if(strcmp(pass, "0")==0) return;
	FILE *ptr;
	ptr=fopen("user.txt", "r");
	while(!feof(ptr)){
		fscanf(ptr, "%[^#]#%[^#]#%[^#]#%d\n", userCheck, emailCheck, passCheck, &uang);
		if(strcmp(email2,emailCheck)==0 && strcmp(pass, passCheck)==0){
			hash(userCheck, emailCheck, passCheck, uang);
			fclose(ptr);
			return;
		}
	}
	fclose(ptr);
		printf("Email or Password Is Invalid!\n");
		system("pause");
		login();
	}

void pass(){
	system("cls");
	int countAt=0;
	int countAt2=0;
	char emailCheck[1000];
	printf("Password (0 To Exit) : ");
	scanf("%[^\n]", passs);
	getchar();
	if(strcmp(passs, "0")==0) return;
	if(strlen(passs)<8 || strlen(passs)>36){
		printf("password must be between 8 and 36 characters!\n");
		system("pause");
		system("cls");
		pass();
	}
	
	for(int a=0; a<strlen(passs); a++){
		if(!((passs[a]<='z' && passs[a]>='a') || (passs[a]<='Z' && passs[a]>='A') || (passs[a]<='9' && passs[a]>='1'))){
		printf("password does not contain a symbol\n");
		system("pause");
		system("cls");
		pass();
		}
		else if(((passs[a]<='z' && passs[a]>='a') || (passs[a]<='Z' && passs[a]>='A'))){
			countAt++;
		}
		else if((passs[a]<='9' && passs[a]>='1')){
			countAt2++;
		}
	}
	if(countAt==0 || countAt2==0){
		printf("password contains at least one alphabet and one number\n");
		system("pause");
		system("cls");
		pass();
	}
	FILE *ptr;
	ptr=fopen("user.txt", "a");
	fprintf(ptr, "%s#%s#%s#%d\n", username, email, passs, 10000);
	fclose(ptr);
	return;
}	

void emaiil(){
	FILE *ptr;
	ptr=fopen("user.txt", "r");
	system("cls");
	int countAt=0;
	char emailCheck[1000];
	char userCheck[1000];
	char passCheck[1000];
	int check;
	printf("Email (0 To Exit) : ");
	scanf("%[^\n]", email);
	getchar();
	if(strcmp(email, "0")==0) return;
	if(strlen(email)<6 || strlen(email)>36){
		printf("email must be between 6 and 36 characters!\n");
		system("pause");
		system("cls");
		emaiil();
	}
	if(ptr!=NULL){
	while(!feof(ptr)){
		fscanf(ptr, "%[^#]#%[^#]#%[^#]#%d\n", userCheck, emailCheck, passCheck, &check);
		if(strcmp(emailCheck, email)==0){
			printf("email must be unique\n");
			system("pause");
			system("cls");
			emaiil();
		}
	}
	}
	fclose(ptr);
	
	for(int a=0; a<strlen(email); a++){
		if(!(email[strlen(email)-1]=='m' && email[strlen(email)-2]=='o' && email[strlen(email)-3]=='c' && email[strlen(email)-4]=='.' )){
		printf("email must be ended with \'.com\'\n");
		system("pause");
		system("cls");
		emaiil();
	}
		else if(email[a]==' '){
		printf("email can’t have white space \' \'\n");
		system("pause");
		system("cls");
		emaiil();
		}
		else if(email[a]=='#'){
			printf("email does not contain the tag \'#\'\n");
			system("pause");
		system("cls");
		emaiil();}
		else if(email[a]=='@'){
			countAt++;
			if(countAt>1){
				printf("email only contains one \'@\'\n");
				system("pause");
				countAt--;
		system("cls");
		emaiil();
			}
			else if(!((email[a+1]<='z' && email[a+1]>='a') || (email[a+1]<='Z' && email[a+1]>='A'))){
				printf("email must have a domain\n");
				system("pause");
		system("cls");
		emaiil();
			}
		}
		else if(!((email[a]<='z' && email[a]>='a') || (email[a]<='Z' && email[a]>='A') || (email[a]<='9' && email[a]>='1') || (email[a]=='.'))){
			printf("email only contain alphabet and number\n");
			system("pause");
		system("cls");
		emaiil();
		}
		else if(!((email[0]<='z' && email[0]>='a') || (email[0]<='Z' && email[0]>='A'))){
			printf("email must be started with a character\n");
			system("pause");
		system("cls");
		emaiil();
		}
	}
	pass();
	return;
}

void regis(){
	char emailCheck[1000];
	char userCheck[1000];
	char passCheck[1000];
	int check;
	FILE *ptr;
	ptr=fopen("user.txt", "r");
	int countAt=0;
	int flag=0;
	char usernameCheck[1000];
	system("cls");
	printf("Username (0 To Exit) : ");
	scanf("%s", username);
	getchar();
	if(strcmp(username, "0")==0) return;
	if(ptr!=NULL){
		
	while(!feof(ptr)){
		fscanf(ptr, "%[^#]#%[^#]#%[^#]#%d\n", userCheck, emailCheck, passCheck, &check);
		if(strcmp(userCheck, username)==0){
			printf("username must be unique\n");
			system("pause");
			system("cls");
			regis();
		}
	}
	fclose(ptr);
	
	if(strlen(username)<1 || strlen(username)>20){
		printf("username must be between 1 and 20 characters!\n");
		system("pause");
		system("cls");
		regis();
	}
	for(int a=0; a<strlen(username); a++){
		if(!((username[a]<='z' && username[a]>='a') || (username[a]<='Z' && username[a]>='A') || (username[a]<='9' && username[a]>='1'))){
			printf("usernames only contain alphabet and number\n");
			break;
	}
	emaiil();
	return;
}
}
}

int main(){
	fullscreen();
	while(true){
	system("cls");
	int k;
	printf("Metafi\n");
	puts("1. Log In To Trade");
	puts("2. Register Account");
	puts("3. Exit Application");
	printf(">> ");
	scanf("%d", &k);
	
	if(k==1){
		login();
	}
	else if(k==2){
		regis();
	}
	else if (k==3){
	system("cls");
	printf(MAGENTA "Meta Fi\n\n" RESET);
	printf(GREEN "Created by Winsen Olando\n\n" RESET);
	printf(RESET "Thank you!\n\n");
	return 0;
	}
}
}

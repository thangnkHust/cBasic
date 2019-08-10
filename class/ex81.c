// ===MENU===
// 1.import from file student.txt(!name viet lien)
// 2.insert new student(check xem id co trung khong?)
// 3.search by ID(check xem co ket qua tra ve khong?)
// 4.delete by ID(Check xem run case3? not find thi tra ve khong tim thay ket qua?)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define id_length 10
#define name_length 50
#define max 100

typedef struct student{		//dinh nghia single linked list
	char id[id_length];
	char name[name_length];
	int grade;
	struct student *next;
}student;

typedef struct hocSinh{		//support read file nhung co the khong dung
	char id[id_length];
	char name[name_length];
	int grade;
}hocSinh;

int menu(){
	puts("=============MENU==============");
	puts("1.Import from file text");
	puts("2.Insert new student");
	puts("3.Search a student by ID");
	puts("4.Delete a student by ID");
	puts("5.Exit!!!");
	printf("Enter selection: ");
	int n;
	scanf("%d", &n);
	puts("============================");
	return n;
}

int checkID(char *id, student *root){		//check id cua new student co trung lap voi cac student khac khong?
	student *cur = root;
	while(cur != NULL){
		if(strcmp(cur->id, id) == 0) return 1;
		cur = cur->next;
	}
	return 0;
}

student *makeNewStudent(student *root){		//creat new student
	student *new = (student*)malloc(sizeof(student));
	printf("\tNhap id: ");
	scanf("%s", new->id);
	while(checkID(new->id, root)){
		printf("***Nhap id bi trung\n\tnhap lai: ");
		scanf("%s", new->id);
	}
	printf("\tNhap name: ");
	scanf("%s",new->name);
	printf("\tNhap grade: ");
	scanf("%d", &new->grade);
	new->next = NULL;
	return new;
}

student *addStudent(student *root, student *to_add)		//add theo thu tu diem
{
    student *cur = NULL, *prev = NULL;

    if (root == NULL) 
        return to_add;

    if (to_add->grade > root->grade)
    {
        to_add->next = root;
        // root = to_add;
        return to_add;
    }

    cur = root; 
    while (cur != NULL  &&  to_add->grade < cur->grade)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = to_add;
    to_add->next = cur;

    return root;
}

student *findByID(student *root, char *id){		//find by ID
	student *cur = root;
	while(cur != NULL){
		if(strcmp(cur->id, id) == 0){
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

student *deleteElement(student *root, student *cur){		//delete by ID
	student *prev = root;
	if(cur == NULL){
		printf("Khong co ket qua trong list!\n");
		return root;
	}
	if(cur == root){
		root = root->next;
		free(cur);
	}else{
		while(prev->next != cur) prev = prev->next;
		prev->next = cur->next;
		free(cur);
	}
	return root;
}

// student *makeNode(hocSinh e){		//function khong duoc su dung dung de nhap node
// 	student *new = (student*)malloc(sizeof(student));
// 	strcpy(new->id, e.id);
// 	strcpy(new->name, e.name);
// 	new->grade = e.grade;
// 	new->next = NULL;
// 	return new;
// }

student *importFile(FILE *fin, student *root){		//Lay du lieu tu file ghi vao list
	hocSinh temp[max];
	// student *to_add;
	char str[max];
	int count = 0;
	while(fgets(str, max, fin) != NULL){
		// printf("%s", str);
		count++;
	}
	printf("So luong: %d\n", count);
	rewind(fin);
	int i = 0;
	while(i < count){
		fscanf(fin, "%s%s%d", temp[i].id, temp[i].name, &temp[i].grade);
		student *to_add = (student*)malloc(sizeof(student));
		strcpy(to_add->id, temp[i].id);
		strcpy(to_add->name, temp[i].name);
		to_add->grade = temp[i].grade;
		to_add->next = NULL;
		// to_add = makeNode(temp[i]);
		root = addStudent(root, to_add);
		// printf("%-10s%-20s%-5d%p\n", to_add->id, to_add->name, to_add->grade, to_add->next);
		i++;
	}
	return root;
}

void printList(student *root){
	student *cur = root;
	while(cur != NULL){
		printf("%-10s%-20s%-5d%p\n", cur->id, cur->name, cur->grade, cur->next);
		cur = cur->next;
	}
	// return root;
}

student *freeList(student *root){		//free list, can return root de truyen gia tri ra khoi function
	student *to_free;
	to_free = root;
	while(to_free != NULL){
		root = root->next;
		free(to_free);
		to_free = root;
	}
	return root;
}


int main(int argc, char *argv[]){

	if(argc != 2){
		printf("Error argument\nSyntax correct: %s <file source>\n", argv[0]);
		return 0;
	}
	int selec;
	student *root = NULL;
	student *to_add, *to_search;
	int case1 = 0, case3 = 0;
	char id[id_length];
	FILE *fin;

	if((fin = fopen(argv[1], "r")) == NULL){
		printf("Can not open file %s\n", argv[1]);
		return 0;
	}

	do{
		selec = menu();
		switch(selec){
			case 1:
				if(case1 == 0){
					root = importFile(fin, root);
					printList(root);
					case1 = 1;
				}else{
					printf("*Case 1 chi chay 1 lan\n");
					break;
				}
				break;
			case 2:
				if(case1 == 0){
					printf("Don't run case 1, run again!\n");
					break;
				}
				to_add = makeNewStudent(root);
				root = addStudent(root, to_add);
				printList(root);
				break;
			case 3:
				if(case1 == 0){
					printf("Don't run case 1, run again!\n");
					break;
				}
				printf("Nhap id search: ");
				getchar();
				gets(id);
				to_search = findByID(root, id);
				case3 = 1;
				if(to_search == NULL){
					printf("Khong co id phu hop!\n");
				}else{
					printf("%-10s%-30s%-5d\n", to_search->id, to_search->name, to_search->grade);
				}
				break;
			case 4:
				if(case1 == 0){
					printf("Don't run case 1, run again!\n");
					break;
				}
				if(case3 == 0){
					printf("Don't run case 3!\n");
					break;
				}
				root = deleteElement(root, to_search);
				printList(root);
				case3 = 0;
				break;
			case 5:
				puts("Exit!!!");
				break;
		}
	}while(selec != 5);

}
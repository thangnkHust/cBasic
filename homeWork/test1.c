// tower of ha noi dung stack
typedef struct{

int N;

int A, B, C;

} ElementType;

// Chương trình con MOVE không đệ qui

void Move(ElementType X){

ElementType Temp, Temp1;

Stack S;

MakeNull_Stack(&S);

Push(X,&S);

do

{

Temp=Top(S); //Lay phan tu dau

Pop(&S); //Xoa phan tu dau

if (Temp.N==1)

printf("Chuyen 1 dia tu %c

sang %c\n",Temp.A,Temp.B);

else

{

// Luu cho loi goi Move(n-1,C,B,A)

Temp1.N=Temp.N-1;

Temp1.A=Temp.C;

Temp1.B=Temp.B;

Temp1.C=Temp.A;

Push(Temp1,&S);

// Luu cho loi goi Move(1,A,B,C)

Temp1.N=1;

Temp1.A=Temp.A;

Temp1.B=Temp.B;

Temp1.C=Temp.C;

Push(Temp1,&S);

//Luu cho loi goi Move(n-1,A,C,B)

Temp1.N=Temp.N-1;

Temp1.A=Temp.A;

Temp1.B=Temp.C;

Temp1.C=Temp.B;

Push(Temp1,&S);

}

} while (!Empty_Stack(S));

}
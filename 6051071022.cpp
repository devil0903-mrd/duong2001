#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>


struct book_st;
void hienThiDSTV(struct book_st*, int);
void hienthibang();

struct book_st{
	char ten [30], theloai[30];
	int  giatien;
}bs;

void nhapN(book_st ds[], int n){
	for(int i=0; i<n; i++){
	    printf("	Nhap thong tin sach thu %d:", i+1);
	    printf("\n	Nhap ten sach: "); 
		fflush(stdin); 
		gets(ds[i].ten);
        printf("	Nhap the loai sach: "); 
		fflush(stdin); 
		gets(ds[i].theloai);
        printf("	Nhap gia tien cua sach : "); 
		scanf("%d", &ds[i].giatien);

    }
}// nhap thong tin sach
void xuatN(book_st ds[], int n){
	for(int i=0; i<n; i++){
		printf("	Thong tin sach thu %d: \n", i+1);
		printf("	Ten sach: %s\n", ds[i].ten);
		printf("	The loai sach : %s\n", ds[i].theloai);
		printf("	Gia cua sach la: %d\n", ds[i].giatien);
	}
}// xuat thong tin sach

void thongtinsach(struct book_st bs){
	printf("	||%-20s ||%-20s ||%-20d \n", bs.ten,bs.theloai,bs.giatien);
}//hien thi thong tin sach

void sapxep(struct book_st *ds, int n) {
	int i, j;
	for(i = 0; i < n - 1; i++) {
		for(j = n - 1; j > i; j --) {
			if(strcmp(ds[j].theloai , ds[j - 1].theloai) > 0)  {
				struct book_st a = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = a;
			}
		}
	}
}
//sap xep danh sach theo the loai
void timtheotheloai(struct book_st *ds, int n) {
	char Ten[30];
	printf("	Nhap the loai : ");
	fflush(stdin);
	gets(Ten);
	hienthibang();
	int i, timS = 0;
	for(i = 0; i < n; i++) {
		if(strcmp(Ten, ds[i].theloai) == 0) {
			thongtinsach(ds[i]);
			timS = 1;
		}
	}
	if(timS == 0) {
		printf("\n	Khong co the loai %s trong danh sach sach !", Ten);
	}
}
//tim sach theo the loai

void hienthibang() {
	printf("-----------------------------------------------------"
	"-----------------------------\n");
	printf("	||%-20s ||%-20s ||%-30s \n", "Ten", "The loai", "Gia tien" );
}
//hien thi danh sach theo cot

void hienThiDSTV(struct book_st *ds, int n) {
	hienthibang();
	int i;
	for(i = 0; i < n; i++) {
		thongtinsach(ds[i]);
	}
	printf("-----------------------------------------------------"
	"-----------------------------\n");
}
void ghiFile(struct book_st* ds, int n) {
	getchar();
	char fName[26];
	printf("	Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i;
	fprintf(fOut,"	------------------------------------------------------------\n");
	fprintf(fOut,"	||TEN SACH   ||THE LOAI             ||GIA TIEN            ||\n");
	fprintf(fOut,"	------------------------------------------------------------\n");
	for(i = 0; i < n; i++) {
		struct book_st bs = ds[i];
		fprintf(fOut, "	||%-10s ||%-20s ||%-20d||\n",bs.ten,bs.theloai,bs.giatien	);
	}
	fprintf(fOut,"	------------------------------------------------------------\n");
	fclose(fOut);
}

void docFile(struct book_st* ds, int* n) {
	FILE* fOut = fopen("book.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct book_st bs;
			fscanf(fOut,"%10s%20s%20d\n",bs.ten,bs.theloai,&bs.giatien);
			ds[i++] = bs;
			if(feof(fOut)) { 
				break;
			}
		}
	}
	fclose(fOut);
	*n = i;
}

int main(){
	system("Color 1E");
	int key,n;
	struct book_st ds[10];
	bool daNhap = false;
	do{
		printf("\n	Nhap so luong sach: ");
		scanf("%d",&n);
	}while(n<=0);
	while(true){
		system("cls");
		printf("                                                                        \n");
		printf("          --------------------------------------------------          \n");
		printf("        *                                                    *         \n");
		printf("       *                                                      *         \n");
		printf("      *                     QUAN LY THU VIEN                   *        \n");
		printf("      *         1. Nhap thong tin sach.                        *         \n");
		printf("      *        2. Sap xep sach theo the loai(Z->A).            *         \n");
		printf("      *        3. Tim sach theo the loai.                      *        \n");
		printf("       *        4. Ghi vao tap tin nhi phan book.txt.         *         \n");
		printf("         *        5. Thoat chuong trinh.                    *         \n");
		printf("           *                                              *         \n");
		printf("             *                                          *         \n");
		printf("               *--------------------------------------*         \n");
		printf(" ----------------------------------------------------------------------------\n");
		printf("	Ban chon: ");
		scanf("%d",&key);
		switch(key){
			case 1:
				nhapN(ds,n);
				printf("	Ban da nhap thanh cong !\n");
				daNhap = true;
				printf("	Bam bat ki phim nao de tiep tuc !");
				getch();
				break;
			case 2:
				if(daNhap){
					printf("	Thong tin sach sau khi sap xep :\n");
					sapxep(ds,n);
					hienThiDSTV(ds,n);
				}
				else{
					printf("	LUU Y: Nhap thong tin cho sach truoc!\n");
				}
				printf("	Bam bat ki phim nao de tiep tuc!");
				getch();
				break;
			
			case 3:
				if(daNhap){
					timtheotheloai(ds,n);
				}
				else{
					printf("	LUU Y: Nhap thong tin cho sach truoc!\n");
				}
				printf("	Nhan phim bat ki de tiep tuc\n");
				getch();
				break;
			case 4:
				if(daNhap){
				ghiFile(ds,n);
				}
				else{
					printf("	LUU Y: Nhap thong tin cho sach truoc!\n");
				}
				printf("	Nhan phim bat ki de tiep tuc\n");
				getch();
				break;
			case 5:
				return 0;
				break;
			default :
				printf("	Khong co chuc nang nay\n");
				printf("	Bam phim bat ki de tiep tuc!");
				getch();
				break;	
			}	
		}
	}

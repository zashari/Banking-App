#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define clear system("cls");

typedef struct data{
	char name[50];
	char date[30];
	long long int hp[15];
	long long int saldoA;
	
} nasabah;


void add(){
	clear
	nasabah s;
	FILE *fp;
	//s = (nasabah*)calloc(1, sizeof(nasabah));
	fp = fopen("datanasabah.txt", "a");
	printf ("================================================================\n");
	printf ("                                                               |");
	printf ("\n                         BANK SUNIB                            |\n");
	printf ("                                                               |\n");
	printf ("================================================================\n");
	
	printf ("Silahkan isi data diri anda!\n");
	printf ("Pastikan data diri anda lengkap dan sesuai..\n");
	printf ("----------------------------------------------------------------\n");
	fflush(stdin);
	printf("Nama\t\t\t\t:"); scanf("%[^\n]s", s.name);
	fflush(stdin);
	printf("No.HP\t\t\t\t:"); scanf("%lld", &s.hp);
	fflush(stdin);
	printf("Tanggal Pembuatan Rekening\t:"); scanf("%[^\n]s", s.date);
	fflush(stdin);
	printf("Saldo Awal\t\t\t:"); scanf("%lld", &s.saldoA);
	printf ("----------------------------------------------------------------\n");
	
	fwrite(&s, sizeof(nasabah),1,fp);
	fclose(fp);
	
	printf ("\nData berhasil disimpan!\n");
	printf ("Tekan enter untuk melanjutkan!\n");
	getch();
	
}
void setor(){
	clear
	char name[50];
	long long int saldoT;
	int found = 0;
	nasabah s1;
	FILE *fp, *fpTemp;
	fp = fopen("datanasabah.txt", "r");
	fpTemp = fopen("temp.txt", "w");
	printf ("================================================================\n");
	printf ("                                                               |");
	printf ("\n                         BANK SUNIB                            |\n");
	printf ("                                                               |\n");
	printf ("================================================================\n");
    printf ("\n                       PENYETORAN SALDO                        |\n");
    printf ("================================================================\n");
	
		if(fp == NULL)
			{
				printf ("\n\t\t    Data Tidak Ditemukan!\n\n");
				printf ("================================================================\n");
			}
		
		fflush(stdin);
		printf("\nMasukkan Nama Nasabah\t\t: "); scanf("%[^\n]s", name);
		while(fread(&s1, sizeof(nasabah),1,fp))
		{
			if(strcmp(s1.name, name) == 0)
			{
				found = 1;
				fflush(stdin);
				printf("Masukkan Jumlah Setor Saldo\t: "); scanf("%lld", &saldoT);
				s1.saldoA = s1.saldoA + saldoT;
			}
			fwrite(&s1, sizeof(nasabah), 1, fpTemp);
		}
		fclose(fp);
		fclose(fpTemp);
		
		if(found)
		{
			fpTemp = fopen("temp.txt", "r");
			fp = fopen("datanasabah.txt", "w");
			
			while(fread(&s1, sizeof(nasabah),1,fpTemp))
			{
				fwrite(&s1, sizeof(nasabah),1,fp);
			}
			
			printf("\nPenyetoran Saldo Berhasil!\n");
			printf("\nTekan ENTER Untuk Melanjutkan.\n");
			getch();
			fclose(fp);
			fclose(fpTemp);
		}
			else
			{
			printf("\nData Nasabah Tidak Ditemukan!\n");
		
			printf("\nTekan ENTER Untuk Melanjutkan.\n");
			getch();
			}
	
}
void tarik(){
	clear
	char name[50];
	long long int saldoT;
	int found = 0;
	nasabah s1;
	FILE *fp, *fpTemp;
	fp = fopen("datanasabah.txt", "r");
	fpTemp = fopen("temp.txt", "w");
	printf ("================================================================\n");
	printf ("                                                               |");
	printf ("\n                         BANK SUNIB                            |\n");
	printf ("                                                               |\n");
	printf ("================================================================\n");
    printf ("\n                       PENYETORAN SALDO                        |\n");
    printf ("================================================================\n");
	
		if(fp == NULL)
			{
				printf ("\n\t\t    Data Tidak Ditemukan!\n\n");
				printf ("================================================================\n");
			}
		
		fflush(stdin);
		printf("\nMasukkan Nama Nasabah\t\t: "); scanf("%[^\n]s", name);
		while(fread(&s1, sizeof(nasabah),1,fp))
		{
			if(strcmp(s1.name, name) == 0)
			{
				found = 1;
				fflush(stdin);
				printf("Masukkan Jumlah Setor Saldo\t: "); scanf("%lld", &saldoT);
				s1.saldoA = s1.saldoA - saldoT;
			}
			fwrite(&s1, sizeof(nasabah), 1, fpTemp);
		}
		fclose(fp);
		fclose(fpTemp);
		
		if(found)
		{
			fpTemp = fopen("temp.txt", "r");
			fp = fopen("datanasabah.txt", "w");
			
			while(fread(&s1, sizeof(nasabah),1,fpTemp))
			{
				fwrite(&s1, sizeof(nasabah),1,fp);
			}
			
			printf("\nPenarikan Saldo Berhasil!\n");
			printf("\nTekan ENTER Untuk Melanjutkan.\n");
			getch();
			fclose(fp);
			fclose(fpTemp);
		}
			else
			{
			printf("\nData Nasabah Tidak Ditemukan!\n");
		
			printf("\nTekan ENTER Untuk Melanjutkan.\n");
			getch();
			}
}
void print(){
	clear
	int index = 1;
	nasabah s1;
	FILE *fp;
	fp = fopen("datanasabah.txt", "r");
	printf ("================================================================\n");
	printf ("                                                               |");
	printf ("\n                         BANK SUNIB                            |\n");
	printf ("                                                               |\n");
	printf ("================================================================\n");
    printf ("\n                        DATA NASABAH                           |\n");
    printf ("================================================================\n");
	
		if(fp == NULL)
			{
				printf ("\n\t\t    Data Tidak Ditemukan!\n\n");
				printf ("================================================================\n");
			}
	
		while(fread(&s1, sizeof(nasabah), 1, fp))
		{
			printf("\nNasabah %d", index);
			printf("\nNama\t\t\t\t: %s\n", s1.name);
			printf("No.HP\t\t\t\t: %lld\n", s1.hp);
			printf("Tanggal Pembuatan Rekening\t: %s\n", s1.date);
			printf("Saldo Rekening\t\t\t: %lld", s1.saldoA);
			printf("\n");
			index++;
		}
	printf ("\n================================================================\n");
	printf ("Total Nasabah : %d                                              |\n", index-1);
	printf ("---------------------------------------------------------------|\n");
	printf ("Tanggal       : %s                                    |\n", __DATE__);
	printf ("Waktu         : %s                                       |\n", __TIME__);
	printf ("================================================================\n");
	printf ("\nTekan enter untuk melanjutkan!\n");
	getch();
}

void hapus(){
	clear
	nasabah s1;
	FILE *fp, *trash;
	int found = 0;
	char name[50];
	fp = fopen("datanasabah.txt", "r");
	trash = fopen("trash.txt", "w");
	printf ("================================================================\n");
	printf ("                                                               |");
	printf ("\n                         BANK SUNIB                            |\n");
	printf ("                                                               |\n");
	printf ("================================================================\n");
    printf ("\n                       PENUTUPAN AKUN                           |\n");
    printf ("================================================================\n");
	
	fflush(stdin);
	printf("Masukkan Nama Nasabah: "); scanf("%[^\n]s", name);
	
	if(fp == NULL)
			{
				printf ("\n\t\t    Data Tidak Ditemukan!\n\n");
				printf ("================================================================\n");
			}
			
		while(fread(&s1, sizeof(nasabah),1,fp))
		{
			if(strcmp(s1.name, name) == 0)
			{
				found = 1;
			}
			else
			fwrite(&s1, sizeof(nasabah), 1, trash);
		}
		fclose(fp);
		fclose(trash);
		
			if(found)
			{
			trash = fopen("trash.txt", "r");
			fp = fopen("datanasabah.txt", "w");
			
			while(fread(&s1, sizeof(nasabah),1,trash))
			{
				fwrite(&s1, sizeof(nasabah),1,fp);
			}
			
			printf("\n%s Telah Berhasil Melakukan Penutupan Akun.\n", name);
			printf ("\nTekan enter untuk melanjutkan!\n");
			getch();
			fclose(fp);
			fclose(trash);
		
			}
				else
				{
					printf("\nData Tidak Ditemukan!\n");
					printf ("\nTekan enter untuk melanjutkan!\n");
					getch();
				}
}	

int main()
{
	int ch;
	do{
		clear
	printf ("========================================\n");
	printf ("                                       |");
	printf ("\n     Selamat Datang di Bank Sunib      |\n");
	printf ("                                       |\n");
	printf ("========================================\n");
	printf ("|1. TAMBAH AKUN\t\t\t       |\n");
	printf ("|2. SETOR\t\t\t       |\n");
	printf ("|3. TARIK\t\t\t       |\n");
	printf ("|4. PRINT AKUN\t\t\t       |\n");
	printf ("|5. HAPUS AKUN\t\t\t       |\n");
	printf ("|0. KELUAR\t\t\t       |\n");
	printf ("========================================\n");
	printf("Masukkan pilihan anda: "); scanf("%d", &ch);
	
	switch(ch)
	{
		case 1:
			add();
			break;
		case 2:
			setor();
			break;
		case 3:
			tarik();
			break;
		case 4:
			print();
			break;
		case 5:
			hapus();
			break;
		case 0:
			printf("\nTerima Kasih\n");
			break;
	}
	
	}while(ch != 0);
	
	return 0;
}

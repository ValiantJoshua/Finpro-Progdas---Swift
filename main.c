#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nama[50];
	float daya;
	float durasi;
} Perangkat;

int main (){
 int menu; //yang dipilih user apakah mau input total kwh atau satu per satu
	int input; //yang diinput user nanti untuk memilih apakah mau lanjut menambahkan perangkat atau tidak
 float totalkwh; //total kwh dari perangkat elektronik

	printf("=========================================\n");
	printf("        Renewable Energy Simulator       \n");
	printf("=========================================\n");
	//Kenapa gak pake for loop? -Rasya 
 printf("Pilih Opsi: \n");
 printf("1. Input perangkat elektronik satu per satu\n");
 printf("2. Input total konsumsi listrik per hari (Kwh)\n");
 printf("Pilihan anda: ");
 scanf("%d", &menu);

 if (menu==1){
  Perangkat *perangkat = (Perangkat *)malloc(1 * sizeof(Perangkat)); //buat pointer ke struct dan alokasi ukuran array perangkat jadi 1 terlebih dahulu
  int i = 0; //counter

  do {
   printf("\nPerangkat Elektronik-%d\n", i+1);
   printf("Nama perangkat elektronik: ");
   getchar();
   scanf(" %[^\n]", perangkat[i].nama);
   
   printf("Daya (Watt): ");
   scanf("%f", &perangkat[i].daya);
   
   printf("Rata-rata durasi pemakaian per hari (jam): ");
   scanf("%f", &perangkat[i].durasi);
   
   i++; 
   
   printf("\nApakah Anda ingin menambahkan perangkat lagi? (1 = Ya, 0 = Tidak): ");
   scanf("%d", &input);
   if (input == 0) {
			break;
		}
		//jika masih lanjut, maka tambah ukuran array (+ 1)
  		perangkat = (Perangkat *) realloc (perangkat, (i + 1) * sizeof(Perangkat));
   } while (input == 1);

 }else if(menu==2){
  printf("\nMasukan total konsumsi listrik per hari (dalam Kwh): ");
  scanf("%f", &totalkwh);
 } else{
  printf("Pilihan tidak valid\n");
 }

	int pick, jml; //Pilihan Renewable Energy yang mana, Jumlah alat renewable energy
	int initialCost, energy; //Initial Cost dan Energy
	
	printf("\nPilih Renewable Energy yang ingin digunakan :\n1. Panel Surya\n2. Kincir Angin\n3. Kincir Air\n : ");
	scanf("%d", &pick);
	
	//Harga masih placeholder, Energy dalam KwH
	printf("Tentukan Harga awal dari alat Renewable Energy : ");
	scanf("%d" ,&initialCost);
	
	printf("Tentukan Energy yang dihasilkan oleh alat Renewable Energy : ");
	scanf("%d", &energy);
	
	printf("Tentukan jumlah alat Renewable Energy : ");
	scanf("%d", &jml);
	
    return 0; //selesai
}

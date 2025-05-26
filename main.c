#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nama[50];
	float daya_perangkat;
	float durasi_perangkat;
} Perangkat;

typedef struct {
	int harga_alat;
	int daya_alat;
	int durasi_alat;
	int jumlah_alat;
} Alat;

void install_alat (float harga_kwh, float biaya_listrik[], Alat alat) {
	biaya_listrik[1] += alat.harga_alat * alat.jumlah_alat;
	biaya_listrik[1] -= alat.daya_alat * alat.durasi_alat * harga_kwh * alat.jumlah_alat * 30 / 1000;
}

int main (){
	int pilihan, n = 0; //yang diinput user nanti untuk memilih apakah mau lanjut menambahkan perangkat atau tidak dan n = counter
	float harga_kwh = 1444.7;
	float total_kwh[2] = {0};
	float biaya_listrik[2] = {0};

	printf("=========================================\n");
	printf("        Renewable Energy Simulator       \n");
	printf("=========================================\n");

	printf("\nPilih mode input simulator\n");
	printf("1. Input daya per perangkat (jika tidak mengetahui listrik yang digunakan rumah per bulan)\n");
	printf("2. Input daya total per bulan\n");
	printf("Pilihan (1 atau 2) : ");
	scanf("%d", &pilihan);

	if (pilihan == 1) {
		Perangkat *perangkat = (Perangkat *)malloc(1 * sizeof(Perangkat)); //buat pointer ke struct dan alokasi ukuran array perangkat jadi 1 terlebih dahulu
		do {
			printf("\nPerangkat Elektronik - %d\n", n + 1);
			printf("Nama : ");
			getchar();
			scanf(" %[^\n]", perangkat[n].nama);

			printf("Daya (Watt): ");
			scanf("%f", &perangkat[n].daya_perangkat);

			printf("Rata-rata durasi pemakaian per hari (jam): ");
			scanf("%f", &perangkat[n].durasi_perangkat); 

			printf("\nApakah masih ada perangkat lagi? (1 = Ya, 0 = Tidak): ");
			scanf("%d", &pilihan);
			if (pilihan == 0) {
				break;
			}
			//jika masih lanjut, maka tambah ukuran array (+ 1)
  			perangkat = (Perangkat *) realloc (perangkat, (n + 2) * sizeof(Perangkat));
			n++;
		} while (pilihan == 1);

		for (int i = 0; i < n + 1; i++) {
			total_kwh[0] += perangkat[i].daya_perangkat * perangkat[i].durasi_perangkat / 1000 * 30;
		} // menghitung kWh per bulan

	} else if (pilihan == 2) {
		printf("Daya total yang digunakan per bulan (kWh) : ");
		scanf("%f", &total_kwh[0]);

	} else {
		printf("Input tidak sesuai\n");
		return 1;
	}

	biaya_listrik[0] += total_kwh[0] * harga_kwh;
	total_kwh[1] = total_kwh[0];
	biaya_listrik[1] = biaya_listrik[0];

	Alat alat[6] = {
        {.harga_alat = 600000,   .daya_alat = 100,  .durasi_alat = 5, .jumlah_alat = 0}, // panel_surya1
        {.harga_alat = 1800000,  .daya_alat = 300,  .durasi_alat = 5, .jumlah_alat = 0}, // panel_surya2
        {.harga_alat = 2600000,  .daya_alat = 550,  .durasi_alat = 5, .jumlah_alat = 0}, // panel_surya3
        {.harga_alat = 4000000,  .daya_alat = 300,  .durasi_alat = 8, .jumlah_alat = 0}, // turbin_angin1
        {.harga_alat = 8000000,  .daya_alat = 800,  .durasi_alat = 8, .jumlah_alat = 0}, // turbin_angin2
        {.harga_alat = 10000000, .daya_alat = 1000, .durasi_alat = 8, .jumlah_alat = 0}  // turbin_angin3
    };

	printf("\nAlat Renewable Energy\n");
	while (pilihan != 8) {
		printf("1. Panel Surya 100 W   (+-15 kWh/bulan)   (Rp600.000)\n");
		printf("2. Panel Surya 300 W   (+-45 kWh/bulan)   (Rp1.800.000)\n");
		printf("3. Panel Surya 550 W   (+-82,5 kWh/bulan) (Rp2.600.000)\n");
		printf("4. Turbin Angin 300 W  (+-72 kWh/bulan)   (Rp4.000.000)\n");
		printf("5. Turbin Angin 800 W  (+-192 kWh/bulan)  (Rp8.000.000)\n");
		printf("6. Turbin Angin 1000 W (+-240 kWh/bulan)  (Rp10.000.000)\n");
		printf("7. Lihat isi keranjang\n");
		printf("8. Selesai\n");
		printf("Pilihan : ");
		scanf("%d", &pilihan);

		switch (pilihan) {
			case 1:

			case 2:

			case 3:

			case 4:

			case 5:

			case 6:

			case 7:
				
			case 8:
		}
		
	}
	
    return 0; //selesai
}




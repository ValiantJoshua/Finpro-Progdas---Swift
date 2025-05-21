#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nama[50];
	float daya_perangkat;
	float durasi_perangkat;
} Perangkat;

typedef struct {
	float harga_alat;
	float daya_alat;
	int jumlah_alat;
	float biaya_listrik_alat;
} Alat;

void install_panel_surya (float harga_kwh, float biaya_listrik[], Alat panel_surya) {
	biaya_listrik[1] += panel_surya.harga_alat * panel_surya.jumlah_alat;
	biaya_listrik[1] -= panel_surya.daya_alat * harga_kwh * panel_surya.jumlah_alat;
}

void install_turbin_angin (float harga_kwh, float biaya_listrik[], Alat turbin_angin) {
	biaya_listrik[1] += turbin_angin.harga_alat * turbin_angin.jumlah_alat;
	biaya_listrik[1] -= turbin_angin.daya_alat * harga_kwh * turbin_angin.jumlah_alat;
}

void install_turbin_air (float harga_kwh, float biaya_listrik[], Alat turbin_air) {
	biaya_listrik[1] += turbin_air.harga_alat * turbin_air.jumlah_alat;
	biaya_listrik[1] -= turbin_air.daya_alat * harga_kwh * turbin_air.jumlah_alat;
}

int main (){
	int input; //yang diinput user nanti untuk memilih apakah mau lanjut menambahkan perangkat atau tidak
	float harga_kwh;
	Perangkat *perangkat = (Perangkat *)malloc(1 * sizeof(Perangkat)); //buat pointer ke struct dan alokasi ukuran array perangkat jadi 1 terlebih dahulu
	int i = 0; //counter

	printf("=========================================\n");
	printf("        Renewable Energy Simulator       \n");
	printf("=========================================\n");
	//Kenapa gak pake for loop? -Rasya
	printf("Harga listrik per kWh : ");
	scanf("%f", &harga_kwh);

	do {
		printf("\nPerangkat Elektronik-%d\n", i+1);
		printf("Nama perangkat elektronik: ");
		getchar();
		scanf(" %[^\n]", perangkat[i].nama);

		printf("Daya (Watt): ");
		scanf("%f", &perangkat[i].daya_perangkat);

		printf("Rata-rata durasi pemakaian per hari (jam): ");
		scanf("%f", &perangkat[i].durasi_perangkat); 

		printf("\nApakah Anda ingin menambahkan perangkat lagi? (1 = Ya, 0 = Tidak): ");
		scanf("%d", &input);
		if (input == 0) {
			break;
		}
		//jika masih lanjut, maka tambah ukuran array (+ 1)
  		perangkat = (Perangkat *) realloc (perangkat, (i + 2) * sizeof(Perangkat));

		i++;
	} while (input == 1);

	float total_kwh[2] = {0};
	float biaya_listrik[2] = {0};

	for (int j = 0; j < i + 1; j++) {
		total_kwh[0] += perangkat[j].daya_perangkat * perangkat[j].durasi_perangkat / 1000 * 30;
		biaya_listrik[0] += total_kwh[0] * harga_kwh;
	} // menghitung biaya listrik tanpa menggunakan alat renewable energy

	biaya_listrik[1] = biaya_listrik[0];

	Alat panel_surya, turbin_angin, turbin_air;
	int pilihan;

	do {
		printf("\nAlat Renewable Energy yang ingin digunakan :\n1. Panel Surya\n2. Turbin Angin\n3. Turbin Air\n4. Selesai\nPilihan : ");
		scanf("%d", &pilihan);

		switch (pilihan) {
			case 1:
				printf("\nHarga dari Panel Surya : ");
				scanf("%f" , &panel_surya.harga_alat);
	
				printf("Daya yang dihasilkan Panel Surya per hari (kWh) : ");
				scanf("%f", &panel_surya.daya_alat);
	
				printf("Jumlah Panel Surya : ");
				scanf("%d", &panel_surya.jumlah_alat);

				install_panel_surya(harga_kwh, biaya_listrik, panel_surya);
				break;
			case 2:
				printf("\nHarga dari Turbin Angin : ");
				scanf("%f" ,&turbin_angin.harga_alat);
	
				printf("Daya yang dihasilkan Turbin Angin (kWh) : ");
				scanf("%f", &turbin_angin.daya_alat);
	
				printf("Jumlah Turbin Angin : ");
				scanf("%d", &turbin_angin.jumlah_alat);

				install_turbin_angin(harga_kwh, biaya_listrik, turbin_angin);
				break;
			case 3:
				printf("\nHarga dari Turbin Air : ");
				scanf("%f" ,&turbin_air.harga_alat);
	
				printf("Daya yang dihasilkan Turbin Air (kWh) : ");
				scanf("%f", &turbin_air.daya_alat);
	
				printf("Jumlah Turbin Air : ");
				scanf("%d", &turbin_air.jumlah_alat);

				install_turbin_air(harga_kwh, biaya_listrik, turbin_air);
				break;
			case 4:
				break;
		}

	} while (pilihan != 4);
	
    return 0; //selesai
}

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
	int jumlah_alat;
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
	int pilihan, n = 0; //yang diinput user nanti untuk memilih apakah mau lanjut menambahkan perangkat atau tidak dan i = counter
	float harga_kwh = 1444.7;
	float total_kwh[2] = {0};
	float biaya_listrik[2] = {0};
	Perangkat *perangkat = (Perangkat *)malloc(1 * sizeof(Perangkat)); //buat pointer ke struct dan alokasi ukuran array perangkat jadi 1 terlebih dahulu

	printf("=========================================\n");
	printf("        Renewable Energy Simulator       \n");
	printf("=========================================\n");

	printf("\nPilih mode input simulator\n");
	printf("1. Input daya per perangkat (jika tidak mengetahui listrik yang digunakan rumah per bulan)\n");
	printf("2. Input daya total per bulan\n");
	printf("Pilihan (1 atau 2) : ");
	scanf("%d", &pilihan);

	if (pilihan == 1) {
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

	Alat panel_surya = {
		.harga_alat = 2000000,
		.daya_alat = 400
	};
	Alat turbin_angin = {
		.harga_alat = 4000000,
		.daya_alat = 400
	};
	Alat turbin_air = {
		.harga_alat = 2000000,
		.daya_alat = 400
	};

	printf("\nAlat Renewable Energy\n");
	printf("1. Panel Surya\n");
	printf("Harga alat : Rp%d\n", panel_surya.harga_alat);
	printf("Daya alat : %d W\n", panel_surya.daya_alat);
	printf("\n2. Turbin Angin\n");
	printf("Harga alat : Rp%d\n", turbin_angin.harga_alat);
	printf("Daya alat : %d W\n", turbin_angin.daya_alat);
	printf("\n3. Turbin Air\n");
	printf("Harga alat : Rp%d\n", turbin_air.harga_alat);
	printf("Daya alat : %d W\n", turbin_air.daya_alat);

	printf("\nInput berapa jumlah Panel Surya yang diinginkan : ");
	scanf("%d", panel_surya.jumlah_alat);
	printf("Input berapa jumlah Turbin Angin yang diinginkan : ");
	scanf("%d", turbin_angin.jumlah_alat);
	printf("Input berapa jumlah Turbin Air yang diinginkan : ");
	scanf("%d", turbin_air.jumlah_alat);
	
    return 0; //selesai
}




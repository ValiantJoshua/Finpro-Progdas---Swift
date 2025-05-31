#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nama[50];
	float daya_perangkat; // watt
	float durasi_perangkat; // jam dalam sehari
	float kwh_perangkat; // per bulan
} Perangkat;

typedef struct {
	char nama_alat[20];
	float harga_alat;
	float kwh_alat; // per bulan
	int jumlah_alat;
	float emisi_karbon_alat; // per bulan
} Alat;

void displayHouse (int jumlah_panel, int jumlah_turbin) {
    printf("\nSimulasi Rumah :\n");
    printf("  __________________\n");
    printf(" /                  \\\n");
    printf("/____________________\\\n");
    printf(" |                  |\n");
    printf(" |   []        []   |\n");
    printf(" |                  |\n");
    printf(" |        []        |\n");
    printf(" |________!!________|\n");
    
    for (int i = 0; i < jumlah_panel || i < jumlah_turbin; i++) {
		printf("#############");
    }
    printf("\n");

    if (jumlah_panel > 0) {
        for (int i = 0; i < jumlah_panel; i++) {
            printf("   _________ ");
        }
        printf("\n");
        for (int i = 0; i < jumlah_panel; i++) {
            printf("  /========/ ");
        }
        printf("\n");
        for (int i = 0; i < jumlah_panel; i++) {
            printf(" /========/  ");
        }
        printf("\n");
        for (int i = 0; i < jumlah_panel; i++) {
            printf("/________/   ");
        }
        printf("\n");
        for (int i = 0; i < jumlah_panel; i++) {
            printf("    | |      ");
        }
        printf("\n");
    }
    printf("\n");

    if (jumlah_turbin > 0) {
        for (int i = 0; i < jumlah_turbin; i++) {
            printf("     [       ");
        }
        printf("\n");
        for (int i = 0; i < jumlah_turbin; i++) {
            printf("     [       ");
        }
        printf("\n");
        for (int i = 0; i < jumlah_turbin; i++) {
            printf("  ===O===    ");
        }
        printf("\n");
        for (int i = 0; i < jumlah_turbin; i++) {
            printf("     |       ");
        }
        printf("\n");
        for (int i = 0; i < jumlah_turbin; i++) {
            printf("     |       ");
        }
        printf("\n");
    }
}

int intInputErrorHandling (int max, int min) {
	int input;
	if (max == -1) {
		do {
			scanf("%d", &input);
			if (input <= min) puts("Input invalid, silakan coba lagi.");
		} while (input <= min);
		return input;
	}

	do {
		scanf("%d", &input);
		if (input > max || input <= min) puts("Input invalid, silakan coba lagi.");
	} while (input > max || input <= min);
	return input;
}

float floatInputErrorHandling (float max, float min) {
	float input;
	if (max == -1) {
		do {
			scanf("%f", &input);
			if (input <= min) puts("Input invalid, silakan coba lagi.");
		} while (input <= min);
		return input;
	}

	do {
		scanf("%f", &input);
		if (input > max || input <= min) puts("Input invalid, silakan coba lagi.");
	} while (input > max || input <= min);
	return input;
}

int main (){
	int pilihan, mode, n = 0; // input pilihan user, input mode, dan counter
	float harga_kwh = 1444.7; 
	float total_kwh_pln[2] = {0}; // index pertama berisi total kwh tanpa non-renewable, index kedua berisi total kwh renewable
	float biaya_listrik_pln[2] = {0}; // index pertama berisi biaya total tanpa non-renewable, index kedua berisi biaya total renewable
	float emisi_karbon[2] = {0}; // index pertama berisi emisi karbon tanpa non-renewable, index kedua berisi emisi karbon renewable
	int jumlah_panel = 0, jumlah_turbin = 0;
	Perangkat *perangkat = (Perangkat *)malloc(1 * sizeof(Perangkat)); //buat pointer ke struct dan alokasi ukuran array perangkat jadi 1 terlebih dahulu

	printf("=========================================\n");
	printf("        Renewable Energy Simulator       \n");
	printf("=========================================\n");

	do {	
		printf("\nPilih mode input simulator\n");
		printf("1. Input daya per perangkat\n");
		printf("2. Input daya total per bulan\n");
		printf("Pilihan : ");
		mode = intInputErrorHandling(2, 0);

		if (mode == 1) {
			do {
				printf("\nPerangkat Elektronik %d\n", n + 1);
				printf("Nama : ");
				scanf(" %[^\n]", perangkat[n].nama);

				printf("Daya (Watt): ");
				perangkat[n].daya_perangkat = floatInputErrorHandling(-1, 0);

				printf("Rata-rata durasi pemakaian per hari (jam): ");
				perangkat[n].durasi_perangkat = floatInputErrorHandling(24,0);

				printf("\nApakah masih ada perangkat lagi? (1 = Ya, 0 = Tidak) : ");
				pilihan = intInputErrorHandling(1, -1);
				if (pilihan == 0) {
					break;
				}
				n++;
  				perangkat = (Perangkat *) realloc (perangkat, (n + 1) * sizeof(Perangkat));
			} while (pilihan == 1);

			for (int i = 0; i <= n; i++) {
				perangkat[i].kwh_perangkat = perangkat[i].daya_perangkat * perangkat[i].durasi_perangkat / 1000 * 30;
				total_kwh_pln[0] += perangkat[i].kwh_perangkat;
			}
			break;
		} else if (mode == 2) {
			printf("\nDaya total yang digunakan per bulan (kWh) : ");
			total_kwh_pln[0] = intInputErrorHandling(-1,0);
			break;
		} else {
			printf("\nInput invalid, silakan coba lagi.\n");
		}
	} while (mode != 1 || mode != 2);

	biaya_listrik_pln[0] = total_kwh_pln[0] * harga_kwh;
	emisi_karbon[0] = total_kwh_pln[0] * 0.85;

	if (mode == 1) {
		printf("\nPenggunaan Listrik Perangkat Elektronik Rumah :\n");
		printf("+----------------------+---------------------+-----------------------+----------------------+\n");
		printf("| %-20s | %-19s | %-21s | %-20s |\n", "Perangkat", "Listrik / Bulan", "Biaya Listrik / Bulan", "Emisi Karbon / Bulan");
		printf("+----------------------+---------------------+-----------------------+----------------------+\n");
		for (int i = 0; i <= n; i++) {
			printf("| %-20s | %-9.2f kWh/bulan | Rp%-13.2f/bulan | %-11.2f kg/bulan |\n", perangkat[i].nama, perangkat[i].kwh_perangkat, perangkat[i].kwh_perangkat * harga_kwh, perangkat[i].kwh_perangkat * 0.85);
		}
		printf("+----------------------+---------------------+-----------------------+----------------------+\n");
		printf("| %-20s | %-9.2f kWh/bulan | Rp%-13.2f/bulan | %-11.2f kg/bulan |\n", "Total", total_kwh_pln[0], biaya_listrik_pln[0], emisi_karbon[0]);
		printf("+----------------------+---------------------+-----------------------+----------------------+\n");
	} else if (mode == 2) {
		printf("\nPenggunaan listrik rumah :\n");
		printf("+---------------------+-----------------------+----------------------+\n");
		printf("| %-19s | %-21s | %-20s |\n", "Listrik / Bulan", "Biaya Listrik / Bulan", "Emisi Karbon / Bulan");
		printf("+---------------------+-----------------------+----------------------+\n");
		printf("| %-9.2f kWh/bulan | Rp%-13.2f/bulan | %-11.2f kg/bulan |\n", total_kwh_pln[0], biaya_listrik_pln[0], emisi_karbon[0]);
		printf("+---------------------+-----------------------+----------------------+\n");
	}

	Alat alat[6] = {
        {.nama_alat = "Panel Surya 100 W",   .harga_alat = 600000,   .kwh_alat = 15,   .jumlah_alat = 0, .emisi_karbon_alat = 0.05}, // panel_surya1
        {.nama_alat = "Panel Surya 300 W",   .harga_alat = 1800000,  .kwh_alat = 45,   .jumlah_alat = 0, .emisi_karbon_alat = 0.05}, // panel_surya2
        {.nama_alat = "Panel Surya 550 W",   .harga_alat = 2600000,  .kwh_alat = 82.5, .jumlah_alat = 0, .emisi_karbon_alat = 0.05}, // panel_surya3
        {.nama_alat = "Turbin Angin 300 W",  .harga_alat = 4000000,  .kwh_alat = 72,   .jumlah_alat = 0, .emisi_karbon_alat = 0.02}, // turbin_angin1
        {.nama_alat = "Turbin Angin 800 W",  .harga_alat = 8000000,  .kwh_alat = 192,  .jumlah_alat = 0, .emisi_karbon_alat = 0.02}, // turbin_angin2
        {.nama_alat = "Turbin Angin 1000 W", .harga_alat = 10000000, .kwh_alat = 240,  .jumlah_alat = 0, .emisi_karbon_alat = 0.02}  // turbin_angin3
	};

	float biaya_alat = 0, temp;

	while (pilihan != 8) {
		printf("\n                                   Toko Alat Renewable Energy                                 \n");
		printf("+------------------------+-------------------------+------------------------------+--------------+\n");
		printf("| Alat Renewable Energy  | Listrik yang diproduksi | Emisi karbon yang diproduksi | Biaya alat   |\n");
		printf("+------------------------+-------------------------+------------------------------+--------------+\n");
		printf("| 1. Panel Surya   100 W | \u00b1 15   kWh/bulan        | \u00b1 0.05 kg/bulan              | Rp600.000    |\n");
		printf("| 2. Panel Surya   300 W | \u00b1 45   kWh/bulan        | \u00b1 0.05 kg/bulan              | Rp1.800.000  |\n");
		printf("| 3. Panel Surya   550 W | \u00b1 82,5 kWh/bulan        | \u00b1 0.05 kg/bulan              | Rp2.600.000  |\n");
		printf("| 4. Turbin Angin  300 W | \u00b1 72   kWh/bulan        | \u00b1 0.02 kg/bulan              | Rp4.000.000  |\n");
		printf("| 5. Turbin Angin  800 W | \u00b1 192  kWh/bulan        | \u00b1 0.02 kg/bulan              | Rp8.000.000  |\n");
		printf("| 6. Turbin Angin 1000 W | \u00b1 240  kWh/bulan        | \u00b1 0.02 kg/bulan              | Rp10.000.000 |\n");
		printf("+------------------------+-------------------------+------------------------------+--------------+\n");
		printf("  7. Lihat isi keranjang\n");
		printf("  8. Selesai\n");
		printf("Pilih alat yang ingin digunakan\n");
		printf("Pilihan : ");
		scanf("%d", &pilihan);

		switch (pilihan) {
			case 1:
				printf("Jumlah : ");
				temp = intInputErrorHandling(-1, 0);
				alat[0].jumlah_alat += temp;
				jumlah_panel += temp;
				break;
			case 2:
				printf("Jumlah : ");
				temp = intInputErrorHandling(-1, 0);
				alat[1].jumlah_alat += temp;
				jumlah_panel += temp;
				break;
			case 3:
				printf("Jumlah : ");
				temp = intInputErrorHandling(-1, 0);
				alat[2].jumlah_alat += temp;
				jumlah_panel += temp;
				break;
			case 4:
				printf("Jumlah : ");
				temp = intInputErrorHandling(-1, 0);
				alat[3].jumlah_alat += temp;
				jumlah_turbin += temp;
				break;
			case 5:
				printf("Jumlah : ");
				temp = intInputErrorHandling(-1, 0);
				alat[4].jumlah_alat += temp;
				jumlah_turbin += temp;
				break;
			case 6:
				printf("Jumlah : ");
				temp = intInputErrorHandling(-1, 0);
				alat[5].jumlah_alat += temp;
				jumlah_turbin += temp;
				break;
			case 7:
				do {
					biaya_alat = alat[0].jumlah_alat * alat[0].harga_alat + alat[1].jumlah_alat * alat[1].harga_alat + alat[2].jumlah_alat * alat[2].harga_alat + alat[3].jumlah_alat * alat[3].harga_alat + alat[4].jumlah_alat * alat[4].harga_alat + alat[5].jumlah_alat * alat[5].harga_alat;
					printf("\nIsi Keranjang:\n");
					printf("+------------------------+--------+-----------------+\n");
					printf("| Alat Renewable Energy  | Jumlah | Biaya Alat      |\n");
					printf("+------------------------+--------+-----------------+\n");
					printf("| 1. Panel Surya 100 W   | %-6d | Rp%-13.2f |\n", alat[0].jumlah_alat, alat[0].jumlah_alat * alat[0].harga_alat);
					printf("| 2. Panel Surya 300 W   | %-6d | Rp%-13.2f |\n", alat[1].jumlah_alat, alat[1].jumlah_alat * alat[1].harga_alat);
					printf("| 3. Panel Surya 550 W   | %-6d | Rp%-13.2f |\n", alat[2].jumlah_alat, alat[2].jumlah_alat * alat[2].harga_alat);
					printf("| 4. Turbin Angin 300 W  | %-6d | Rp%-13.2f |\n", alat[3].jumlah_alat, alat[3].jumlah_alat * alat[3].harga_alat);
					printf("| 5. Turbin Angin 800 W  | %-6d | Rp%-13.2f |\n", alat[4].jumlah_alat, alat[4].jumlah_alat * alat[4].harga_alat);
					printf("| 6. Turbin Angin 1000 W | %-6d | Rp%-13.2f |\n", alat[5].jumlah_alat, alat[5].jumlah_alat * alat[5].harga_alat);
					printf("+------------------------+--------+-----------------+\n");
					printf("| Total                  | %-6d | Rp%-13.2f |\n", jumlah_panel + jumlah_turbin, biaya_alat);
					printf("+------------------------+--------+-----------------+\n");
					printf("  7. Kembali ke toko\n");
					printf("Pilih alat yang ingin dikurangi\n");
					printf("Pilihan : ");
					scanf("%d", &pilihan);
					
					// Memastikan input tidak bisa bernilai negatif atau lebih dari jumlah sekarang
					switch (pilihan) {
						case 1:
							if (alat[0].jumlah_alat > 0){
								printf("Jumlah alat : %d\n", alat[0].jumlah_alat);
								printf("Jumlah yang ingin dikurangi : ");
								temp = intInputErrorHandling(alat[0].jumlah_alat, -1);
								alat[0].jumlah_alat -= temp;
								jumlah_panel -= temp;
							} else {
								printf("Input Invalid, silahkan coba lagi\n");
							}
							break;

						case 2:
							if (alat[1].jumlah_alat > 0){
								printf("Jumlah : %d\n", alat[1].jumlah_alat);
								printf("Jumlah yang ingin dikurangi : ");
								temp = intInputErrorHandling(alat[1].jumlah_alat, -1);
								alat[1].jumlah_alat -= temp;
								jumlah_panel -= temp;
							} else {
								printf("Input Invalid, silahkan coba lagi\n");
							}
							break;

						case 3:
							if (alat[2].jumlah_alat > 0){
								printf("Jumlah : %d\n", alat[2].jumlah_alat);
								printf("Jumlah yang ingin dikurangi : ");
								temp = intInputErrorHandling(alat[2].jumlah_alat, -1);
								alat[2].jumlah_alat -= temp;
								jumlah_panel -= temp;
							} else {
								printf("Input Invalid, silahkan coba lagi\n");
							}
							break;

						case 4:
							if (alat[3].jumlah_alat > 0){
								printf("Jumlah : %d\n", alat[3].jumlah_alat);
								printf("Jumlah yang ingin dikurangi : ");
								temp = intInputErrorHandling(alat[3].jumlah_alat, -1);
								alat[3].jumlah_alat -= temp;
								jumlah_turbin -= temp;
							} else {
								printf("Input Invalid, silahkan coba lagi\n");
							}
							break;

						case 5:
							if (alat[4].jumlah_alat > 0){
								printf("Jumlah : %d\n", alat[4].jumlah_alat);
								printf("Jumlah yang ingin dikurangi : ");
								temp = intInputErrorHandling(alat[4].jumlah_alat, -1);
								alat[4].jumlah_alat -= temp;
								jumlah_turbin -= temp;
							} else {
								printf("Input Invalid, silahkan coba lagi\n");
							}
							break;
							
						case 6:
							if (alat[5].jumlah_alat > 0){
								printf("Jumlah : %d\n", alat[5].jumlah_alat);
								printf("Jumlah yang ingin dikurangi : ");
								temp = intInputErrorHandling(alat[5].jumlah_alat, -1);
								alat[5].jumlah_alat -= temp;
								jumlah_turbin -= temp;
							} else {
								printf("Input invalid, silakan coba lagi\n");
							}
							break;

						case 7:
							break;

						default:
							printf("Input invalid, silakan coba lagi\n");
							break;
					}
				} while (pilihan != 7);
				break;

			case 8:
				break;

			default:
				printf("Input invalid, silakan coba lagi\n");
				break;
		}
	}

	if (jumlah_panel == 0 && jumlah_turbin == 0) {
		if (mode == 1) {
			printf("\nPenggunaan Listrik Perangkat Elektronik Rumah :\n");
			printf("+----------------------+---------------------+-----------------------+----------------------+\n");
			printf("| %-20s | %-19s | %-21s | %-20s |\n", "Perangkat", "Listrik / Bulan", "Biaya Listrik / Bulan", "Emisi Karbon / Bulan");
			printf("+----------------------+---------------------+-----------------------+----------------------+\n");
			for (int i = 0; i <= n; i++) {
				printf("| %-20s | %-9.2f kWh/bulan | Rp%-13.2f/bulan | %-11.2f kg/bulan |\n", perangkat[i].nama, perangkat[i].kwh_perangkat, perangkat[i].kwh_perangkat * harga_kwh, perangkat[i].kwh_perangkat * 0.85);
			}
			printf("+----------------------+---------------------+-----------------------+----------------------+\n");
			printf("| %-20s | %-9.2f kWh/bulan | Rp%-13.2f/bulan | %-11.2f kg/bulan |\n", "Total", total_kwh_pln[0], biaya_listrik_pln[0], emisi_karbon[0]);
			printf("+----------------------+---------------------+-----------------------+----------------------+\n");
		} else if (mode == 2) {
			printf("\nPenggunaan listrik rumah :\n");
			printf("+---------------------+-----------------------+----------------------+\n");
			printf("| %-19s | %-21s | %-20s |\n", "Listrik / Bulan", "Biaya Listrik / Bulan", "Emisi Karbon / Bulan");
			printf("+---------------------+-----------------------+----------------------+\n");
			printf("| %-9.2f kWh/bulan | Rp%-13.2f/bulan | %-11.2f kg/bulan |\n", total_kwh_pln[0], biaya_listrik_pln[0], emisi_karbon[0]);
			printf("+---------------------+-----------------------+----------------------+\n");
		}
		return 0;
	}
	
	printf("\nAlat Renewable Energy yang digunakan :\n");
	printf("+-----------------------+--------+------------------+----------------------+----------------------------+------------------+\n");	
	printf("| %-21s | %-6s | %-16s | %-20s | %-26s | %-16s |\n", "Alat Renewable Energy", "Jumlah", "Biaya Alat", "Listrik yang Dihemat", "Biaya Listrik yang Dihemat", "Emisi Karbon");
	printf("+-----------------------+--------+------------------+----------------------+----------------------------+------------------+\n");	
	for (int i = 0; i < 6; i++) {
		total_kwh_pln[1] += alat[i].kwh_alat * alat[i].jumlah_alat;
		emisi_karbon[1] += alat[i].emisi_karbon_alat * alat[i].kwh_alat * alat[i].jumlah_alat;

		if (alat[i].jumlah_alat) {
			printf("| %-21s | %-6d | Rp%-14.2f | %-10.2f kWh/bulan | Rp%-18.2f/bulan | %-7.2f kg/bulan |\n", alat[i].nama_alat, alat[i].jumlah_alat, alat[i].harga_alat * alat[i].jumlah_alat, alat[i].kwh_alat * alat[i].jumlah_alat, alat[i].kwh_alat * alat[i].jumlah_alat * harga_kwh, alat[i].emisi_karbon_alat * alat[i].jumlah_alat * alat[i].kwh_alat);
		}
	}

	biaya_listrik_pln[1] = total_kwh_pln[1] * harga_kwh;

	printf("+-----------------------+--------+------------------+----------------------+----------------------------+------------------+\n");
	printf("| %-21s | %-6d | Rp%-14.2f | %-10.2f kWh/bulan | Rp%-18.2f/bulan | %-7.2f kg/bulan |\n", "Total", jumlah_panel + jumlah_turbin, biaya_alat, total_kwh_pln[1], biaya_listrik_pln[1], emisi_karbon[1]);
	printf("+-----------------------+--------+------------------+----------------------+----------------------------+------------------+\n");

	total_kwh_pln[1] = total_kwh_pln[0] - total_kwh_pln[1]; // Mengubah total_kwh_pln[1] dari yang listrik dihemat menjadi total listrik baru dengan renewable energy
	biaya_listrik_pln[1] = biaya_listrik_pln[0] - biaya_listrik_pln[1]; // ini juga sama tapi untuk biaya

	int jumlahBulan; 

	printf("\nTentukan Berapa lama simulasi berjalan (bulan): ");
	jumlahBulan = intInputErrorHandling(-1,0);
	
	printf("\nSimulasi Renewable Energy %d Bulan :\n", jumlahBulan);
	printf("+-----------------------+---------------------------+----------------------------------+\n");
	printf("| %-21s | %-25s | %-32s |\n", "Perbandingan", "Non-Renewable", "Renewable");
	printf("+-----------------------+---------------------------+----------------------------------+\n");

	if (total_kwh_pln[1] < 0) {
		float kelebihan_listrik = -total_kwh_pln[1];
		total_kwh_pln[1] = 0;
		biaya_listrik_pln[1] = 0;
		printf("| %-21s | %-15.2f kWh/bulan | Kelebihan : +%-9.2f kWh/bulan |\n", "Listrik / Bulan", total_kwh_pln[0], kelebihan_listrik);
		printf("| %-21s | Rp%-16.2f /bulan | Rp%-23.2f /bulan |\n", "Biaya Listrik / Bulan", biaya_listrik_pln[0], biaya_listrik_pln[1]);
	} else {
		printf("| %-21s | %-15.2f kWh/bulan | %-22.2f kWh/bulan |\n", "Listrik / Bulan", total_kwh_pln[0], total_kwh_pln[1] * jumlahBulan);
		printf("| %-21s | Rp%-16.2f /bulan | Rp%-23.2f /bulan |\n", "Biaya Listrik / Bulan", biaya_listrik_pln[0], biaya_listrik_pln[1]);
	}
	printf("| %-21s | Rp%-23.2f | Rp%-30.2f |\n", "Total Biaya Alat", 0, biaya_alat);
	printf("| %-21s | Rp%-23.2f | Rp%-30.2f |\n", "Total Biaya", biaya_listrik_pln[0] * jumlahBulan, biaya_listrik_pln[1] * jumlahBulan + biaya_alat);
	printf("| %-21s | %-22.2f kg | %-29.2f kg |\n", "Total Emisi Karbon", emisi_karbon[0] * jumlahBulan, emisi_karbon[1] * jumlahBulan);
	printf("+-----------------------+---------------------------+----------------------------------+\n");

	int waktu_balik_modal = biaya_alat / (biaya_listrik_pln[0] - biaya_listrik_pln[1]);

	printf("Waktu balik modal: %d bulan\n", waktu_balik_modal);

	displayHouse(jumlah_panel, jumlah_turbin);

	free(perangkat);
	return 0; //selesai
}
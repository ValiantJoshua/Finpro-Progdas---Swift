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
	int harga_alat;
	float kwh_alat; // per bulan
	int jumlah_alat;
} Alat;

int displayHouse (int panelSurya, int turbinAngin){
    int i;
    printf("\n========== RUMAHMU ==========\n");
    printf("      ________________\n");
    printf("     /                 \\\n");
    printf("    /___________________\\\n");
    printf("     |                 |\n");
    printf("     |   []       []   |\n");
    printf("     |                 |\n");
    printf("     |        []       |\n");
    printf("     |________!!_______|\n");
    
    for(i=0; i<panelSurya || i<turbinAngin; i++){
            printf("#############");
        }
        printf("\n");
        
    if(panelSurya >0){
        for(i=0; i<panelSurya; i++){
            printf("   _________ ");
        }
        printf("\n");
        for(i=0; i<panelSurya; i++){
            printf("  /========/ ");
        }
        printf("\n");
        for(i=0; i<panelSurya; i++){
            printf(" /========/  ");
        }
        printf("\n");
        for(i=0; i<panelSurya; i++){
            printf("/________/   ");
        }
        printf("\n");
        for(i=0; i<panelSurya; i++){
            printf("    | |      ");
        }
        printf("\n");
    }
    printf("\n");
    if(turbinAngin > 0){
        for(i=0; i<turbinAngin; i++){
            printf("     [       ");
        }
        printf("\n");
        for(i=0; i<turbinAngin; i++){
            printf("     [       ");
        }
        printf("\n");
        for(i=0; i<turbinAngin; i++){
            printf("  ===O===    ");
        }
        printf("\n");
        for(i=0; i<turbinAngin; i++){
            printf("     |       ");
        }
        printf("\n");
        for(i=0; i<turbinAngin; i++){
            printf("     |       ");
        }
        printf("\n");
    }
}

int inputWErrorHandlingForInt (int max, int min){
	int input;
	if (max == -1){
		do{
			scanf("%d", &input);
			if (input <= min)puts("Input Invalid, silahkan coba lagi.");
		} while (input <= min);
		return input;
	}
	do{
		scanf("%d", &input);
		if (input > max || input <= min)puts("Input Invalid, silahkan coba lagi.");
	} while (input > max || input <= min);
	return input;
}

int main (){
	int pilihan, mode, n = 0, i, j; //yang diinput user nanti untuk memilih apakah mau lanjut menambahkan perangkat atau tidak dan n = counter
	float harga_kwh = 1444.7; 
	float total_kwh_pln[2] = {0};
	float biaya_listrik_pln[2] = {0};
	float emisi_karbon[2] = {0};
	int panelSurya = 0, turbinAngin = 0;
	Perangkat *perangkat = (Perangkat *)malloc(1 * sizeof(Perangkat)); //buat pointer ke struct dan alokasi ukuran array perangkat jadi 1 terlebih dahulu

	printf("=========================================\n");
	printf("        Renewable Energy Simulator       \n");
	printf("=========================================\n");

	do{	
		printf("\nPilih mode input simulator\n");
		printf("1. Input daya per perangkat (jika tidak mengetahui listrik yang digunakan rumah per bulan)\n");
		printf("2. Input daya total per bulan\n");
		printf("Pilihan (1 atau 2) : ");
		scanf("%d", &mode);

		if (mode == 1) {
			do {
				printf("\nPerangkat Elektronik - %d\n", n + 1);
				printf("Nama : ");
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

			for (i = 0; i <= n; i++) {
				perangkat[i].kwh_perangkat = perangkat[i].daya_perangkat * perangkat[i].durasi_perangkat / 1000 * 30;
				total_kwh_pln[0] += perangkat[i].kwh_perangkat;
			}
			break;
		} else if (mode == 2) {
			printf("Daya total yang digunakan per bulan (kWh) : ");
			scanf("%f", &total_kwh_pln[0]);
			break;
		} else {
			printf("\nInput tidak sesuai, Coba kembali\n");
		}
	} while (mode != 1 || mode != 2);

	biaya_listrik_pln[0] = total_kwh_pln[0] * harga_kwh;
	emisi_karbon[0] = total_kwh_pln[0] * 0.85;

	if (mode == 1) {
		printf("Perangkat Rumah");
		for (i = 0; i <= n; i++) {
			printf("\nPerangkat-%d : %s\n", i + 1, perangkat[i].nama);
			printf("Listrik per bulan : %.2f kWh\n", perangkat[i].kwh_perangkat);
		}
		printf("Total listrik per bulan : %.2f kWh\n", total_kwh_pln[0]);
		printf("Total biaya listrik per bulan : Rp%f\n", biaya_listrik_pln[0]);
	} else if (mode == 2) {
		printf("Total listrik per bulan : %.2f kWh\n", total_kwh_pln[0]);
		printf("Total biaya listrik per bulan : Rp%.2f\n", biaya_listrik_pln[0]);
	}

	Alat alat[6] = {
        {.nama_alat = "Panel Surya 100 W",   .harga_alat = 600000,   .kwh_alat = 15,   .jumlah_alat = 0}, // panel_surya1
        {.nama_alat = "Panel Surya 300 W",   .harga_alat = 1800000,  .kwh_alat = 45,   .jumlah_alat = 0}, // panel_surya2
        {.nama_alat = "Panel Surya 550 W",   .harga_alat = 2600000,  .kwh_alat = 82.5, .jumlah_alat = 0}, // panel_surya3
        {.nama_alat = "Turbin Angin 300 W",  .harga_alat = 4000000,  .kwh_alat = 72,   .jumlah_alat = 0}, // turbin_angin1
        {.nama_alat = "Turbin Angin 800 W",  .harga_alat = 8000000,  .kwh_alat = 192,  .jumlah_alat = 0}, // turbin_angin2
        {.nama_alat = "Turbin Angin 1000 W", .harga_alat = 10000000, .kwh_alat = 240,  .jumlah_alat = 0}  // turbin_angin3
	};

	int temp;

	printf("\nToko Alat Renewable Energy\n");
	while (pilihan != 8) {
		printf("Pilih alat yang ingin dibeli\n");
		printf("1. Panel Surya 100 W   | (+-15 kWh/bulan)   | (Rp600.000)\n");
		printf("2. Panel Surya 300 W   | (+-45 kWh/bulan)   | (Rp1.800.000)\n");
		printf("3. Panel Surya 550 W   | (+-82,5 kWh/bulan) | (Rp2.600.000)\n");
		printf("4. Turbin Angin 300 W  | (+-72 kWh/bulan)   | (Rp4.000.000)\n");
		printf("5. Turbin Angin 800 W  | (+-192 kWh/bulan)  | (Rp8.000.000)\n");
		printf("6. Turbin Angin 1000 W | (+-240 kWh/bulan)  | (Rp10.000.000)\n");
		printf("7. Lihat isi keranjang\n");
		printf("8. Selesai\n");
		printf("Pilihan : ");
		scanf("%d", &pilihan);

		switch (pilihan) {
			case 1:
				printf("Jumlah: ");
				temp = inputWErrorHandlingForInt(-1, 0);
				alat[0].jumlah_alat += temp;
				panelSurya += temp;
				break;
			case 2:
				printf("Jumlah: ");
				temp = inputWErrorHandlingForInt(-1, 0);
				alat[1].jumlah_alat += temp;
				panelSurya += temp;
				break;
			case 3:
				printf("Jumlah: ");
				temp = inputWErrorHandlingForInt(-1, 0);
				alat[2].jumlah_alat += temp;
				panelSurya += temp;
				break;
			case 4:
				printf("Jumlah: ");
				temp = inputWErrorHandlingForInt(-1, 0);
				alat[3].jumlah_alat += temp;
				turbinAngin += temp;
				break;
			case 5:
				printf("Jumlah: ");
				temp = inputWErrorHandlingForInt(-1, 0);
				alat[4].jumlah_alat += temp;
				turbinAngin += temp;
				break;
			case 6:
				printf("Jumlah: ");
				temp = inputWErrorHandlingForInt(-1, 0);
				alat[5].jumlah_alat += temp;
				turbinAngin += temp;
				break;
			case 7:
				do {
					printf("Isi Keranjang:\n");
					printf("1. Panel Surya 100 W   | Jumlah : %d\n", alat[0].jumlah_alat);
					printf("2. Panel Surya 300 W   | Jumlah : %d\n", alat[1].jumlah_alat);
					printf("3. Panel Surya 550 W   | Jumlah : %d\n", alat[2].jumlah_alat);
					printf("4. Turbin Angin 300 W  | Jumlah : %d\n", alat[3].jumlah_alat);
					printf("5. Turbin Angin 800 W  | Jumlah : %d\n", alat[4].jumlah_alat);
					printf("6. Turbin Angin 1000 W | Jumlah : %d\n", alat[5].jumlah_alat);
					printf("7. Kembali ke toko\n");
					printf("Pilih alat yang ingin dikurangi (jika tidak pilih 7 untuk kembali)\n");
					printf("Pilihan : ");
					scanf("%d", &pilihan);
					
					// Memastikan input tidak bisa bernilai negatif atau lebih dari jumlah sekarang
					switch (pilihan) {
						case 1:
							printf("Jumlah : %d\n", alat[0].jumlah_alat);
							printf("Jumlah yang ingin dikurangi : ");
							temp = inputWErrorHandlingForInt(alat[0].jumlah_alat, 0);
							alat[0].jumlah_alat -= temp;
							break;

						case 2:
							printf("Jumlah : %d\n", alat[1].jumlah_alat);
							printf("Jumlah yang ingin dikurangi : ");
							temp = inputWErrorHandlingForInt(alat[1].jumlah_alat, 0);
							alat[1].jumlah_alat -= temp;
							break;

						case 3:
							printf("Jumlah : %d\n", alat[2].jumlah_alat);
							printf("Jumlah yang ingin dikurangi : ");
							temp = inputWErrorHandlingForInt(alat[2].jumlah_alat, 0);
							alat[2].jumlah_alat -= temp;
							break;

						case 4:
							printf("Jumlah : %d\n", alat[3].jumlah_alat);
							printf("Jumlah yang ingin dikurangi : ");
							temp = inputWErrorHandlingForInt(alat[3].jumlah_alat, 0);
							alat[3].jumlah_alat -= temp;
							break;

						case 5:
							printf("Jumlah : %d\n", alat[4].jumlah_alat);
							printf("Jumlah yang ingin dikurangi : ");
							temp = inputWErrorHandlingForInt(alat[4].jumlah_alat, 0);
							alat[4].jumlah_alat -= temp;
							break;

						case 6:
							printf("Jumlah : %d\n", alat[5].jumlah_alat);
							printf("Jumlah yang ingin dikurangi : ");
							temp = inputWErrorHandlingForInt(alat[5].jumlah_alat, 0);
							alat[5].jumlah_alat -= temp;
							break;

						case 7:
							break;
						default:
							printf("Pilihan tidak sesuai\n");
							break;
					}
				} while (pilihan != 7);
				break;
			case 8:
				break;
			default:
				printf("\nPilihan tidak sesuai\n");
				break;
		}
	}

	if (panelSurya == 0 && turbinAngin == 0) {
		return 0;
	}

	float biaya_alat = 0;
	// output alat apa aja yang dibeli
	printf("Alat Renewable Energy yang digunakan\n");
	for (i = 0; i < 6; i++) {
		biaya_alat += alat[i].harga_alat * alat[i].jumlah_alat;
		total_kwh_pln[1] += alat[i].kwh_alat * alat[i].jumlah_alat;
		if (alat[i].jumlah_alat) {
			printf("%s %dx\n", alat[i].nama_alat, alat[i].jumlah_alat);
		}
	}
	printf("Total biaya alat : %.2f\n", biaya_alat);
	printf("Total listrik yang dihemat per bulan : %.2f kWh\n", total_kwh_pln[1]);

	biaya_listrik_pln[1] = total_kwh_pln[1] * harga_kwh;
	printf("Total biaya listrik yang dihemat per bulan : Rp%.2f\n", biaya_listrik_pln[1]);

	emisi_karbon[1] = total_kwh_pln[1] * 0.85;
	total_kwh_pln[1] = total_kwh_pln[0] - total_kwh_pln[1]; // Mengubah total_kwh_pln[1] dari yang listrik dihemat menjadi total listrik baru dengan renewable energy
	biaya_listrik_pln[1] = biaya_listrik_pln[0] - biaya_listrik_pln[1]; // ini juga sama tapi untuk biaya

	printf("Total emisi karbon yang dihemat : %.2fkg", emisi_karbon[1]);

	emisi_karbon[1] = emisi_karbon[0] - emisi_karbon[1];

	int jumlahBulan;
	int waktu_balik_modal = biaya_alat / (biaya_listrik_pln[0] - biaya_listrik_pln[1]);

	do {
		printf("\nTentukan Berapa lama simulasi berjalan (bulan): ");
		scanf("%d", &jumlahBulan);
		if (jumlahBulan <= 0)printf("Input Invalid. Silahkan Coba lagi");
	} while (jumlahBulan <= 0);

    displayHouse(panelSurya, turbinAngin);

	printf("Simulasi %d Bulan\n", jumlahBulan);
	printf("Non-Renewable | Renewable\n");
	printf("Total listrik : %.2f kWh | %.2f kWh\n", total_kwh_pln[0] * jumlahBulan, total_kwh_pln[1] * jumlahBulan);
	printf("Biaya listrik : Rp%.2f | Rp%.2f\n", biaya_listrik_pln[0] * jumlahBulan, biaya_listrik_pln[1] * jumlahBulan);
	printf("Biaya alat : Rp0 | Rp%.2f\n", biaya_alat);
	printf("Total biaya : Rp%.2f | Rp%.2f\n", biaya_listrik_pln[0] * jumlahBulan, biaya_listrik_pln[1] * jumlahBulan + biaya_alat);
	printf("Total emisi karbon : %.2f kg | %.2f kg\n", emisi_karbon[0] * jumlahBulan, emisi_karbon[1] * jumlahBulan);
	printf("Waktu untuk balik modal biaya alat : %d bulan", waktu_balik_modal);

	free(perangkat);
	return 0; //selesai
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nama[50];
	float daya_perangkat; // watt
	float durasi_perangkat; // jam dalam sehari
	float kwh_perangkat; // per bulan
} Perangkat;

typedef struct {
	int harga_alat;
	float kwh_alat; // per bulan
	int jumlah_alat;
} Alat;

/*
void cek_pengurangan_alat(Alat *alat, int index_alat, int temp){ //function untuk mengecek saat ingin mengurang dari keranjang
	if(temp >alat[index_alat].jumlah_alat){
		printf("Input Invalid. Jumlah alat yang ingin dikurangkan lebih sedikit dari keranjang");
	} else{
		alat[index_alat].jumlah_alat -= temp;
	}
}
	*/ 
	
//void houseAppl (Perangkat *perangkat[], int size){
//	int i;
//	for (i=0; i<size; i++){
//		printf("Mesin ke-%d\n", i+1);
//		printf("Nama : %s\n", perangkat[i].nama);
//	}
//}
//	
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
	int pilihan, n = 0, i, j; //yang diinput user nanti untuk memilih apakah mau lanjut menambahkan perangkat atau tidak dan n = counter
	float harga_kwh = 1444.7; 
	float total_kwh_pln[2] = {0};
	float biaya_listrik_pln[2] = {0};
	float emisi_karbon[2] = {0};
	int panelSurya = 0, turbinAngin = 0;
	Perangkat *perangkat = NULL;

	printf("=========================================\n");
	printf("        Renewable Energy Simulator       \n");
	printf("=========================================\n");

do{	
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

		for (i = 0; i < n; i++) {
			perangkat[i].kwh_perangkat = perangkat[i].daya_perangkat * perangkat[i].durasi_perangkat / 1000 * 30;
			total_kwh_pln[0] += perangkat[i].kwh_perangkat;

			}
			break;
		} else if (pilihan == 2) {
			printf("Daya total yang digunakan per bulan (kWh) : ");
			scanf("%f", &total_kwh_pln[0]);
			break;
		} else {
			printf("\nInput tidak sesuai, Coba kembali\n");

		}
	}while(pilihan !=1 || pilihan != 2);


	biaya_listrik_pln[0] = total_kwh_pln[0] * harga_kwh;
	emisi_karbon[0] = total_kwh_pln[0] * 0.85;
	
	//Set Total kwh pln agar benar 
	total_kwh_pln[1] = total_kwh_pln[0];

	//output total biaya listrik biasa dan kwh per perangkat

	Alat alat[6] = {
        {.harga_alat = 600000,   .kwh_alat = 15,   .jumlah_alat = 0}, // panel_surya1
        {.harga_alat = 1800000,  .kwh_alat = 45,   .jumlah_alat = 0}, // panel_surya2
        {.harga_alat = 2600000,  .kwh_alat = 82.5, .jumlah_alat = 0}, // panel_surya3
        {.harga_alat = 4000000,  .kwh_alat = 72,   .jumlah_alat = 0}, // turbin_angin1
        {.harga_alat = 8000000,  .kwh_alat = 192,  .jumlah_alat = 0}, // turbin_angin2
        {.harga_alat = 10000000, .kwh_alat = 240,  .jumlah_alat = 0}  // turbin_angin3
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
							temp = inputWErrorHandlingForInt(alat[1].jumlah_alat, 0);
							alat[1].jumlah_alat -= temp;
							break;

						case 7:
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
	
	int jumlahBulan;
	float modal;

	do{
		printf("\nTentukan Berapa lama simulasi berjalan (bulan): ");
		scanf("%d", &jumlahBulan);
		if (jumlahBulan <= 0)printf("Input Invalid. Silahkan Coba lagi");
	} while (jumlahBulan <= 0);
	
	for (i = 0; i < 6; i++) {
		total_kwh_pln[1] -= alat[i].kwh_alat * alat[i].jumlah_alat;
	}
	for (j=0; j<6; j++){ //menghitung total biaya yang dibutuhkan untuk membeli alat 
		modal += alat[j].harga_alat * alat[j].jumlah_alat;
	}
	biaya_listrik_pln[1] = total_kwh_pln[1] * harga_kwh;
	emisi_karbon[1] = total_kwh_pln[1] * 0.85;

	float persen_penghematan = ((total_kwh_pln[0]*jumlahBulan)-(total_kwh_pln[1]*jumlahBulan))/(total_kwh_pln[0]*jumlahBulan) *100;
	float persen_pengurangan_emisi = ((emisi_karbon[0] - emisi_karbon[1]) / emisi_karbon[0]) * 100;
	int waktu_balik_modal = modal/(biaya_listrik_pln[0]-biaya_listrik_pln[1]);

    printf("\n========== RUMAHMU ==========\n");
    printf("      ________________\n");
    printf("     /                 \\\n");
    printf("    /___________________\\\n");
    printf("     |                 |\n");
    printf("     |   []       []   |\n");
    printf("     |                 |\n");
    printf("     |        []       |\n");
    printf("     |________!!_______|\n");
    
    if(panelSurya >0){
        for(i=0; i<panelSurya; i++){
            printf("#####################");
        }
        printf("\n");
        for(i=0; i<panelSurya; i++){
            printf("         _________   ");
        }
        printf("\n");
        for(i=0; i<panelSurya; i++){
            printf("        /========/   ");
        }
        printf("\n");
        for(i=0; i<panelSurya; i++){
            printf("       /========/    ");
        }
        printf("\n");
        for(i=0; i<panelSurya; i++){
            printf("      /________/     ");
        }
        printf("\n");
        for(i=0; i<panelSurya; i++){
            printf("          | |        ");
        }
        printf("\n");
    }
    if(turbinAngin > 0){
        for(i=0; i<turbinAngin; i++){
            printf("             !       ");
        }
        printf("\n");
        for(i=0; i<turbinAngin; i++){
            printf("             !       ");
        }
        printf("\n");
        for(i=0; i<turbinAngin; i++){
            printf("         ====O====   ");
        }
        printf("\n");
        for(i=0; i<turbinAngin; i++){
            printf("             |       ");
        }
        printf("\n");
        for(i=0; i<turbinAngin; i++){
            printf("             |       ");
        }
        printf("\n");
    }


    printf("\n================= Output =================\n");
    printf("Modal yang dikeluarkan untuk alat        : Rp %.2f \n", modal);
    printf("Biaya yang dihemat perbulan              : Rp %.2f\n",biaya_listrik_pln[0]-biaya_listrik_pln[1]);
    printf("Waktu yang dibutuhkan untuk uang kembali : %d bulan\n", waktu_balik_modal);
	printf("Energi yang dihemat perbulan             : %.2f kWh\n",total_kwh_pln[0]-total_kwh_pln[1] );
	printf("Persentase pengehematan Energi           : %.2f%%\n", persen_penghematan); 
	printf("Persentase berkurangnya Emisi            : %.2f%%\n", persen_pengurangan_emisi);
	
	printf("\n+==================================================================\n");
	printf("| %-20s| %-20s| %-20s|\n", "PERBANDINGAN ENERGI", "Non-Renewable", "Renewable");
	printf("+==================================================================\n");
	printf("| %-20s| Rp %-17.2f| Rp %-17.2f|\n", "Biaya/Bulan", biaya_listrik_pln[0], biaya_listrik_pln[1]);
	printf("| %-20s| Rp %-17.2f| Rp %-17.2f|\n", "Biaya Akhir Simulasi", biaya_listrik_pln[0]*jumlahBulan, biaya_listrik_pln[1]*jumlahBulan);
	printf("| %-20s| %-16.2f Kwh| %-16.2f Kwh|\n", "Total KWH", total_kwh_pln[0]*jumlahBulan, total_kwh_pln[1]*jumlahBulan);
	printf("| %-20s| %-20.2f| %-20.2f|\n", "Emisi Karbon", emisi_karbon[0]*jumlahBulan, emisi_karbon[1]*jumlahBulan);
	printf("+==================================================================\n");
	
	return 0; //selesai
}

#include <stdio.h>

// Definisi standar pemakaian per 1 kg (dalam ml)
#define PEMAKAIAN_DETERGEN 50 
#define PEMAKAIAN_PELEMBUT 30

typedef struct {
    float detergen; // dalam ml
    float pelembut; // dalam ml
} Stok;

int main() {
    Stok gudang = {5000, 3000}; // Stok awal: 5 Liter detergen, 3 Liter pelembut
    float beratCucian;
    int pilihan;

    while (1) {
        printf("\n--- SISTEM STOK BAHAN KIMIA LAUNDRY DEL. ---\n");
        printf("1. Lihat Sisa Stok Gudang\n");
        printf("2. Input Cucian Baru (Gunakan Stok)\n");
        printf("3. Isi Ulang Stok (Restock)\n");
        printf("4. Keluar\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        if (pilihan == 4) break;

        switch (pilihan) {
            case 1:
                printf("\n--- LAPORAN STOK ---\n");
                printf("Detergen : %.2f ml (%.1f Liter)\n", gudang.detergen, gudang.detergen/1000);
                printf("Pelembut : %.2f ml (%.1f Liter)\n", gudang.pelembut, gudang.pelembut/1000);
                
                // Peringatan jika stok rendah (dibawah 1 liter)
                if (gudang.detergen < 1000) printf("!!! STOK DETERGEN KRITIS !!!\n");
                if (gudang.pelembut < 1000) printf("!!! STOK PELEMBUT KRITIS !!!\n");
                break;

            case 2:
                printf("Masukkan berat cucian (kg): ");
                scanf("%f", &beratCucian);

                float butuhDetergen = beratCucian * PEMAKAIAN_DETERGEN;
                float butuhPelembut = beratCucian * PEMAKAIAN_PELEMBUT;

                if (gudang.detergen >= butuhDetergen && gudang.pelembut >= butuhPelembut) {
                    gudang.detergen -= butuhDetergen;
                    gudang.pelembut -= butuhPelembut;
                    printf("Berhasil! Stok dikurangi untuk %.1f kg cucian.\n", beratCucian);
                } else {
                    printf("Gagal! Stok tidak cukup untuk mencuci berat tersebut.\n");
                }
                break;

            case 3:
                printf("Input jumlah Detergen baru (ml): ");
                float tambahD;
                scanf("%f", &tambahD);
                gudang.detergen += tambahD;
                printf("Stok berhasil diperbarui!\n");
                break;

            default:
                printf("Menu tidak tersedia.\n");
        }
    }
    return 0;
}
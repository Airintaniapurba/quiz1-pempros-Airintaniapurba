#include <stdio.h>
#include <string.h>

#define MAX 100

// struktur menu
typedef struct {
    char kode[5];
    char nama[30];
    int harga;
} Menu;

int main() {

    // daftar menu sesuai gambar
    Menu menu[] = {
        {"NGS","Nasi Goreng Spesial",15000},
        {"AP","Ayam Penyet",20000},
        {"SA","Sate Ayam (10 Tusuk)",25000},
        {"BU","Bakso Urat",18000},
        {"MAP","Mie Ayam Pangsit",15000},
        {"GG","Gado-Gado",15000},
        {"SAM","Soto Ayam",17000},
        {"RD","Rendang Daging",25000},
        {"IB","Ikan Bakar",35000},
        {"NUK","Nasi Uduk Komplit",20000}
    };

    int jumlahMenu = 10;

    char inputKode[10];
    int porsiButet;
    int porsiUcok;
    int i, ketemu;

    char namaPesanan[MAX][30];
    int porsiTotal[MAX];
    int hargaSatuan[MAX];
    int totalItem[MAX];

    int index = 0;
    int grandTotal = 0;

    printf("=== INPUT PESANAN (ketik END untuk selesai) ===\n");

    while(1){
        printf("Kode Menu : ");
        scanf("%s", inputKode);

        if(strcmp(inputKode,"END")==0)
            break;

        ketemu = 0;

        for(i=0;i<jumlahMenu;i++){
            if(strcmp(inputKode, menu[i].kode)==0){

                printf("Porsi Butet : ");
                scanf("%d",&porsiButet);

                // perbandingan berat
                // Ucok 100kg, Butet 50kg → 2 : 1
                porsiUcok = 2 * porsiButet;

                strcpy(namaPesanan[index], menu[i].nama);

                porsiTotal[index] = porsiButet + porsiUcok;
                hargaSatuan[index] = menu[i].harga;
                totalItem[index] =
                    porsiTotal[index] * hargaSatuan[index];

                grandTotal += totalItem[index];

                index++;
                ketemu = 1;
                break;
            }
        }

        if(!ketemu)
            printf("Kode tidak ditemukan!\n");
    }

    // ================= OUTPUT STRUK =================
    printf("\n====================================================\n");
    printf("%-25s %-7s %-10s %-10s\n",
           "Menu","Porsi","Harga","Total");
    printf("====================================================\n");

    for(i=0;i<index;i++){
        printf("%-25s %-7d %-10d %-10d\n",
               namaPesanan[i],
               porsiTotal[i],
               hargaSatuan[i],
               totalItem[i]);
    }

    printf("====================================================\n");

    // ================= HITUNG KUPON =================
    int diskonPersen = 0;

    if(grandTotal >= 500000)
        diskonPersen = 25;
    else if(grandTotal >= 400000)
        diskonPersen = 20;
    else if(grandTotal >= 300000)
        diskonPersen = 15;
    else if(grandTotal >= 200000)
        diskonPersen = 10;
    else if(grandTotal >= 100000)
        diskonPersen = 5;

    int diskon = grandTotal * diskonPersen / 100;
    int totalBayar = grandTotal - diskon;

    printf("Total                : %d\n", grandTotal);
    printf("Diskon (%d%%)         : %d\n", diskonPersen, diskon);
    printf("Total Pembayaran     : %d\n", totalBayar);
    printf("====================================================\n");

    return 0;
}
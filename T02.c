#include <stdio.h>

int main() {
    int N, i, kodeKelompok;
    int totalNilai = 0;

    // 1. Input Jumlah Total Data (N)
    printf("Masukkan jumlah total data (N): ");
    scanf("%d", &N);

    // Deklarasi array sesuai jumlah N
    int nilai[N];

    // 2. Input Deret Nilai (n1, n2, ..., nN)
    printf("Masukkan %d deret nilai:\n", N);
    for (i = 0; i < N; i++) {
        printf("Nilai data ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
    }

    // 3. Input Kode Kelompok Siswa
    // Asumsi: Kode 1 = Posisi Ganjil (Indeks 0, 2, ...), Kode 2 = Posisi Genap (Indeks 1, 3, ...)
    printf("\nMasukkan Kode Kelompok (1 untuk Ganjil, 2 untuk Genap): ");
    scanf("%d", &kodeKelompok);

    // Proses Penjumlahan Berdasarkan Kelompok
    for (i = 0; i < N; i++) {
        if (kodeKelompok == 1) {
            // Mengecek posisi ganjil (indeks 0, 2, 4...) menggunakan modulo
            if (i % 2 == 0) {
                totalNilai += nilai[i];
            }
        } else if (kodeKelompok == 2) {
            // Mengecek posisi genap (indeks 1, 3, 5...)
            if (i % 2 != 0) {
                totalNilai += nilai[i];
            }
        }
    }

    // Output Hasil Akhir
    printf("-------------------------------\n");
    printf("Total nilai kelompok %d adalah: %d\n", kodeKelompok, totalNilai);

    return 0;
}
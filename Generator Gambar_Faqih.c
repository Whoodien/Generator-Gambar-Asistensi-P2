#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Untuk fungsi sleep
#include <time.h>

#define MIN_LENGTH 10
#define MIN_WIDTH 5
#define MAX_LENGTH 100
#define MAX_WIDTH 75

void generateStaticImage(int length, int width) {
    srand(time(NULL));
    // Menampilkan gambar statis
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            int random_choice = rand() % 2;
            if (random_choice == 0){
                printf("*");
            } else{
            printf(" ");}
        }
        printf("\n");
    }
}

void generateMovingImage(int length, int width) {
    // Menampilkan gambar yang bergerak
    for (int offset = 0; offset < length; offset++) {
        // Menampilkan gambar dengan offset
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                if (j < offset || j >= offset + length) {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
            printf("\n");
        }
        usleep(100000); // Delay 100 ms
    }
}

int main() {
    int length, width;
    char choice;

    while (1) {
        printf("Masukkan panjang gambar (10-100): ");
        scanf("%d", &length);
        printf("Masukkan lebar gambar (5-75): ");
        scanf("%d", &width);

        // Validasi input
        if (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Panjang harus antara %d dan %d.\n", MIN_LENGTH, MAX_LENGTH);
            continue;
        }
        if (width < MIN_WIDTH || width > MAX_WIDTH) {
            printf("Lebar harus antara %d dan %d.\n", MIN_WIDTH, MAX_WIDTH);
            continue;
        }

        // Memilih mode tampilan
        printf("Pilih mode tampilan (s untuk statis, m untuk bergerak): ");
        scanf(" %c", &choice); // Spasi sebelum %c untuk mengabaikan newline

        if (choice == 's') {
            generateStaticImage(length, width);
        } else if (choice == 'm') {
            generateMovingImage(length, width);
        } else {
            printf("Pilihan tidak valid. Silakan pilih 's' atau 'm'.\n");
        }
    }

    return 0;
}

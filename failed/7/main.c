#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


// Bu main, komut satırından bir dosya adı alarak çalışır.
// Kullanım: ./a.out test_dosyasi.txt
// Eğer dosya adı verilmezse, standart girdiden (klavyeden) okur.

int main()
{
    int     fd;
    char    *line;
    int     line_count;

    // --- Dosya Tanımlayıcısını (fd) Belirleme --//
        // Komut satırından bir dosya adı verildi, onu açalım.
        fd = open("test.txt", O_RDONLY);
        if (fd == -1)
        {
            perror("Dosya açma hatası");
            return (1);
        }
        printf("--- '%s' dosyasından okunuyor ---\n", "test.txt");
    // --- get_next_line'ı Döngüde Çağırma ---
    line_count = 1;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            printf("\n--- Okuma bitti (get_next_line NULL döndürdü) ---\n");
            break; // Döngüden çık
        }

        // Okunan satırı ve satır numarasını yazdır
        printf("Satir %d: %s", line_count, line);
        
        // GNL'den dönen ve malloc ile ayrılmış olan satırı serbest bırak
        free(line);
        line_count++;
    }

    // Eğer bir dosya açtıysak, kapatmayı unutmayalım.
    if (fd > 0)
    {
        close(fd);
    }
    return (0);
}


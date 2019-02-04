#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define D 5
#define namelength 4
#define codelength 4
void main()
{
    char name[D][namelength] = { "milk", "eggs", "corn", "fish", "meat" };
    int cena[D] = { 70, 50, 100, 200, 300 };
    int skidka[D] = { 50, 66, 90, 80, 60 };
    char code[D][codelength] = { "0001", "0002", "0003", "0004", "0005" };
    char scode[codelength];
    int kolvo[D] = { 0 };
    int summa = 0, fullst = 0, mode, i, j, check, fullskidka;
    setlocale(LC_ALL, "Russian");
    printf("1 - сканирование товара\n");
    printf("2 - вывести описание отсканированного товара\n");
    printf("3 - сформировать чек на покупку\n");
    printf("4 - рассчитать итоговую стоимость покупки\n");
    do
    {
        do
        {
            printf("Введите режим работы программы\n");
            scanf("%d", &mode);
        } while (mode > 4 || mode < 1);
        switch (mode)
        {
            case 1:
            {
                printf("Введите штрих-код для сканирования\n");
                scanf("%s", &scode);
                i = 0;
                check = 0;
                while ((check < 4) && (i < D))
                {
                    j = check = 0;
                    while (j < codelength)
                    {
                        if (scode[j] == code[i][j])
                            check++;
                        j++;
                    }
                    i++;
                }
                if (check == 4) kolvo[i - 1]++;
                else printf("Товара с данным штрихкодом не существует");
                break;
            }
            case 2:
            {
                    printf("Введите штрих-код отсканированного товара\n");
                    scanf("%s", &scode);
                    i = 0;
                    check = 0;
                    while ((check < 4) && (i < D))
                    {
                        j = check = 0;
                        while (j < codelength)
                        {
                            if (scode[j] == code[i][j])
                                check++;
                            j++;
                        }
                        i++;
                    }
                    if (check == 4)
                        if (kolvo[i - 1] == 0)
                            printf("Данный товар не отсканирован\n");
                        else
                        {
                            printf("%s    ", scode);
                            for (j = 0; j < namelength; j++)
                                printf("%c", name[i -1][j]);
                            printf("    %d", cena[i - 1]);
                            printf("    %d\n", skidka[i - 1]);
                        }
                    else printf("Товара с данным штрихкодом не существует");
                    break;
            }
            case 3:
            {
                check = 0;
                for (i = 0; i < 5; i++)
                    if (kolvo[i] != 0)
                    {
                        fullst += cena[i] * kolvo[i];
                        summa += cena[i] * kolvo[i] * skidka[i] / 100;
                        for (j = 0; j < namelength; j++)
                            printf("%c", name[i][j]);
                        printf("    %d", cena[i]);
                        printf("    %d", kolvo[i]);
                        printf("    %d", cena[i] * kolvo[i]);
                        printf("    %d\n", cena[i] * kolvo[i] * skidka[i] / 100);
                        check++;
                    }
                if (!check) printf("Нет ни одного отсканированного товара\n");
                break;
            }
            case 4:
            {
                for (i = 0; i < D; i++)
                {
                }
                fullskidka = fullst - summa;
                printf("Общая стоимость - %d\n", fullst);
                printf("Общая скидка - %d\n", fullskidka);
                printf("К оплате - %d\n", summa);
                break;
            }
        }
    } while (mode != 4);
}

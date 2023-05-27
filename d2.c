#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>//підключення бібліотек
int main() {
    int array[10];
    int i, first_positive_index = -1, last_positive_index = -1;
    int min_abs_value = 0;
    int min_abs_index = 0;
    int sum_between_positives = 0;
    srand(time(NULL) ^ getpid()); // Ініціалізація генератора випадкових чисел
    // Заповнення масиву випадковими числами від -100 до 100
    for (i = 0; i < 10; i++) {
        array[i] = rand() % 201 - 100;
        printf("%d ", array[i]);
    }
    // Знаходження номера мінімального за модулем елемента
    for (i = 1; i < 10; i++) {
        if (abs(array[i]) < abs(array[min_abs_index])) {
            min_abs_index = i;
            min_abs_value = array[i];
        }
    }
    printf("\nМінімальний за модулем елемент: %d\n", min_abs_value);
    // Знаходження першого та останнього додатнього елемента
    for (i = 0; i < 10; i++) {
        if (array[i] > 0) {
            if (first_positive_index == -1) {
                first_positive_index = i;
            }
            last_positive_index = i;
        }
    }
    // Обчислення суми елементів між першим та останнім додатніми елементами
    if (first_positive_index != -1 && last_positive_index != -1) {
        for (i = first_positive_index + 1; i < last_positive_index; i++) {
            sum_between_positives += array[i];
        }
    }
    printf("Сума елементів між першим та останнім додатніми: %d\n", sum_between_positives);
  return 0;
}

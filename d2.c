#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>//підключення бібліотек
int generateRandomNumber(){
    return rand() % 201 - 100;
}
int findMinAbsValue(int array[], int size){
    int min_abs_value = array[0];
    int i;
    for (i = 1; i < size; i++) {
        if(abs(array[i]) < abs(min_abs_value)){
            min_abs_value = array[i];
        }
    }
    return min_abs_value;
}
void findPositiveIndices(int array[], int size, int* first_positive_index, int* last_positive_index){
    *first_positive_index = -1;
    *last_positive_index = -1;
    int i;
    for (i = 0; i < size; i++){
        if(array[i] > 0){
            if(*first_positive_index == -1){
                *first_positive_index = i;
            }
            *last_positive_index = i;
        }
    }
}
int calculatesumbetweenPosivies(int array[], int size, int first_positive_index, int last_positive_index){
    int sum_between_positives = 0;
    int i;
    for (i = first_positive_index + 1; i < last_positive_index; i++){
        sum_between_positives += array[i];
    }
    return sum_between_positives;
}
int main(){
    int array[10];
    int i, first_positive_index, last_positive_index;
    int min_abs_value, sum_between_positives;
    srand(time(NULL) ^ getpid());
    //заповнюємо масив випадковими числами
    for(i = 0; i < 10; i++){
        array[i] = generateRandomNumber();
        printf("%d ", array[i]);
    }
printf("\n");
//знаходимо мінамільний за модулем елемент
min_abs_value = findMinAbsValue(array, 10);
printf("мінімальний за модулем елемент: %d\n", min_abs_value);
//знаходимо перший і останній додатній елемент
findPositiveIndices(array, 10, &first_positive_index, &last_positive_index);\
//обчислюємо суму елементів між першим і останнім додатнім елементом
if(first_positive_index != -1 && last_positive_index != -1){
    sum_between_positives = calculatesumbetweenPosivies(array, 10, first_positive_index, last_positive_index);
    printf("Сума елементів між першим та останнім додатнім елементом: %d\n", sum_between_positives);
   }
   return 0;
}

#include <stdio.h>//підключення бібліотеки
int countEven(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;//функція для знаходження парних елементів масиву
}
int countZero(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            count++;
        }
    }
    return count;//функція для знаходження нульових елементів масиву 
}
int main() {
    int n;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);
    int arr[n];
    printf("Введіть елементи масиву:\n");//введення значень
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);//введення даних
    }
    int evenCount = countEven(arr, n);
    int zeroCount = countZero(arr, n);
    if (evenCount) { 
        printf("Кількість парних елементів: %d\n", evenCount);
    } else {
        printf("В масиві парні елементи відсутні.\n");
    }    
    if (zeroCount) {
        printf("Кількість нульових елементів: %d\n", zeroCount);
    } else {
        printf("В масиві нульові елементи відсутні.\n");//виведення результатів
    }
    return 0;//кінець програми
}
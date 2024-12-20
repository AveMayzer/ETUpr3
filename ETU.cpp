#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
const int N = 8;
const int halfN = N / 2;

int x = 0, y = 0;



// Установка позиции каретки
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, position);
}
void printNewLine(int n) {
    y += n;    
    x = 0;
    setCursorPosition(x, y);
}

void BubbleSort(int* arr, int* end) {
    for (int* i = arr; i < end; i++) {
        for (int* j = arr; j < end - (i - arr); j++) {
            if (*j > *(j + 1)) {
                swap(*j, *(j + 1));
            }
        }
    }
}

void CombSort(int* matrix, int* end) {
    float k = 1.247;
    int s = end - matrix;
    bool swapped = true;

    while (s > 1 || swapped) {
        s = (s > 1) ? int(s / k) : 1;
        swapped = false;

        for (int* i = matrix; i + s < end + 1; i++) {
            if (*i > *(i + s)) {
                swap(*i, *(i + s));
                swapped = true;
            }
        }
    }
}

void InsertionSort(int* matrix, int* end) {
    {
        for (int* i = matrix; i < end + 1; i++)
        {
            int* j = i - 1;
            while (*j >= 0 && *j > *(j + 1))
            {
                swap(*j, *(j + 1));
                j--;
            }
        }
    }
}

void QuickSort(int* matrix, int* begin, int* end) {
    int* f = begin;
    int* l = end;
    int mid = *(begin + (end - begin) / 2);

    while (f <= l) {
        while (*f < mid) f++;
        while (*l > mid) l--;

        if (f <= l) {
            swap(*f, *l);
            f++;
            l--;
        }
    }
    if (begin < l) QuickSort(matrix, begin, l);
    if (f < end) QuickSort(matrix, f, end);
}



void printMatrix(int* matrix, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int* num = matrix + i * n + j;
            setCursorPosition(x + j * 5, y + i);
            cout << *num;
        }
    }
}

// Заполнение матрицы спиралькой
void fillMatrixSpiral(int* matrix, int n) {
    int num = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            *(matrix + top * n + i) = rand() % 100 + 1;
            setCursorPosition(x + i * 5, y + top);
            cout << *(matrix + top * n + i);
            Sleep(50);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            *(matrix + i * n + right) = rand() % 100 + 1;
            setCursorPosition(x + right * 5, y + i);
            cout << *(matrix + i * n + right);
            Sleep(50);
        }
        right--;

        for (int i = right; i >= left; i--) {
            *(matrix + bottom * n + i) = rand() % 100 + 1;
            setCursorPosition(x + i * 5, y + bottom);
            cout << *(matrix + bottom * n + i);
            Sleep(50);
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            *(matrix + i * n + left) = rand() % 100 + 1;
            setCursorPosition(x + left * 5, y + i);
            cout << *(matrix + i * n + left);
            Sleep(50);
        }
        left++;
    }
    printNewLine(n);
}

// Заполнение матрицы змейкой
void fillMatrixSnake(int* matrix, int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int value = 1;
    while (top <= bottom && left <= right) {

        for (int i = bottom; i >= top; i--) {
            int* num = matrix + i * n + left;
            *num = rand() % 100 + 1;
            setCursorPosition(x + left * 5, y + i);
            cout << *num;
            Sleep(50);
        }
        left++;

        for (int i = top; i <= bottom; i++) {
            int* num = matrix + i * n + left;
            *num = rand() % 100 + 1;
            setCursorPosition(x + left * 5, y + i);
            cout << *num;
            Sleep(50);
        }
        left++;
    }
    printNewLine(n);
}
void swapBlocks(int* matrix, int n, int firstRowStart, int firstColStart,
    int secondRowStart, int secondColStart, int blockN) {
    for (int i = 0; i < blockN; i++) {
        for (int j = 0; j < blockN; j++) {
            int* elem1 = matrix + (firstRowStart + i) * n + (firstColStart + j);
            int* elem2 = matrix + (secondRowStart + i) * n + (secondColStart + j);
            swap(*elem1, *elem2);
        }
    }
}


/* swapBlocks(ptr, N, 0, 0, 0, halfN, halfN);  A и B
swapBlocks(ptr, N, halfN, 0, halfN, halfN, halfN);  C и D
swapBlocks(ptr, N, 0, 0, halfN, 0, halfN);  A и C
swapBlocks(ptr, N, 0, halfN, halfN, halfN, halfN);  B и D
swapBlocks(ptr, N, 0, 0, halfN, halfN, halfN);  A и D
swapBlocks(ptr, N, halfN, 0, 0, halfN, halfN);  B и C   */


void sumToElementsMatrix(int* matrix, int N) {
    int needNum;
    cout << "Введите число, которое нужно прибавить к каждому элементу";
    printNewLine(1);
    cin >> needNum;
    printNewLine(1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int* num = matrix + i * N + j;
            *num += needNum;
        }
    }
}

void delToElementsMatrix(int* matrix, int N) {
    int needNum;
    cout << "Введите число, которое нужно вычесть к каждому элементу";
    printNewLine(1);
    cin >> needNum;
    printNewLine(1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int* num = matrix + i * N + j;
            *num -= needNum;
        }
    }
}

void multToElementsMatrix(int* matrix, int N) {
    int needNum;
    cout << "Введите число, которое нужно умножить к каждому элементу";
    printNewLine(1);
    cin >> needNum;
    printNewLine(1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int* num = matrix + i * N + j;
            *num *= needNum;
        }
    }
}
void divToElementsMatrix(int* matrix, int N) {
    int needNum;
    cout << "Введите число, которое нужно поделить к каждому элементу";
    printNewLine(1);
    cin >> needNum;
    printNewLine(1);
    if (needNum != 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int* num = matrix + i * N + j;
                *num /= needNum;
            }
        }
    }
}

void idz(int* matrix) {

}

int main() {
    setlocale(0, "");
    srand((unsigned)time(0));
    int choice;
    bool started = true;
    int matrix[N][N];
    int* ptr = &matrix[0][0];
    int* end = &matrix[0][0] + N * N - 1; 
    cout << "Предстоит выбрать как создать матрицу: \n 1 | Змейкой \n 2 | Спиралькой";
    printNewLine(3);

    cin >> choice;
    printNewLine(1);
    switch (choice) {
        case 1: fillMatrixSnake(ptr, N); break;
        case 2: fillMatrixSpiral(ptr, N); break;
    }
    printNewLine(2);

    cout << "Какую сортировку предпочитаете?\n 1 | Bubble\n 2 | Insertion\n 3 | Comb\n 4 | Quick\n 5 | Не сортировать.";
    printNewLine(6);
    cin >> choice;
    switch (choice) {
        case 1: BubbleSort(ptr, end); break;
        case 2: InsertionSort(ptr, end); break;
        case 3: CombSort(ptr, end); break;
        case 4: QuickSort(ptr, ptr, end); break;
        case 5: break;
    }
    printMatrix(ptr, N);
    printNewLine(N + 1);



    printNewLine(1);
    while (started) {
        cout << "Предстоит выбрать изменение блоков: \n 1 | По вертикали\n 2 | По горизонтале \n 3 | По диагонали \n 4 | По часово стрелке\n 5 | Выйти.";
        printNewLine(7);
        cin >> choice;
        switch (choice) {
            case 1: swapBlocks(ptr, N, 0, 0, halfN, 0, halfN);
                swapBlocks(ptr, N, 0, halfN, halfN, halfN, halfN);  break;
            case 2: swapBlocks(ptr, N, 0, 0, 0, halfN, halfN);
                swapBlocks(ptr, N, halfN, 0, halfN, halfN, halfN); break;
            case 3: swapBlocks(ptr, N, 0, 0, halfN, halfN, halfN);
                swapBlocks(ptr, N, halfN, 0, 0, halfN, halfN); break;
            case 4: swapBlocks(ptr, N, 0, 0, 0, halfN, halfN); swapBlocks(ptr, N, 0, 0, halfN, halfN, halfN);
                swapBlocks(ptr, N, 0, 0, halfN, 0, halfN); break;
            case 5: started = false; break;

        }
        printMatrix(ptr, N);
        printNewLine(N + 1);
    }
    printNewLine(1);
   
    started = true;
    

    while (started) {
        cout << "Теперь предстоит выбрать операцию над матрицами\n 1 | Сложить каждый элемент на число\n 2 | Вычесть каждый элемент на число\n 3 | Умножить каждый элемент на число\n 4 | Поделить каждый элемент на число\n 5 | Выйти.";
        printNewLine(6);
        cin >> choice;
        printNewLine(1);
        switch (choice) {
            case 1: sumToElementsMatrix(ptr, N); break;
            case 2: delToElementsMatrix(ptr, N); break;
            case 3: multToElementsMatrix(ptr, N); break;
            case 4: divToElementsMatrix(ptr, N); break;
            case 5: started = false; break;
        }
        printMatrix(ptr, N);
        printNewLine(N + 1);
    }
    return 0;
}
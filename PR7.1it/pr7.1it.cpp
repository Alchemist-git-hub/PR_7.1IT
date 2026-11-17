#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипи функцій
void Create(int** C, const int rowCount, const int colCount,
    const int Low, const int High);

void Print(int** C, const int rowCount, const int colCount);

void Sort(int** C, const int rowCount, const int colCount);

void Change(int** C, const int row1, const int row2,
    const int colCount);

void Sum(int** C, const int rowCount, const int colCount,
    int& S, int& k);


int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    const int Low = -21;
    const int High = 18;
    const int rowCount = 8;
    const int colCount = 7;

   
    int** C = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        C[i] = new int[colCount];

    Create(C, rowCount, colCount, Low, High);

    cout << "Original matrix C:";
    Print(C, rowCount, colCount);

    Sort(C, rowCount, colCount);

    cout << "Sorted matrix C:";
    Print(C, rowCount, colCount);

    int S = 0;
    int k = 0;

    Sum(C, rowCount, colCount, S, k);

    cout << "Sum S = " << S << endl;
    cout << "Count k = " << k << endl;

    cout << "Modified matrix C:";
    Print(C, rowCount, colCount);

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] C[i];

    delete[] C;

    return 0;
}
void Create(int** C, const int rowCount, const int colCount,
    const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            C[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** C, const int rowCount, const int colCount)
{
    cout << endl;

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(5) << C[i][j];

        cout << endl;
    }

    cout << endl;
}
// Сортування рядків
void Sort(int** C, const int rowCount, const int colCount)
{
    for (int i0 = 0; i0 < rowCount - 1; i0++)
    {
        for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
        {
            if ((C[i1][0] < C[i1 + 1][0]) ||

                (C[i1][0] == C[i1 + 1][0] &&
                    C[i1][1] < C[i1 + 1][1]) ||

                (C[i1][0] == C[i1 + 1][0] &&
                    C[i1][1] == C[i1 + 1][1] &&
                    C[i1][3] > C[i1 + 1][3]))
            {
                Change(C, i1, i1 + 1, colCount);
            }
        }
    }
}
// Обмін двох рядків
void Change(int** C, const int row1, const int row2,
    const int colCount)
{
    int tmp;

    for (int j = 0; j < colCount; j++)
    {
        tmp = C[row1][j];
        C[row1][j] = C[row2][j];
        C[row2][j] = tmp;
    }
}
void Sum(int** C, const int rowCount, const int colCount,
    int& S, int& k)
{
    S = 0;
    k = 0;

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (C[i][j] % 2 == 0 || C[i][j] <= 0)
            {
                S += C[i][j];
                k++;

                C[i][j] = 0;
            }
        }
    }
}
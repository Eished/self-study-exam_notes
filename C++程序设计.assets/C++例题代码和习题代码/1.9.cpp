#include <iostream>
using namespace std;
int *A = new int[5];
int main()
{
  for (int i = 0; i < 5; i++)
  {
    A[i] = i + 1;
    cout << A[i] << endl;
  }
  // delete[] A;
  delete A;
  for (int i = 0; i < 5; i++)
  {
    cout << A[i] << endl;
  }
  return 0;
}
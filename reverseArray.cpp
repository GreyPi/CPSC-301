#include <iostream>
using namespace std;

void reverseArray(int num[], int length);

int main()
{
int SIZE = 3;
int number[SIZE] = {1,2,3,4};

reverseArray(number, SIZE);


return 0;
}

void reverseArray(int num[], int length)
{
  for (int i = length; i >= 0; i--)
  {
    cout << num[i] << " ";
  }

}

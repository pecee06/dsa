#include "../Utils/printArray.cpp"
#include <ctime>
#include <cstdlib>

int getRandomInteger(int min, int max)
{
  srand(time(0));
  int random_num = rand();
  int range = max - min + 1;
  return min + (random_num % range);
}

int partition(int arr[], int from, int to)
{
  swap(arr[from], arr[getRandomInteger(from, to)]);
  int slow, fast, pivot = arr[from]; // random pivot
  slow = fast = to;
  while (fast > from){
    if (arr[fast] > pivot){
      swap(arr[slow], arr[fast]);
      slow--;
    }
    fast--;
  }
  swap(arr[from], arr[slow]);
  return slow;
}

void quickSort(int arr[], int from, int to)
{
  if (from >= to)
    return;
  int pi = partition(arr, from, to);
  quickSort(arr, from, pi - 1);
  quickSort(arr, pi + 1, to);
}

int main()
{
  int arr[] = {7,3,3,7,6,1,1,1,6,9,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  quickSort(arr, 0, n-1);
  printArray(arr, n);

  return 0;
}

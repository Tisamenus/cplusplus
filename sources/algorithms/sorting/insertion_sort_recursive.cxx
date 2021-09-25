#include <iostream>

using namespace std;

template <class T> void printArray(int size, T* array) {
  for(int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void swap(int& val1, int& val2) {
  val1 += val2;
  val2 = val1 - val2;
  val1 = val1 - val2;
}

void sortArray(int index, int bound, int* numbers) {
  if(index < 0) { swap(numbers[0], numbers[bound]); return; }
  if(numbers[index] > numbers[bound]) {
    sortArray(index-1, bound, numbers);
  }
  if(index+1 == bound) { return; }
  swap(numbers[index+1], numbers[bound]);
}

void sortArray(int size, int* numbers) {
  if(size < 1) { return; }
  sortArray(size-1, numbers);
  sortArray(size-1, size, numbers);
}

int main() {
  int size;
  cin >> size;
  int* inputs = new int[size];

  for(int i = 0; i < size; i++) {
    cin >> inputs[i];
  }

  sortArray(size-1, inputs);

  printArray(size, inputs);
}
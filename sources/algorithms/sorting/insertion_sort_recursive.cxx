#include <iostream>

using namespace std;

template <class T> void print_array(int size, T* array) {
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

void sort_array(int index, int bound, int* numbers) {
  if(index < 0) { swap(numbers[0], numbers[bound]); return; }
  if(numbers[index] > numbers[bound]) {
    sort_array(index-1, bound, numbers);
  }
  if(index+1 == bound) { return; }
  swap(numbers[index+1], numbers[bound]);
}

void sort_array(int size, int* numbers) {
  if(size < 1) { return; }
  sort_array(size-1, numbers);
  sort_array(size-1, size, numbers);
}

int main() {
  int size;
  cin >> size;
  int* inputs = new int[size];

  for(int i = 0; i < size; i++) {
    cin >> inputs[i];
  }

  sort_array(size-1, inputs);

  print_array(size, inputs);
}
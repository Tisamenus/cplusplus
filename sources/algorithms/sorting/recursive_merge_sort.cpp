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

void merge_sort(int q, int r, int* numbers) {
  if(q == r) { return; }
  merge_sort(q, r/2, numbers);
  merge_sort(r/2 + 1, r, numbers);
}

void merge_sort(int q, int p, int r, int* numbers) {
  int offset = p + q;
  int r_index = r/2 + 1 + offset;
  if(r_index > r) { return; }

  if(numbers[r_index] < numbers[offset]) {
    swap(numbers[r_index], numbers[offset]);
  }
  if(offset + 1 == r_index) { return ; }
  swap(numbers[r_index], numbers[offset+1]);

  merge_sort(q, p+1, r, numbers);
}

int main() {
  int size;
  cin >> size;
  int* inputs = new int[size];

  for(int i = 0; i < size; i++) {
    cin >> inputs[i];
  }

  merge_sort(0, size-1, inputs);

  print_array(size, inputs);
}
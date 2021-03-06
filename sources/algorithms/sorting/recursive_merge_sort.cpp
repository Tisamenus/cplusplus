#include <iostream>

using namespace std;

template <class T>
void print_array(int size, T* array) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void swap(int& val1, int& val2) {
  val1 += val2;
  val2 = val1 - val2;
  val1 = val1 - val2;
}

void merge_sort(int q, int p, int ri, int r, int* numbers) {
  int offset = q + p;
  if (ri > r) {
    return;
  }

  if (numbers[offset] > numbers[ri]) {
    swap(numbers[offset], numbers[ri]);
  }
  if (offset + 1 == ri) {
    ri++;
    p = 0;
  }

  merge_sort(q, p + 1, ri, r, numbers);
}

void merge_sort(int q, int r, int* numbers) {
  if (q >= r) {
    return;
  }
  merge_sort(q, q + (r - q) / 2, numbers);
  merge_sort(q + (r - q) / 2 + 1, r, numbers);
  merge_sort(q, 0, q + (r - q) / 2 + 1, r, numbers);
}

int main() {
  int size;
  cin >> size;
  int* inputs = new int[size];

  for (int i = 0; i < size; i++) {
    cin >> inputs[i];
  }

  merge_sort(0, size - 1, inputs);

  print_array(size, inputs);
}
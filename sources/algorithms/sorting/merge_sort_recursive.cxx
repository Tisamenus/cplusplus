#include <iostream>
#include <string>

using namespace std;

template <class T>
void print_array(int size, T* array) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

template <class T>
T* copy_array(int size, T* to_copy) {
  T* copy = new T[size];
  for(int i = 0; i < size; i++) {
    copy[i] = to_copy[i];
  }
  return copy;
}

string findPos(int lox) {
  string line = "----------------------------------------";
  line[lox*2] = 'v';
  return line;
}

void swap(int& val1, int& val2) {
  val1 += val2;
  val2 = val1 - val2;
  val1 = val1 - val2;
}

void merge_sort(int q, int p, int r, int* numbers, int* help_array) {
  int offset = q + p;
  int ri = offset + (r-q)/2 + 1;

  cout << findPos(offset) << endl;
  print_array(r+1, numbers);
  print_array(r+1, help_array);
  cout << findPos(ri) << endl; 
  print_array(r+1, help_array);
  cout << "------------------------------" << endl;

  if (ri > r) {
    if((r-q + 1)%2) {
      int lpos = (r-q)/2 + q;
      if(numbers[q+ 2*p - 1] > help_array[lpos]) {
	swap(numbers[q+ 2*p - 1], help_array[lpos]);
      }
      numbers[q + 2*p] = help_array[lpos];
    }
    delete help_array;
    return;
  }

  if (help_array[offset] > help_array[ri]) {
    numbers[offset+p] = help_array[ri];
    numbers[offset+1+p] = help_array[offset];
  } else {
    numbers[offset+p] = help_array[offset];
    numbers[offset+1+p] = help_array[ri];
  }

  merge_sort(q, p + 1, r, numbers, help_array);
}

void merge_sort(int q, int r, int* numbers) {
  if (q >= r) {
    return;
  }
  merge_sort(q, q + (r - q) / 2, numbers);
  merge_sort(q + (r - q) / 2 + 1, r, numbers);
  merge_sort(q, 0, r, numbers, copy_array(r+1, numbers));
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
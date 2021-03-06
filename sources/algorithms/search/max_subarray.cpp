#include <iostream>
using namespace std;

struct subarray {
    int low;
    int high;
    long sum;

    subarray(int _low, int _high, int _sum) {
        low = _low;
        high = _high;
        sum = _sum;
    }
    subarray(const subarray& sub) {
        low = sub.low;
        high = sub.high;
        sum = sub.sum;
    }
    subarray(const subarray& lower,
             const subarray& higher) {
        low = lower.low;
        high = higher.low;
        sum = lower.sum + higher.sum;
    }
};

subarray find_crossing_half(int low, int high, int sum, int index, int* array) {
    sum += array[index];
    bool direction = (low > high);
    return ((array[index + (direction ? -1 : 1)] < array[index]) != direction) ? find_crossing_half(low, high, sum,
            index + (direction ? -1 : 1), array) : subarray(index, low, sum);
}

subarray find_subarray(int low, int high, int* array) {
    if(low == high) {
        return subarray(low, high, array[low]);
    } else {
        int mid = (high + low) / 2;
        subarray lower = find_subarray(low, mid, array);
        subarray higher = find_subarray(mid + 1, high, array);
        subarray middle =  subarray(find_crossing_half(mid, low, 0, mid, array), find_crossing_half(mid + 1, high, 0, mid + 1, array));
        if(lower.sum >= higher.sum) {
            if(lower.sum >= middle.sum) {
                return subarray(lower);
            }
        } else if(higher.sum >= middle.sum) {
            return subarray(higher);
        }
        return subarray(middle);
    }
}

int main() {
    int size;
    cin >> size;
    int* inputs = new int[size];
    for(int i = 0; i < size; i++) {
        cin >> inputs[i];
    }
    subarray result = find_subarray(0, size - 1, inputs);
    cout << result.low << " - " << result.high << " ==> " << result.sum << endl;
}
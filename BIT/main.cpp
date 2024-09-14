#include <bits/stdc++.h>
using namespace std;


class BIT {
private:
    int size;
    vector<int> arr;
    vector<int> bit;

public:
    BIT (int n) : size(n), arr(n), bit(n) {

    }

    /** Sets element at index to val */
    void set(int index, int val) {
        add(index, val - arr[index]);
        arr[index] = val;
    }

    /** Adds val to element at index */
    void add(int index, int val) {
        for (; index < size; index |= (index + 1)) {
            bit[index] += val;
        }
    } 

    /** @return sum of elements in arr[0....index] */
    int pref_sum(int index) {
        int sum = 0;
        for (; index >= 0; index = (index & (index + 1)) - 1) {
            sum += bit[index];
        }
        return sum;
    }

    /** @return sum of element in arr[left.....right] */
    int range_sum(int left, int right) {
        return left == 0 ? pref_sum(right) : pref_sum(right) - pref_sum(left - 1);
    }

};

int main() {
    return 0;
}
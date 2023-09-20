#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* heights = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int left = 0, right = n - 1;
    int max_left = 0, max_right = 0;
    int water = 0;

    while (left <= right) {
        if (heights[left] <= heights[right]) {
            water += max(max_left - heights[left], 0);
            max_left = max(max_left, heights[left]);
            ++left;
        } else {
            water += max(max_right - heights[right], 0);
            max_right = max(max_right, heights[right]);
            --right;
        }
    }

    cout << water << endl;

    delete[] heights;

    return 0;
}

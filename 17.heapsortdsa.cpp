#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildMaxHeap(vector<int>& arr) {
    for (int i = arr.size()/2 - 1; i >= 0; i--)
        maxHeapify(arr, arr.size(), i);
}

void buildMinHeap(vector<int>& arr) {
    for (int i = arr.size()/2 - 1; i >= 0; i--)
        minHeapify(arr, arr.size(), i);
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> marks(n);
    cout << "Enter marks of students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i+1 << ": ";
        cin >> marks[i];
    }

    vector<int> maxHeap = marks, minHeap = marks;
    buildMaxHeap(maxHeap);
    buildMinHeap(minHeap);

    cout << "\nMaximum marks: " << maxHeap[0];
    cout << "\nMinimum marks: " << minHeap[0];

    return 0;
}

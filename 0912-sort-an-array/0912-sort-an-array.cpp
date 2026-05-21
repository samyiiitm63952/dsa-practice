class Solution {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int li = 2 * i + 1;
        int ri = 2 * i + 2;
        if (li < n && arr[li] > arr[largest]) {
            largest = li;
        }
        if (ri < n && arr[ri] > arr[largest]) {
            largest = ri;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    vector<int> buildHeap(vector<int> &arr, int n) {
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        return arr;
    }
    vector<int> sortArray(vector<int>& nums) {
       nums= buildHeap(nums, nums.size());
        int size = nums.size();
        while (size) {
            swap(nums[0], nums[size-1]);
            size--;
            heapify(nums, size, 0);
        }
        return nums;
    }
};
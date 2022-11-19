class Solution {
public:
    
    void heapify(vector<int> &heap, int size, int index)
    {
        int lchild = index * 2 + 1; 
        int rchild = index * 2 + 2;
        int largestIndex = index;
        if(lchild <= size - 1 && heap[lchild] > heap[largestIndex])
            largestIndex = lchild;

        if(rchild <= size - 1 &&  heap[rchild] > heap[largestIndex])
            largestIndex = rchild;

        if(largestIndex != index)
        {
            swap(heap[index] , heap[largestIndex]);
            heapify(heap, size, largestIndex);
        }
    }

    void convertToMaxHeap(vector<int> &heap, int size)
    {
        for(int i = (size - 1)/2; i>=0 ; i--)
        {
            heapify(heap, size, i);
        }
    }


    void heapSort(vector<int> &nums, int n)
    {
        convertToMaxHeap(nums, n);

        for(int i = n-1; i>=0; i--)
        {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
    
    void quickSort(vector<int> &nums, int low, int high)
    {
        if(low>=high)
            return;
        // find the pivot and place it at the right spot
        // and then repeat the process for the left array and 
        // the right array
        int len = high - low + 1;
        srand(time(0));
        int pivot = low + rand() % len;
        swap(nums[pivot], nums[high]);
        int k = low;
        for(int i = low; i <= high-1; i++)
        {
            if(nums[i] < nums[high])
                swap(nums[k++], nums[i]);
                
        }
        swap(nums[k], nums[high]);
        quickSort(nums, low, k - 1);
        quickSort(nums, k + 1, high);
    }
    
    vector<int> merge(vector<int> &nums, int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
        vector<int> temp;
        while(i<=mid && j<=high)
        {
            temp.push_back(nums[i]<nums[j]?nums[i++]:nums[j++]);
        }
        while(i<=mid)
            temp.push_back(nums[i++]);
        while(j<=high)
            temp.push_back(nums[j++]);
        return temp;
    }
    
    void mergeSort(vector<int> &nums, int low, int high)
    {
        if(low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        vector<int> temp = merge(nums, low, mid, high);
        for(int i = low; i<= high; i++)
        {
            nums[i] = temp[i - low];
        }
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        heapSort(nums, n);
        return nums;
        
    }
};
class Solution {
public:
    /*
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    int parttion(vector<int> &v, int low, int high)
    {
        int pivotkey = v[low];
        while(low<high)
        {
            while(low<high && pivotkey<=v[high])
                high--;
            v[low] = v[high];
            while(low<high && pivotkey>=v[low])
                low++;
            v[high] = v[low];
        }
        v[low] = pivotkey;
        return low;
    }

    void quickSort(vector<int> &v, int low, int high)
    {
        while(low<high)
        {
            int pivot = parttion(v, low, high);
            quickSort(v, low, pivot);
            low = pivot + 1;
        }
    }

    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        quickSort(colors, 0, colors.size()-1);
    }
};

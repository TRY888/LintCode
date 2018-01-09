class Solution {
public:
    /*
     * @param A: an integer array
     * @return:
     */

    void mergeSort(vector<int> &A, int p, int r)
    {
        if(p<r)
        {
            int q = (p + r)/2;
            mergeSort(A, p, q);
            mergeSort(A, q+1, r);
            merge(A, p, q, r);
        }
    }

    void merge(vector<int> &A, int p, int q, int r)
    {
        int n1 = q - p + 1;
        int n2 = r - q;
        int *B = new int[n1];
        int *C = new int[n2];
        for(int i=0; i<n1; i++)
            B[i] = A[p+i];
        for(int i=0; i<n2; i++)
            C[i] = A[q+i+1];
        int i,j,k;
        i = p;
        j = k = 0;
        while(i<=r)
        {
            if(B[j]<=C[k])
            {
                A[i++] = B[j++];
                if(j==n1)
                {
                    for(int h=k; h<n2; h++)
                        A[i++] = C[h];
                    break;
                }

            }
            else
            {
                A[i++] = C[k++];
                if(k==n2)
                {
                    for(int h=j; h<n1; h++)
                        A[i++] = B[h];
                    break;
                }
            }
        }
        delete []B;
        delete []C;
    }

    void sortIntegers2(vector<int>& A) {
        // write your code here
        mergeSort(A, 0, A.size()-1);
    }
};

class Solution {
public:
    /*
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long  mergeSort(vector<int> &A, int p, int r)
    {
        if(p>=r)
            return 0;
        int q = (p + r)/2;
        long long sum1 = mergeSort(A, p, q);
        long long sum2 = mergeSort(A, q+1, r);
        long long sum = merge(A, p, q, r);
        return sum1 + sum2 + sum;
    }

    long long merge(vector<int> &A, int p, int q, int r)
    {
        int n1 = q - p + 1;
        int n2 = r - q;
        int *B = new int[n1];
        int *C = new int[n2];
        for(int i=0; i<n1; i++)
            B[i] = A[p+i];
        for(int i=0; i<n2; i++)
            C[i] = A[q+i+1];
        int i, j, k;
        long long cnt;
        i = p;
        j = k = cnt = 0;
        while(i<=r)
        {
            if(B[j]<=C[k])
            {
                A[i++] = B[j++];
                if(j == n1)
                {
                    for(int h=k; h<n2; h++)
                        A[i++] = C[h];
                    break;
                }
            }
            else
            {
                cnt = cnt + (n1 - j);
                A[i++] = C[k++];
                if(k == n2)
                {
                    for(int h=j; h<n1; h++)
                        A[i++] = B[h];
                    break;
                }
            }
        }
        delete []B;
        delete []C;
        return cnt;
    }

    long long reversePairs(vector<int> &A) {
        // write your code here
        return mergeSort(A, 0, A.size()-1);
    }
};

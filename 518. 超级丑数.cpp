class Solution {
public:
    /*
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */

    long nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<long> res(n, 0);
        res[0] = 1;
        int size = primes.size();
        vector<int> index_primes(size, 0);
        int cnt = 1;
        while(cnt<n)
        {
            long long min = 0x80000000;//min = 0x7ffffffff + 1
            int index = -1;
            for(int i=0; i<size; i++)
            {
                long temp = primes[i]*res[index_primes[i]];
                if(temp<min)
                {
                    index = i; //记录下标
                    min = temp;//更新最小值
                }
            }
            if(index!=-1)
            {
                ++index_primes[index];
                if(min>res[cnt-1])
                {
                    res[cnt] = min;
                    ++cnt;
                }
            }

        }
        return res[n-1];
    }
};

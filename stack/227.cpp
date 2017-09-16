/*
 * title：容易-227.用栈模拟汉诺塔问题
 * desc:在经典的汉诺塔问题中，有 3 个塔和 N 个可用来堆砌成塔的不同大小的盘子。要求盘子必须按照从小到大的顺序从上往下堆 （如，任意一个盘子，其必须堆在比它大的盘子上面）。同时，你必须满足以下限制条件：
 *     (1) 每次只能移动一个盘子。
 *     (2) 每个盘子从堆的顶部被移动后，只能置放于下一个堆中。
 *     (3) 每个盘子只能放在比它大的盘子上面。
 *     请写一段程序，实现将第一个堆的盘子移动到最后一个堆中。
 * e.g.:
 */

class Tower {
private:
    stack<int> disks;
public:
    /*
    * @param i: An integer from 0 to 2
    */
    Tower(int i) {
        // create three towers
    }

    /*
     * @param d: An integer
     * @return: nothing
     */
    void add(int d) {
        // Add a disk into this tower
        if (!disks.empty() && disks.top() <= d) {
            printf("Error placing disk %d", d);
        } else {
            disks.push(d);
        }
    }

    /*
     * @param t: a tower
     * @return: nothing
     */
    void moveTopTo(Tower &t) {
        // Move the top disk of this tower to the top of t.
        if(disks.empty()){
            printf("Error this tower is empty\n");
        }else if(!t.getDisks().empty() && disks.top() >= t.getDisks().top()){
            printf("Error placing\n");
        }else{
            t.add(disks.top());
            disks.pop();
        }
    }

    void towers(int n, Tower &from, Tower &buffer, Tower &to)
    {
        if(n==1)
        {
            from.moveTopTo(to);
        }
        else{
            towers(n-1, from, to, buffer);
            from.moveTopTo(to);
            towers(n-1, buffer, from, to);
        }
    }


    /*
     * @param n: An integer
     * @param destination: a tower
     * @param buffer: a tower
     * @return: nothing
     */
    void moveDisks(int n, Tower &destination, Tower &buffer) {
        // Move n Disks from this tower to destination by buffer tower
        towers(n, *this, buffer, destination);
    }

    /*
     * @return: Disks
     */
    stack<int> getDisks() {
        // write your code here
        return disks;
    }
};

/**
 * Your Tower object will be instantiated and called as such:
 * vector<Tower> towers;
 * for (int i = 0; i < 3; i++) towers.push_back(Tower(i));
 * for (int i = n - 1; i >= 0; i--) towers[0].add(i);
 * towers[0].moveDisks(n, towers[2], towers[1]);
 * print towers[0], towers[1], towers[2]
*/
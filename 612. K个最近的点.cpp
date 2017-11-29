
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


class Solution {
public:
    /*
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    // 0:a=b
    // 1:a>b
    // -1:a<b
    int compare(Point a, Point b, Point &origin)
    {
        int a_sum = (a.x-origin.x)*(a.x-origin.x) + (a.y-origin.y)*(a.y-origin.y);
        int b_sum = (b.x-origin.x)*(b.x-origin.x) + (b.y-origin.y)*(b.y-origin.y);
        if(a_sum == b_sum)
            return 0;
        if(a_sum > b_sum)
            return 1;
        return -1;
    }

    void min_heapify(vector<Point> &points, Point &origin, int parent, int size)
    {
        int left = 2*parent + 1;
        int right = 2*parent + 2;
        int smallest = parent;
        if(left<=size-1)
        {
            cout << "111" << endl;
            if(compare(points[left], points[smallest], origin) == -1)
            {
                smallest = left;
            }
            else if(compare(points[left], points[smallest], origin) == 0)
            {
                if(points[left].x < points[smallest].x)
                    smallest = left;
                else if((points[left].x == points[smallest].x) &&
                        (points[left].y < points[smallest].y))
                    smallest = left;
            }
        }
        if(right<=size-1)
        {
            cout << "222" << endl;
            if(compare(points[right], points[smallest], origin) == -1)
            {
                smallest = right;
            }
            else if(compare(points[right], points[smallest], origin) == 0)
            {
                if(points[right].x < points[smallest].x)
                    smallest = right;
                else if((points[right].x == points[smallest].x) &&
                        (points[right].y < points[smallest].y))
                    smallest = right;
            }
        }
        if(parent!=smallest)
        {
            Point temp = points[parent];
            points[parent] = points[smallest];
            points[smallest] = temp;
            min_heapify(points, origin, smallest, size);
        }
    }
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        // write your code here
        vector<Point> res;
        if(points.size()<k)
            return res;
        if(points.size() == k)
            return points;
        for(int i=(points.size()-2)/2; i>=0; i--)
            min_heapify(points, origin, i, points.size());
        for(int i=points.size()-1; i>0; i--)
        {
            Point temp = points[0];
            points[0] = points[i];
            points[i] = temp;
            min_heapify(points, origin, 0, i);
        }

        for(int i=points.size()-1; i>=points.size()-k; i--)
            res.push_back(points[i]);
        return res;
    }
};

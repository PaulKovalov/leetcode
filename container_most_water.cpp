/**
 * Why this works ?
    When we calculate the container size, the formula is
    (rightIndex - leftIndex) * min(height[leftIndex], height[rightIndex]).
    So key factor here is the width and height and height is determined by smaller height between the 2 indecies.

    But because we start from most left line and most right line and gradually examine inner lines, we notice that the width, (rightIndex - leftIndex) is monotonically decreasing as we examine more and more lines.

    This means, once we pick some height in each step and calculate container size, 
    that size is the maximum size of the container by using the same height as 
    at that time the width is the maximum for that height. So there is no bigger 
    container appears for the same height we pick, so in each step we pick min(height[leftIndex], height[rightIndex]) 
    and once either of the height is used, we can forget about that index.
    So if left is smaller just increament left, otherwise decreament right.
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            if ((right - left)*min(height[left], height[right]) > maxArea) {
                maxArea = (right - left)*min(height[left], height[right]);
            }
            
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;
    }
};
class Solution {
public:
    int findFirst(vector<int> &v, int target) {
        int start = 0, end = v.size() - 1, position = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (v[mid] < target)
                start = mid + 1;
            else if (v[mid] >= target)
                end = mid - 1, position = mid;
        }
        return (position != -1 && v[position] == target) ? position : -1;
    }

    int findLast(vector<int> &v, int target) {
        int start = 0, end = v.size() - 1, position = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (v[mid] > target)
                end = mid - 1;
            else if (v[mid] <= target)
                start = mid + 1, position = mid;
        }
        return (position != -1 && v[position] == target) ? position : -1;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};

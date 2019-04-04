class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            while (blue >= 0 && nums[blue] == 2) blue--;
            if (nums[i] == 0) {
                if (i == red) red++;
                else {
                    swap(nums[i], nums[red]);
                    red++;
                    while (red <= (nums.size() - 1) && nums[red] == 0) red++;
                }
            }
            else if (nums[i] == 2) {
                if (i >= blue) return;
                else {
                    swap(nums[i], nums[blue]);
                    blue--;
                    while (blue >= 0 && nums[blue] == 2) blue--;
                    if (nums[i] == 0) {
                        if (i == red) red++;
                        else {
                            swap(nums[i], nums[red]);
                            red++;
                            while (red <= (nums.size() - 1) && nums[red] == 0) red++;
                        }
                    }
                }
            }
        }
    }
};

//可能是个傻子
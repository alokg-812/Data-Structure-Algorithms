void sortColors(vector<int>& nums) {
        int n = nums.size();
        int no = 0;
        int nz = 0;
        int nt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                nz++;
            else if (nums[i] == 1)
                no++;
            else
                nt++;
        }
        for (int i = 0; i < n; i++) {
            if (i < nz)
                nums[i] = 0;
            else if (i < (no + nz))
                nums[i] = 1;
            else
                nums[i] = 2;
        }
        return;
    }
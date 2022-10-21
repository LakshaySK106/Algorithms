class Solution {
    public List<List<Integer>> permute(int[] nums) {
		List<List<Integer>> res = new ArrayList<>();
		backtrack(nums, 0, new LinkedList<>(), res);
		return res;
    }

	private void backtrack(int[] nums, int start, List<Integer> cur, List<List<Integer>> res) {
		if (cur.size() == nums.length) {
			res.add(new ArrayList<>(cur));
			return;
		}

		for (int i = 0; i <= cur.size(); i++) {
			cur.add(i, nums[start]);
			backtrack(nums, start + 1, cur, res);
            cur.remove(i);
		}
        
	}
}
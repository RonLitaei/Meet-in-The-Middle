## Steps:
1. Divide input array into two.
2. Create all subset sums for each half.
3. Sort the second subset half.
4. For every value in the subset sum of the left half:
   - **Perform binary search** in the right subset half (`lower_bound + upper_bound = equal_range`) for: `x - val`.
   - **Calculate the distance** (in case of multiple answers).
5. **Make money.**

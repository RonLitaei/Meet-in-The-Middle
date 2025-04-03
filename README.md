1. Divide input array to two.
2. Create all subsets sum to each half.
3. Sort the second half.
4. For every value in the subset sum of the left half:
  4.1 Perform binary search (lower_bound + upper_bound = equal_range) for: x - val.
  4.2 Calculate the distance (in case of multiple answers).
5. Make money.

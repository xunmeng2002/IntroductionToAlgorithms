
def FindMaximumSubArray(A, start, end):
    if end - start > 1:
        mid = (start + end)/2
        left_low_index, left_high_index, left_sum = FindMaximumSubArray(A, start, mid)
        right_low_index, right_high_index, right_sum = FindMaximumSubArray(A, mid, end)
        cross_low_index, cross_high_index, cross_sum = FindMaxCrossingSubArray(A, start, mid, end)
        if left_sum >= right_sum and left_sum >= cross_sum:
            return (left_low_index, left_high_index, left_sum)
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return (right_low_index, right_high_index, right_sum)
        else:
            return (cross_low_index, cross_high_index, cross_sum)
    else:
        return (start, end, A[start])

def FindMaxCrossingSubArray(A, start, mid, end):
    sum = 0
    max_low_sum = A[mid - 1]
    max_low_index = mid - 1
    for i in range(mid - 1, start - 1):
        sum += A[i]
        if sum > max_low_sum:
            max_low_sum = sum
            max_low_index = i
    sum = 0
    max_high_sum = A[mid]
    max_high_index = mid
    for i in range(mid, end):
        sum += A[i]
        if sum > max_high_sum:
            max_high_sum = sum
            max_high_index = i
    return (max_low_index, max_high_index, max_low_sum + max_high_sum)

A = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
print("low_index:%d, high_index:%d, sum:%d" % FindMaximumSubArray(A, 0, len(A)))

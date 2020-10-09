func maxSumTwoNoOverlap(A []int, L int, M int) int {
	for i := 1; i < len(A); i++ {
		A[i] += A[i-1]
	}

	maximum := A[L+M-1]
	maxL, maxM := A[L-1], A[M-1]

	for i := L+M; i < len(A); i++ {
		maxM = max(maxM, A[i-L] - A[i-L-M])
		maxL = max(maxL, A[i-M] - A[i-L-M])
		maximum = max(maximum, max(maxM + A[i]-A[i-L], maxL + A[i]-A[i-M]))
	}

	return maximum
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

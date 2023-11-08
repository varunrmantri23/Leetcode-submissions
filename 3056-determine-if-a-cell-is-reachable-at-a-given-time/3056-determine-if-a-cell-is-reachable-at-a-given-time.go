func isReachableAtTime(sx int, sy int, fx int, fy int, t int) bool {
	xDistance := int(math.Abs(float64(sx - fx)))
	yDistance := int(math.Abs(float64(sy - fy)))
	min_dist := int(math.Min(float64(xDistance), float64(yDistance))) + int(math.Abs(float64(yDistance - xDistance)))
	if min_dist == 0 {
		if t == 1 {
			return false
		} else {
			return true
		}
	}
	return t >= min_dist   
}
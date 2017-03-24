maxNearby :: [Int] -> Int
maxNearby l = maxNearby (0 : l) 1 0 0 where
	maxNearby (_ : []) _ maxPos _ = maxPos
	maxNearby (x : y : []) pos maxPos max = if x > max then pos else maxPos
	maxNearby (x : y : z : zs) pos maxPos max = if (x + z) > max 
		then maxNearby (y : z : zs) (pos + 1) pos $ x + z
		else maxNearby (y : z : zs) (pos + 1) maxPos max
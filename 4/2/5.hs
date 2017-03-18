sumOfThreeLists :: [Int] -> [Int] -> [Int] -> [Int]
sumOfThreeLists first second third = sumOfLists first (sumOfLists second third []) [] where
	sumOfLists [] [] result = result
	sumOfLists first second result = sumOfLists (tail' first) (tail' second) (result ++ [((head' first) + (head' second))]) where
		head' [] = 0
		head' list = head list
		tail' [] = []
		tail' list = tail list
		
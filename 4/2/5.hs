sumOfThreeLists :: [Int] -> [Int] -> [Int] -> [Int]
sumOfThreeLists [] [] [] = []
sumOfThreeLists first second third = [head' first + head' second + head' third] ++ sumOfThreeLists (tail' first) (tail' second) (tail' third) where
	head' [] = 0
	head' list = head list
	tail' [] = []
	tail' list = tail list
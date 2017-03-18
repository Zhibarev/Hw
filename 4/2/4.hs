search :: [Int] -> Int -> Int
search list number = search' list number 1 where
	search' list number current
		| list == [] = -1
		| (head list) == number = current
		| otherwise = search' (tail list) number (current + 1)
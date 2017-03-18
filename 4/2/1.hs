reverseList :: Num a => [a] -> [a]
reverseList list = reverseList' list [] where
	reverseList' [] result = result
	reverseList' list result = reverseList' (tail list) (head list : result)
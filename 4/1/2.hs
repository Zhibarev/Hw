fibonacci :: Int -> Int
fibonacci n | n >= 0 = fibonacciRecursive n 0 1
			| otherwise = error "Argument < 0"

fibonacciRecursive :: Int -> Int -> Int -> Int
fibonacciRecursive n current next | n == 0 = current
								  | otherwise = fibonacciRecursive (n - 1) next (current + next)



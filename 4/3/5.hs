fib :: Int -> Int
fib n = fib' 0 1 n where
	fib' curr prev n | n == 0 = curr
	                 | n > 0  = fib' (curr + prev) curr $ n - 1
					 | n < 0  = fib' prev (curr - prev) $ n + 1

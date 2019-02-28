fib :: Int -> Int
fib n = fib' 1 1 n where
            fib' curr _ 0 = curr
            fib' curr next n = fib' next (curr + next) (n - 1)
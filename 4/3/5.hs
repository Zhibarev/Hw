fib :: Int -> Int

fib n = fib' 0 1 n where
        fib' x _ 0 = x
        fib' curr next n = fib' next (curr + next * (signum n)) $ n - (signum n)
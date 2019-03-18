fib :: Int -> Int

fib n = (signum n) * (fib' 0 1 n) where
        fib' x _ 0 = x
        fib' curr next n = (signum n) * (fib' next (curr + next) $ n - (signum n))
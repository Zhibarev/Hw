find :: Eq a => [a] -> a -> Int

find list n = find' list n 0 where
                find' [] _ _ = -1
                find' (x:xs) n i = if x == n then i else find' xs n $ i + 1
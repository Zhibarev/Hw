multiTable :: Int -> [Int]
multiTable n = [1..n] >>= flip map [1..n].(*)
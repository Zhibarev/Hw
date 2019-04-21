angleN :: Int -> [[Int]]

angleN n = angleN' 1 n where
           angleN' k n | k > n = []
                       | otherwise = ((replicate k k) ++ (take (n - k) [(k + 1)..])) : (angleN' (k + 1) n)
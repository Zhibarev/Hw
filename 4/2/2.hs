powOfTwoList :: Int -> [Int]

powOfTwoList n = reverse $ reversedList [1] n where
                    reversedList res 0 = res
                    reversedList (x:xs) n = reversedList (2 * x:x:xs) (n - 1)
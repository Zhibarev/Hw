sumThreeLists :: [Int] -> [Int] -> [Int] -> [Int]

sumThreeLists [] [] [] = []
sumThreeLists x y z = (head' x + head' y + head' z) : sumThreeLists (tail' x) (tail' y) (tail' z) where
                        head' [] = 0
                        head' x = head x
                        tail' [] = []
                        tail' x = tail x
                                        
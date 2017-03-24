countEvenFoldr :: [Int] -> Int
countEvenFoldr = foldr ((+) . flip mod 2 . (+ 1)) 0

countEvenFilter :: [Int] -> Int
countEvenFilter = length . filter ((0 ==) . flip mod 2)

countEvenMap :: [Int] -> Int
countEvenMap = foldl (+) 0 . map (flip mod 2 . (+ 1))
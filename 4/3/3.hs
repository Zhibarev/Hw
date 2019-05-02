maxNeighbors :: [Int] -> Int

maxNeighbors l = fst $ foldl (\x y -> if (snd x) >= (snd y) then x else y) (-1, minBound::Int) $ zip [1..] $ zipWith (+) l $ tail l
reverse' :: [a] -> [a]

reverse' = foldl (\result x -> x : result) []
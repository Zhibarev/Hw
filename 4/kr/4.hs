concatMap' :: (a -> [b]) -> [a] -> [b]

concatMap' f [] = []
concatMap' f (x : xs) =  f x ++ concatMap' f xs
check :: (a -> Bool) -> [a] -> Bool

check f = foldl (flip $ (&&).f) True
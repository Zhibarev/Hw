check :: (a -> Bool) -> [a] -> Bool

check f l = foldl (\x y -> x && (f y)) True l
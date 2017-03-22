import Data.List

checkString str :: [Char] -> Bool
checkString str = check' str brackets where
	check' [] [] = True
	check' [] _ = False
	check' (x:xs) $ b:bs | elem x "[{(" = check' xs $ x:b:bs
	                     | x == "]"     = b == "[" then check' xs bs else False
						 | x == ")"     = b == "(" then check' xs bs else False
						 | x == "}"     = b == "{" then check' xs bs else False
						 | otherwise    = check' xs $ b:bs
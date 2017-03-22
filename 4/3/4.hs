import Data.List

checkStr :: [Char] -> Bool
checkStr str = check' str "&" where -- "&" != [] for don't describe (check' str [])
	check' [] "&" = True
	check' [] _ = False
	check' (x:xs) (b:bs) 
		| elem x "[{(" = check' xs (x:b:bs)
		| x == ']'     = if b == '[' then check' xs bs else False
		| x == ')'     = if b == '(' then check' xs bs else False
		| x == '}'     = if b == '{' then check' xs bs else False
		| otherwise    = check' xs (b:bs)
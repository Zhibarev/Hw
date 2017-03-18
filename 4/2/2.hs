getListOfDegrees :: Integer -> [Integer]
getListOfDegrees degree = getListOfDegrees' [] 1 degree where
	getListOfDegrees' list number (-1) = list
	getListOfDegrees' list number counter = getListOfDegrees' (list ++ [number]) (number * 2) (counter - 1)
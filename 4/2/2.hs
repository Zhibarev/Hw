getListOfDegrees :: Integer -> [Integer]
getListOfDegrees degree = reverse $ getListOfDegrees' [1] degree where
	getListOfDegrees' list 0 = list
	getListOfDegrees' (x : xs) degree = getListOfDegrees' (x * 2 : x : xs) $ degree - 1
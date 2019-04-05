plusMinusOne :: [Integer]
plusMinusOne = 1 : -1 : plusMinusOne

alterSignNumbers :: [Integer]
alterSignNumbers = zipWith (*) [1..] plusMinusOne
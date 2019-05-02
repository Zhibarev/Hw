list179 :: [Integer]

list179 = 1 : 7 : 9 : concatMap (flip (zipWith (+).repeat.(* 10)) [1, 7, 9]) list179
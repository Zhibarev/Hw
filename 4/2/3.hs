numeralSum :: Integer -> Integer
numeralSum number = numeralSum' number 0 where
	numeralSum' 0 sum = sum
	numeralSum' number sum = numeralSum' (div number 10) (sum + (mod number 10))
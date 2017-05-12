printSquare :: Int -> IO()

printOther 0 _ = return (putStr "")
printOther n l = do 
	putStr ('X' : (replicate l '0'))
	putStrLn "X"
	printOther (n - 1) l

printSquare n = do
	putStrLn (replicate n 'X') 
	printOther (n - 2) (n - 2)
	putStrLn (replicate n 'X')
				   
				   
		
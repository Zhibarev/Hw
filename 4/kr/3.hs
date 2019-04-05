printRhomb :: Int -> IO()

printRhomb n = printRhomb' n 1 1 where
               printRhomb' n i sgn | i == 0 = putStr("")
                                   | i < n = putStr (replicate (n - i) ' ') >>
                                                putStr (replicate (2 * i - 1) 'x') >>
                                                putStrLn (replicate (n - i) ' ') >>
                                                printRhomb' n (i + sgn) sgn
                                   | i == n = putStrLn (replicate (2 * n - 1) 'x') >>
                                                printRhomb' n (i - 1) (-1)
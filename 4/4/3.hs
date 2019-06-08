import System.IO

findBy :: String -> (b -> String) -> (b -> String) -> [b] -> String
findBy _ _ _ [] = "Not found"
findBy s f g (x : xs) = if s == (f x) then g x else findBy s f g xs

writeToFile :: Handle -> [(String, String)] -> IO ()
writeToFile _ [] = return ()
writeToFile h ((x,y) : xs) =  do hPutStrLn h x
                                 hPutStrLn h y
                                 writeToFile h xs
                                     
readFromFile :: Handle -> IO [(String, String)]
readFromFile h = do eof <- hIsEOF h
                    if eof 
                        then
                            return []
                        else 
                            do x <- hGetLine h
                               y <- hGetLine h
                               end <- readFromFile h
                               return ((x,y) : end)
                               
getFile :: IO String
getFile = putStrLn "Enter file's name" >> getLine

help :: IO ()
help = do putStrLn ("0 - exit")
          putStrLn ("1 - add to phonebook")
          putStrLn ("2 - find by name")
          putStrLn ("3 - find by number")
          putStrLn ("4 - save to file")
          putStrLn ("5 - load from file")
          
phonebook :: IO ()
phonebook = do help
               phonebook' []

phonebook' :: [(String, String)] -> IO ()
phonebook' book = do
    command <- putStrLn ("Enter command") >> getLine
    case command of
        "0" -> return ()
        "1" -> do name <- putStrLn ("Enter name") >> getLine
                  number <- putStrLn ("Enter number") >> getLine
                  phonebook' $ (name, number) : book
        "2" -> do name <- putStrLn ("Enter name") >> getLine
                  putStrLn $ findBy name fst snd book
                  phonebook' book
        "3" -> do number <- putStrLn ("Enter number") >> getLine
                  putStrLn $ findBy number snd fst book
                  phonebook' book
        "4" -> do fileName <- putStrLn "Enter file's name" >> getLine
                  h <- openFile fileName WriteMode
                  writeToFile h book 
                  hClose h
                  phonebook' book
        "5" -> do fileName <- putStrLn "Enter file's name" >> getLine
                  h <- openFile fileName ReadMode
                  book <- readFromFile h
                  hClose h
                  phonebook' book
        _ -> do putStrLn "Unknown command"
                phonebook' book
                  

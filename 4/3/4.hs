import Data.Map

checkBranches :: [Char] -> Bool

checkBranches xs = checkBranches' "&" xs $ fromList [(')', '('), ('}', '{'), (']', '[')] where
                   checkBranches' bs [] _ = bs == "&"
                   checkBranches' (b : bs) (x : xs) dict | elem x $ elems dict = checkBranches' (x : b : bs) xs dict
                                                         | notElem x $ keys dict = checkBranches' (b : bs) xs dict
                                                         | dict ! x == b = checkBranches' bs xs dict
                                                         | otherwise = False
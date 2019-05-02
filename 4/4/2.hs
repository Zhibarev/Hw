data AST = ASTnum Float | ASTvar Char | ASTop Char AST AST
    deriving Show
    

derivative :: AST -> AST
derivative (ASTnum a) = ASTnum 0
derivative (ASTvar c) = ASTnum 1
derivative (ASTop '*' left right) = ASTop '+' (ASTop '*' left $ derivative right) (ASTop '*' (derivative left) right) 
derivative (ASTop '/' left right) = ASTop '/' (ASTop '-' (ASTop '*' left $ derivative right) (ASTop '*' (derivative left) right))
                                              (ASTop '*' right right)
derivative (ASTop plusMinus left right) = ASTop plusMinus (derivative left) (derivative right)
 
--fromInfix :: [Char] -> AST


--toInfix :: AST -> [Char]

--reduceExp :: [Char] -> [Char]
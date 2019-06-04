data Expr = Const Float 
            | Var 
            | Expr :+: Expr 
            | Expr :-: Expr 
            | Expr :*: Expr 
            | Expr :/: Expr
    deriving Show
    
derivate :: Expr -> Expr
derivate (Const n) = Const 0
derivate Var = Const 1
derivate (expr1 :+: expr2) = (derivate expr1) :+: (derivate expr2)
derivate (expr1 :-: expr2) = (derivate expr1) :-: (derivate expr2)
derivate (expr1 :*: expr2) = ((derivate expr1) :*: expr2) :+: (expr1 :*: (derivate expr2))
derivate (expr1 :/: expr2) = (((derivate expr1) :*: expr2) :-: (expr1 :*: (derivate expr2))) :/: (expr1 :*: expr2)

simplify :: Expr -> Expr
simplify ((Const 1) :*: expr) = simplify expr
simplify (expr :*: (Const 1)) = simplify expr
simplify ((Const 0) :*: expr) = Const 0
simplify (expr :*: (Const 0)) = Const 0
simplify (expr :/: (Const 1)) = simplify expr
simplify ((Const 0) :+: expr) = simplify expr
simplify (expr :+: (Const 0)) = simplify expr
simplify (expr :-: (Const 0)) = simplify expr
simplify (expr1 :*: expr2) = (simplify expr1) :*: (simplify expr2)
simplify (expr1 :/: expr2) = (simplify expr1) :/: (simplify expr2)
simplify (expr1 :+: expr2) = (simplify expr1) :+: (simplify expr2)
simplify (expr1 :-: expr2) = (simplify expr1) :-: (simplify expr2)
simplify expr = expr

simpleDer :: Expr -> Expr
simpleDer = simplify . derivate
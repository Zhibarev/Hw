data Polynom a = Polynom [a]
    
liftP :: ([a] -> [a]) -> Polynom a -> Polynom a
liftP f (Polynom x) = Polynom $ f x
   
pPlus :: Num a => Polynom a -> Polynom a -> Polynom a
pPlus (Polynom (x:xs)) (Polynom (y:ys)) = liftP ((x + y) :) (pPlus (Polynom xs) (Polynom ys))
pPlus (Polynom []) (Polynom xs) = Polynom xs
pPlus (Polynom xs) (Polynom []) = Polynom xs

pMultiply :: Num a => Polynom a -> Polynom a -> Polynom a
pMultiply (Polynom (x:xs)) (Polynom ys) = pPlus (liftP (map (x *)) (Polynom ys)) $ pMultiply (Polynom xs) $ Polynom (0:ys)
pMultiply (Polynom []) _ = Polynom []

instance Show a => Show (Polynom a) where
    show (Polynom xs) = concat [(if degree == 0 then "" else " + ") ++ (show value) ++ " * x^" ++ (show degree) | (degree, value) <- (zip [0..] xs)]
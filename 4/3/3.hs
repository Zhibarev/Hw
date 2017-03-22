import Data.List
import Data.Ord

maxNearby l = snd $ maximumBy (comparing fst) (reverse $ zip (map (uncurry (+)) $ zip (0:init l) $ tail l ++ [0]) [1..])
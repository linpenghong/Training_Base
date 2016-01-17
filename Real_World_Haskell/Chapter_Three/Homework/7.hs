intersperse :: a -> [[a]] -> [a]
intersperse _ [] = []
intersperse x (y : ys) = y ++ x : (intersperse x ys)

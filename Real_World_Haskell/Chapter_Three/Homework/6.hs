import Data.List

sortByLength ::[[a]] -> [[a]]

sortByLength xs = sortBy (\x y -> compare (length x) (length y)) xs

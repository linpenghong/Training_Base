mean' :: [Float] -> Float

mean' xs = (sum xs) / len
               where len = fromIntegral (length xs) :: Float

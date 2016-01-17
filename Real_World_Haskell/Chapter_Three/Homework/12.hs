data Direction = MyLeft
               | MyRight
               | StringLine deriving (Show)

data Point = Point Float Float deriving (Show)

turn :: Point -> Point -> Point -> Direction
turn a b c = deter x
                  where deter x | x < 0 = MyLeft
                                | x == 0 = StringLine
                                | x > 0 = MyRight
                        (Point x _) = diff (diff c b) (diff b a)
                            where diff (Point x1 y1) (Point x2 y2) = Point (x1 - x2) (y1 - y2)

turnList :: [Point] -> [Direction]
turnList [] = []
turnList (_ : []) = []
turnList (_ : (_ : [])) = []
turnList (a : (b : (c : xs))) = (turn a b c) : (turnList (b : (c : xs)))

data Direction = MyLeft
               | MyRight
               | StringLine deriving (Show)

data Point = Point Float Float deriving (Show)

a = Point 0 0
b = Point 0 1
c = Point 1 0

turn :: Point -> Point -> Point -> Direction
turn a b c = deter x
                  where deter x | x < 0 = MyLeft
                                | x == 0 = StringLine
                                | x > 0 = MyRight
                        (Point x _) = diff (diff c b) (diff b a)
                            where diff (Point x1 y1) (Point x2 y2) = Point (x1 - x2) (y1 - y2)

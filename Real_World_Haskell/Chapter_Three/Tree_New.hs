data Tree a = Node a (Maybe (Tree a)) (Maybe (Tree a)) deriving (Show)

tree1 = Node "parent" Nothing Nothing
tree2 = Node "parent" (Node "left child" Nothing Nothing) Nothing

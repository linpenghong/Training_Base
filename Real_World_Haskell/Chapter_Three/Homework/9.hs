data Tree a = Node a (Tree a) (Tree a)
            | Empty
            deriving (Show)

tree1 = Node "x" Empty Empty
tree2 = Node "x" (Node "y" Empty Empty) Empty
tree3 = Node "x" (Node "y" Empty Empty)
                 (Node "z" Empty Empty)

treeHeight :: Tree a -> Int

treeHeight Empty = 0
treeHeight (Node _ l r) = 1 + max (treeHeight l) (treeHeight r)

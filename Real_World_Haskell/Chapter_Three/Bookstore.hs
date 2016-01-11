data BookInfo = Book Int String [String]
                deriving (Show)

myInfo = Book 9780 "Algebra of Programming" ["Richard Bird", "Oege de Moor"]

type CustomerID = Int
type ReviewBody = String

data BookReview = BookReview CustomerID ReviewBody

type BookRecord = (BookInfo, BookReview)

type CardNumber = Int
type CardHolder = String
type Address = [String]

-- CreditCard / CashOnDelivery / Invoice are three constructors of BillingInfo
data BillingInfo = CreditCard CardNumber CardHolder Address
                 | CashOnDelivery
                 | Invoice CustomerID
                 deriving (Show)

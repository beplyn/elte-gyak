module Gyak1112 where

inc :: (Num a) => a -> a
inc n = n + 1

cmpr :: (Ord a) => a -> a -> String
cmpr x y
  | x < y = "less"
  | x == y = "equal"
  | otherwise = "more"

isZero :: (Num a, Eq a) => a -> Bool
isZero x = x == 0

data Anwser = Yes | No | Maybe deriving (Show)

data Pair = P Int Int deriving (Show, Eq)

addElems :: Pair -> Int
addElems (P x y) = x + y

data Day = Mon | Tue | Wed | Thu | Fri | Sat | Sun deriving (Show, Eq, Enum)

isWeekend :: Day -> Bool
isWeekend Sat = True
isWeekend Sun = True
isWeekend _ = False

tomorrow :: Day -> Day
tomorrow Sun = Mon

tomorrow x succ x

data USTime = AM Int Int | PM Int Int deriving (Show, Eq)

showUSTime :: USTime -> String
showUSTime (AM h m) = show h ++ "." show m ++ " am"
showUSTime (PM h m) = show h ++ "." show m ++ " pm"

instance Show USTime where
  show x = showUSTime x

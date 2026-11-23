module Week9 where


data USTime = AM Int Int | PM Int Int
  deriving (Eq, Show)

data CardinalPoint = North | East | South | West
  deriving (Show, Eq)

numOfDirection :: CardinalPoint -> [CardinalPoint] -> Integer
numOfDirection dir xs = fromIntegral (length [x | x <- xs, x == dir])

turnLeft :: CardinalPoint -> CardinalPoint
turnLeft North = West
turnLeft West  = South
turnLeft South = East
turnLeft East  = North

data Time = T Int Int
  deriving (Eq, Show)

time2USTime :: Time -> USTime
time2USTime (T 0 m)  = AM 12 m
time2USTime (T 12 m) = PM 12 m
time2USTime (T h m)
  | h < 12    = AM h m
  | otherwise = PM (h - 12) m

uSTime2Time :: USTime -> Time
uSTime2Time (AM 12 m) = T 0 m
uSTime2Time (AM h m)  = T h m
uSTime2Time (PM 12 m) = T 12 m
uSTime2Time (PM h m)  = T (h + 12) m

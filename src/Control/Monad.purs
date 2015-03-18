module Control.Monad where

replicateM :: forall m a. (Monad m) => Number -> m a -> m [a]
replicateM 0 _ = return []
replicateM n m = do
  a <- m
  as <- replicateM (n - 1) m
  return (a : as)

foldM :: forall m a b. (Monad m) => (a -> b -> m a) -> a -> [b] -> m a
foldM _ a [] = return a
foldM f a (b:bs) = f a b >>= \a' -> foldM f a' bs

when :: forall m. (Monad m) => Boolean -> m Unit -> m Unit
when true m = m
when false _ = return unit

unless :: forall m. (Monad m) => Boolean -> m Unit -> m Unit
unless false m = m
unless true _ = return unit

-- | Filter where the predicate returns a monadic Boolean. For example: 
-- |
-- | ```purescript
-- | powerSet :: forall a. [a] -> [[a]]
-- | powerSet = filterM (const [true, false])
-- | ```
filterM :: forall a m. (Monad m) => (a -> m Boolean) -> [a] -> m [a]
filterM _ [] = return []
filterM p (x:xs) = do
  b <- p x
  xs' <- filterM p xs
  return $ if b
           then x : xs'
           else xs'

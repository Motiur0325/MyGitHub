pairs=[(1,'one'),(7,'seven'),(3,'three'),(8,'eight'),(6,'six')]
print(pairs)
#Sort through first key in tuple i.e, sorting of list is done through numeric keys.
pairs.sort(key=lambda pair:pair[0])
print(pairs)
#Sort through second key in tuple i.e.,sorting of list is done through the string keys.
pairs.sort(key=lambda pair: pair[1])
print(pairs)

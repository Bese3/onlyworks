def best_score(a_dictionary):
   if a_dictionary is None or len(a_dictionary.keys()) == 0:
      return None
   key = []
   value = []
   best_score = 0
   for i , j in zip(a_dictionary.keys() , a_dictionary.values()):
      key.append(i)
      value.append(j)
   for i in range(len(value)):
      if value[best_score] < value[i]:
         best_score = i
         
   return list(a_dictionary.keys())[best_score]
   
     
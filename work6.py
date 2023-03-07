def multiple_returns(sentence):
    if sentence == None or sentence == "":
        return tuple((len(sentence) , None))
    else:
        return tuple((len(sentence) , sentence[0]))
def count(w, words):
    count = 0
    for i in words:
        if i == w:
            count += 1
    return count

def most_frequent(words):
    mf_word = ""
    frequency = 0
    for w in words:
        f = count(w, words)
        if f > frequency:
            mf_word = w
            frequency = f
    return mf_word

def frequencies(words):
    fs = {}
    for w in words:
        if w in fs:
            fs[w] += 1
        else:
            fs[w] = 1
    return fs

def max_val(d, esclusi):
    max = 0
    max_key = ""
    for k in d.keys():
        if not k in esclusi and d[k] > max:
            max = d[k]
            max_key = k
    return max_key

def dict_to_couples(di):
    cs = []
    for k in di.keys():
        cs += [(di[k], k)]
    return cs




def word_count(s):
    word = s.split()
    count_of_words ={}
    for i in word:
        if i in count_of_words:
            count_of_words[i] += 1
        else:
            count_of_words[i] = 1
    return count_of_words    
    pass
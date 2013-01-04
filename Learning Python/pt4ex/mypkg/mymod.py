def countLines(file):
    """
    Reads an input file and counts the number
    of lines in it. Hint: file.readlines()
    """
    file.seek(0)
    return len(file.readlines())

def countChars(file):
    """
    Reads an input file and counts the number
    of characters in it. Hint: file.read()
    """
    file.seek(0)
    return len(file.read())

def test(name):
    """
    Calls both counting functions with a given
    input filename.
    """
    file = open(name)
    #print "Counting lines in file {0}".format(name)
    #countLines(file)
    #print "Counting characters in file {0}".format(name)
    #countChars(file)
    
    return countLines(file), countChars(file)

if __name__ == "__main__": 
    import sys
    print test(sys.argv[1])

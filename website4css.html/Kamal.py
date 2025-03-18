import os.path
import sys
#from pathlib import path
fname = input("enter the file name=")
if not os.path.isfile (fname):
    print("File",fname,"doesnot exist")
    sys.exit(0)
infile=open(fname,"r")
lineList = infile.readlines()
i=1
for i in range(7):
    print(i,":",lineList[i])
word=input("enter a word")
cnt=0
for line in lineList:
    cnt+=line.count(word)
print("the word",word,"appears",cnt,"times in the file")
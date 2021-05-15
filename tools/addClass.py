#!/usr/bin/env python3

import sys
import os

def fileExists(fileName):
    return os.path.isfile(fileName)

def createFile(fileName):
    with open(fileName,'w'): pass

def addFile(fileName):
    if fileExists(fileName):
        print(fileName, "already exists")
    else:
        createFile(fileName)
        print("Created",fileName)

def makeHeaderFileName(rootName,moduleName,className):
    return os.path.join(rootName, "lib", "include", moduleName, className + ".h")

def makeSourceFileName(rootName,moduleName,className):
    return os.path.join(rootName, "lib", "source", moduleName, className + ".cpp")

def makeTestsFileName(rootName,moduleName,className):
    return os.path.join(rootName, "tests", moduleName, className + "Tests.cpp")

def getFileNameParts():
    rootName = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))    
    moduleName = sys.argv[1]
    className = sys.argv[2]

    return rootName, moduleName, className

def addClass():
    rootName, moduleName, className = getFileNameParts()

    addFile(makeHeaderFileName(rootName,moduleName,className))
    addFile(makeSourceFileName(rootName,moduleName,className))
    addFile(makeTestsFileName(rootName,moduleName,className))

if __name__ == "__main__":
    addClass()
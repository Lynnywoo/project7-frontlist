# Makefile for Project 7 – FrontList (HasA, IsA, AsA)
# Usage:
#   make          – build all three test programs
#   make hasA     – build testerHasA only
#   make isA      – build testerIsA only
#   make asA      – build testerAsA only
#   make run      – build and run all three testers
#   make clean    – remove binaries

CXX      = g++
CXXFLAGS = -std=c++14 -Wall -Wextra

.PHONY: all hasA isA asA run clean

all: hasA isA asA

hasA: testerHasA.cpp FrontListHasA.h FrontListHasA.cpp \
      LinkedList.h LinkedList.cpp Node.h Node.cpp \
      FrontListInterface.h ListInterface.h PrecondViolatedExcep.h
	$(CXX) $(CXXFLAGS) -o testerHasA testerHasA.cpp

isA: testerIsA.cpp FrontListIsA.h FrontListIsA.cpp \
     LinkedList.h LinkedList.cpp Node.h Node.cpp \
     FrontListInterface.h ListInterface.h PrecondViolatedExcep.h
	$(CXX) $(CXXFLAGS) -o testerIsA testerIsA.cpp

asA: testerAsA.cpp FrontListAsA.h FrontListAsA.cpp \
     LinkedList.h LinkedList.cpp Node.h Node.cpp \
     FrontListInterface.h ListInterface.h PrecondViolatedExcep.h
	$(CXX) $(CXXFLAGS) -o testerAsA testerAsA.cpp

run: all
	@echo ""; echo "====== HAS-A ======"
	./testerHasA
	@echo ""; echo "====== IS-A ======"
	./testerIsA
	@echo ""; echo "====== AS-A ======"
	./testerAsA

clean:
	rm -f testerHasA testerIsA testerAsA

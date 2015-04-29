//
//  main.h
//  PRAlgo
//
//  Created by Bradley Morgan on 2/23/15.
//  Copyright (c) 2015 Bradley Morgan. All rights reserved.
//

#ifndef PRAlgo_main_h
#define PRAlgo_main_h

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

char algo;
int frames;
int lcount;

string fname;
string* pages;
string* queue;

ifstream lines;

void getAlgorithmSelection();
void getFileName();
void getFrameSize();

bool getFileContents();

void executeFIFO();
void executeLRU();

#endif

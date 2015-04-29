//
//  main.cpp
//  PRAlgo
//
//  Created by Bradley Morgan on 2/23/15.
//  Copyright (c) 2015 Bradley Morgan. All rights reserved.
//

#include "main.h"

int main(int argc, const char * argv[]) {
    
    char run;
    
    while(1) {
        
        cout << "\n\nPage Replacement Algorithm Simulator\n";
        cout << "------------------------------------\n\n";
        
        getAlgorithmSelection();
        getFrameSize();
        getFileName();
       
        if(getFileContents()) {

            if(algo == '1') {
                
                executeFIFO();
                
            } else {
                
                executeLRU();
                
            }
            
        }
        
        cout<<"Run Again? ";
        
        cin>>run;
        
        if (run != 'y' && run != 'Y') { break; }
        
    }
    
    return 0;
    
}

void getFileName() {
    
    cout << "\nFilename: ";

    cin >> fname;
    
    cout << "\nLoading " << fname << "...";
    
}

bool getFileContents() {
    
    string line;
    
    lines.open(fname.c_str());
    
    if(lines.is_open()) {
        
        while (getline(lines, line))
            lcount++;
       
        pages = new string[lcount];

        lcount = 0;
        
        lines.clear();
        lines.seekg(0, ios::beg);
        
        while(!lines.eof()) {
            
            getline(lines,line);
            
            if(!line.empty()) {
            	pages[lcount] = line;
            	 lcount++;
            }
            
        }
        
        cout << "\nRead " << lcount << " lines...\n\n";
        
        for(int i=0; i < lcount; i++) {
        
            cout << pages[i] << "\n";
            
        }
        
        return true;
        
        
    } else {
        
        cout << "File not found.\n\n";
        
        return false;
        
    }
    
    
}

void getFrameSize() {

    string algo_name;
    
    (algo == '1') ? algo_name = "FIFO" : algo_name = "LRU";
    
    cout << "\nFrame size for " << algo_name << ": ";
    cin >> frames;
    
    queue = new string[frames];
    
}

void getAlgorithmSelection() {
    
    cout << "1. FIFO\n";
    cout << "2. LRU\n\n";
    
    do {
        
        cout << "Please choose an algorithm: ";
        cin >> algo;
        
        if(algo != '1' && algo != '2') {
            
            cout << "\nInvalid selection.\n";
            
        }
        
    } while(algo != '1' && algo != '2');
    
}

void executeFIFO() {
 
    int faults = 0;
    
    for(int i=0; i < lcount; i++) {
        
        cout << "\n\nLooking for page " << pages[i];
        
        bool found = false;
        
            for(int j=0; j < frames; j++) {
                
                if(queue[j] == pages[i]) {
                    
                    cout << "...FOUND" << "\n\n";
                    
                    found = true; break;
                    
                }
                
            }
            
            if(!found) {
            
                // left shift the array values
                
                for(int k = 0; k < (frames - 1); k++) {
                 
                    queue[k] = queue[k+1];
                    
                }
                
                queue[frames - 1] = pages[i];
                
                faults++;

                cout << "...FAULT" << "\n\n";

            }
        
            for(int i=0; i < frames; i++) {
                
                cout << queue[i] << "|";
                
            }
        
            
        }
    
    cout << "\n\nTotal FIFO Page Faults: " << faults << "\n\n";
    
}

void executeLRU() {
    
    int faults = 0;
    
    for(int i=0; i < lcount; i++) {
        
        cout << "\n\nLooking for page " << pages[i];
        
        bool found = false;
        
        for(int j=0; j < frames; j++) {
            
            if(queue[j] == pages[i]) {
                
                cout << "...FOUND" << "\n\n";
                
                for(int l=j; l > 0; l--) {
                    
                    queue[l] = queue[l - 1];
                    
                }
                
                for(int k = 0; k < (frames - 1); k++) {
                    
                    queue[k] = queue[k+1];
                    
                }
                
                queue[frames - 1] = pages[i];
                
                found = true; break;
                
            }
            
        }
        
        if(!found) {
            
            // left shift the array values
            
            for(int k = 0; k < (frames - 1); k++) {
                
                queue[k] = queue[k+1];
                
            }
            
            queue[frames - 1] = pages[i];
            
            faults++;
            
            cout << "...FAULT" << "\n\n";
            
        }
        
        for(int i=0; i < frames; i++) {
            
            cout << queue[i] << "|";
            
        }
        
        
    }
    
    cout << "\n\nTotal LRU Page Faults: " << faults << "\n\n";
    
}

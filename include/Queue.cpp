#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]) {
    
    ifstream input(argv[1]);
    ofstream output(argv[2]);
    string input_str;
    string check;
    string val;
    int value = 0;
    bool val_check = true;
    int count = 9;
    int head = 0;
    int tail = 0;
    int size = 0;
    bool over = false;
    
    while (!input.eof()) {
        
        getline(input, input_str);
        if (input_str.size() > count) {
            for ( int i = 0; i < count; i++) {
                check += input_str[i];
            }
            if (check == "set_size ") {
                for (int i = count; i < input_str.size(); i++) {
                    if ((input_str[i] >= '0') && (input_str[i] <= '9')) {
                        val += input_str[i];
                    }
                    else {
                        val_check = false;
                    }
                }
                
                if (val_check == true) {
                    value = stoi(val);
                    size = value;
                    break;
                }
                else {
                    output << "error" << endl;
                }
                
            }
            else {
                output << "error" << endl;
            }
        }
        else if ((input_str != "") && (input_str != "\n") && (input_str != " \n")) {
            output << "error" << endl;
        }
        
        
        
        check = "";
    }
    
    if (size) {
        string *queue = new string[size];
        count = 5;
        check = "";
        while (!input.eof())
        {
            getline(input, input_str);
            for ( int i = 0; i < count; i++) {
                check += input_str[i];
            }
            if (check == "push ") {
                val = "";
                val_check = true;
                for (int i = 5; i < input_str.size(); i++)
                {
                    if (input_str[i] == ' ')
                        val_check = false;
                    else
                        val += input_str[i];
                }
                if (val_check == true) {
                    
                    if (((head-tail) == size) && !(over))
                        output << "overflow" << endl;
                    else if ((over) && (head + size - tail) >= size)
                        output << "overflow" << endl;
                    else
                    {
                        queue[head] = val;
                        head++;
                        if (head >= size)
                        {
                            head = head % size;
                            over = true;
                        }
                    }
                }
                else
                {
                    output << "error" << endl;
                }
            }
            
                else if (input_str == "print")
                {
                    if (!over)
                    {
                        if ((head - tail) == 0)
                        {
                            output << "empty" << endl;
                        }
                        else
                        {
                            for (int i = tail; i < head-1 ; i++)
                                output << queue[i] << " ";
                            output << queue[head- 1] << endl;
                        }
                    }
                    else
                    {
                        
                        if (head)
                        {
                            for (int i = tail; i< size; i++)
                                output << queue[i] << " ";
                            for (int i = 0; i < head - 1; i++)
                                output << queue[i] << " ";
                            output << queue[head - 1] << endl;
                        }
                        else
                        {
                            for (int i = tail; i< size-1; i++)
                                output << queue[i] << " ";
                            output << queue[size - 1] << endl;
                        }
                    }
                }
            
            else if (input_str == "pop")
            {
                
                if (((head - tail) == 0) && (!over))
                output << "underflow" << endl;
                else
                {
                    output << queue[tail] << endl;;
                    tail++;
                    if (tail >= size)
                    {
                        over = false;
                        tail = tail % size;
                    }
                }
                
            }
            else if(input_str!="") {
                output << "error" << endl;
            }
            check = "";
        }
        
        delete[] queue;
    }
    
    
    input.close();
    output.close();
    return 0;
}

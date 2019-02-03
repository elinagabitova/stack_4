#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Queue
{
public:
    Queue(int size)
    {
        this->size = size;
        number = new string[size];
    }

    string push(string value)
    {
        if (curr_size < size)
        {
            number[tail] = value;
            tail = (tail+1)%size;
            curr_size++;
            return "";
        } 
        else return "overflow";
    }

    string pop()
    {
        if (curr_size == 0)
        {
            return "underflow";
        } 
        else 
        {
            curr_size--;
            string x = number[head];
            head = (head + 1) % size;
            return x;
        }
    }

    string print()
    {
        string answer = "";
        if (curr_size == 0)
            return "empty";
        if (tail == 0 ||head < tail)
        {
            int count = (tail==0)?size :tail;
            for(int i = head; i < count; i++) 
            {
                answer += number[i];
                if (i != count - 1)
                    answer += " ";
            }
        } 
        else 
        {
            for(int i = head; i < size; i++)
                answer += number[i] + " ";

            for(int i = 0; i < tail; i++) 
            {
                answer += number[i];
                if (i != tail - 1)
                    answer += " ";
            }
        }
        return answer;
    }
    
    ~Queue()
    {
        delete[] number;
    }

private:
    long curr_size = 0;
    long head = 0;
    long tail = 0;
    long size;
    string* number;
};


int main(int argc, char *argv[])
{
    int val;
    bool init;
    string value, check, cmd;
    int size = 0;
    ifstream input(argv[1]);
    ofstream output(argv[2]);
    
    while (!input.eof())
    {
        getline(input, cmd);
        
        if (cmd.size() > 9) 
        {
            for ( int i = 0; i < 9; i++) 
            check += cmd[i];
        
            if ((cmd != "") && (cmd != "\n") && (cmd != " \n")) 
            {
                output << "error" << endl;
            }
        
            else if (check == "set_size ") 
            {
                init = true;
                value = "";
                for (int i = 9; i < cmd.size(); i++)
                    {
                        if ((cmd[i] >= '0') && (cmd[i] <= '9'))
                            value += cmd[i];
                        else
                            init = false;
                    }
                
                if (init == true)
                {
                    val = stoi(value);
                    size = val;
                    break;
                }
                else output << "error" << endl;
            }
        else output << "error" << endl;
        }
        check = "";
    }
    
    if (size!= 0)
    {
        Queue queue = Queue(size);
        while (!input.eof())
        {
            getline(input, cmd);
            
            if (cmd.size() > 5) 
            {
                for (int i = 0; i < 5; i++) 
                check += cmd[i];
            }
            if (check == "push ") 
            {
                init = true;
                value = "";
                for (int i = 5; i < cmd.size(); i++)
                {
                    if (cmd[i] == ' ')
                        init = false;
                    else
                        value += cmd[i];
                }
                
                if (init)
                {
                    string answer = queue.push(value);
                    if (answer != "")
                        output << queue.push(value) << endl;
                }
                else
                {
                    output << "error" << endl;
                }
            }
            else if (cmd == "pop")
            {
                output << queue.pop() << endl;
            }
            else if (cmd == "print")
            {
                string answer = queue.print();
                if (answer != "")
                    output << queue.print() << endl;
            }
            else
            if(cmd!="")
                output << "error" << endl;
        }
    }
    input.close();
    output.close();
    return 0;
}

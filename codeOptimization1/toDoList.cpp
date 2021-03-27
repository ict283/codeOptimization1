// For review purposes only! Does not represent the actual solution!

#include "toDoList.h"

ToDoList::ToDoList()
{

}

ToDoList::~ToDoList()
{

}

void ToDoList::run()
{
        store(read("to_do_data.txt"));
        display();

}

string ToDoList::read(const string fileName)
{
        ifstream infile (fileName);

        if(!infile.is_open())
        {
                cout<<"Error: File Not Found - "<<fileName<<endl;
                return NULL;
        }

        string fileStreamData;
        getline(infile, fileStreamData);
        return fileStreamData;

}

void ToDoList::store(string fileStreamData)
{
        istringstream stringStream {fileStreamData}; //stringify

        string item;
        string taskDay="";
        int taskNum=1;

        while (getline(stringStream,item,','))
        {
                if(item[0]=='#')
                {
                        taskDay= item.substr(1,item.length());
                        taskNum =1;
                }
                else
                {
                        Task task;
                        task.key = taskDay;
                        task.num = taskNum++;
                        task.taskDescription = item;
                }
        }
}

void ToDoList::display()
{
        
}

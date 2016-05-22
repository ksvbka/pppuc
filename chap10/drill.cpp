#include <cstdlib> // For std::rand()
#include <fstream> // for ofstream and ifstream
#include <stdexcept>
#include <iostream>

using namespace std;

void test_write_file(string file_name){
    ofstream ost{file_name}; // Open file for write
    if(!ost)
        throw runtime_error("Can't open file ");
    for(int i = 0; i < 50; ++i){
        ost << i << "\t: " << rand()%100 << endl;;
    }

}

void test_read_file(string file_name){
    ifstream ist{file_name};
    if(!ist)
        throw runtime_error("Can't open file");
    string item;
    while(ist >> item){
        cout << item;
    }
}

int main(int argc, char const *argv[])
{
    try{
        test_write_file("log.txt");
        test_read_file("log.txt");
    }catch(runtime_error &e){
        cout << e.what() << endl;
    }catch(...){
        cout << "Exiting...!" << endl;
    }
    return 0;
}

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<vector>
#include<ctime>
#include<unistd.h>

using namespace std;

class Mars{
    private:
    vector<vector<char>> map;
    int dimX, dimY;

    public:
    Mars(){
        init();
    }

    void init();
    void display();
    int getdimX();
    int getDimY();
    char getObject(int x, int y);
    void setObject(int x, int y, char c);
    bool isEmpty(int x, int y);

};

void Mars::init(){

    char objects[] ={' ',' ',' ',' ',' ',' ',
                    'X','#','@','$'};
    
    int noOfObjects = 10;

    dimX = 15;
    dimY = 5;

    //create dynamic 2D array using vector
    map.resize(dimY); //create rows
    for (int i=0;i<dimY;i++){
        map[i].resize(dimX);//resize each row
    }

    //put random chars into the vector array
    for(int i=0;i<dimY; ++i){
        for(int j=0; j<dimX; ++j){
            int objNo = rand() % noOfObjects;
            map[i][j] = objects[objNo];
        }
    }
}

void Mars::display()
{
    system("cls");
    cout<<"--__--__--__--__--__--__--__--_"<<endl;
    cout<<"= Curiosity, welcome to Mars! ="<<endl;
    cout<<"--__--__--__--__--__--__--__--_"<<endl;

    for(int i=0; i<dimY; ++i){
        cout<<" ";
        for(int j=0;j<dimX; ++j){
            cout<<"+-";
        }
        cout<<"+"<<endl;
        cout<<setw(2)<<(dimY-i);

        for(int j=0; j<dimX;++j){
            cout<<"|"<<map[i][j];
        }
        cout<<"|"<<endl;
    }

    cout<<" ";
    for(int j=0;j<dimX;++j){
        cout<<"+-";
    }
    cout<<"+"<<endl;

    cout<<" ";
    for(int j=0; j<dimX; ++j){
        int digit = (j+1)/10;
        cout<<" ";
        if(digit==0)
            cout<<" ";
        else
            cout<<digit;
    }
    cout<<endl;

    cout<<" ";
    for(int j=0; j<dimX; ++j){
        cout<<" "<<(j+1)%10;
    }
    cout<<endl<<endl;
}

int Mars::getdimX(){
    return dimX;
}

int Mars::getDimY(){
    return dimY;
}

char Mars::getObject(int x, int y){
        char obj =map[dimY-y][x-1];
        return obj;
}

void Mars::setObject(int x, int y, char c){
    map[(dimY-y)][x-1] = c;
}

bool Mars::isEmpty(int x, int y){
    if (map[dimY-y][x-1] ==' ')
        return true;
    
    else
        return false;
}

void test4(){
    Mars mars;
    mars.setObject(1,1,'A');
    mars.setObject(15,1,'B');
    mars.setObject(15,5,'C');
    mars.setObject(1,5,'D');
    mars.display();
    cout<<"The object A should be at column 1 and row 1"<<endl;
    cout<<"The object B should be at column 15 and row 1"<<endl;
    cout<<"The object C should be at column 15 and row 5"<<endl;
    cout<<"The object D should be at column 1 and row 5"<<endl;

}

void test5(){
    Mars mars;
    mars.setObject(2,4,'Z');
    mars.setObject(10,3,' ');
    mars.display();

    cout << "Coordinate (2,4) is ";
    if ( mars.isEmpty(2,4) )
        cout << "empty.";
    else
        cout<<"not empty";
    cout<<endl;
    cout<<"Coordinate(10,3) is";
    if(mars.isEmpty(10,3))
        cout<<"Empty";
    else    
        cout<<"Not Empty";
    cout<<endl;
}

void test3(){
    Mars mars;
    mars.display();
    int x,y;
    char obj;
    x=1;y=1;
    obj = mars.getObject(x,y);
    cout<<"Object at column "<<x<<" and row "<<y<<" is ["<<obj<<"]"<<endl;
    x=15;y=5;
    obj = mars.getObject(x,y);
    cout<<"Object at column "<<x<<" and row "<<y<<" is ["<<obj<<"]"<<endl;
    x=5;y=2;
    obj = mars.getObject(x,y);
    cout<<"Object at column "<<x<<" and row "<<y<<" is ["<<obj<<"]"<<endl;
    x=10;y=4;
    obj = mars.getObject(x,y);
    cout<<"Object at column "<<x<<" and row "<<y<<" is ["<<obj<<"]"<<endl;
}

void test2(){
    Mars mars;
    cout<<mars.getdimX()<<" "<<mars.getDimY();
}
int main(){
    srand(time(NULL));
    //test3();
    //test4();
    test5();

    return 0;
}
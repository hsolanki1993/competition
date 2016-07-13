
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>

using namespace std;

//CadburyBar
class CadburyBar{
	int length;
	int breadth;
	
public:
	//Getting initial values of a bar
    CadburyBar(int l,int b):length(l),breadth(b){}
	
	//Getters
	int getLength(){return length;}
	int getBreadth(){return breadth;}
};

//Distributor
class Distributor{
private:
	vector<CadburyBar> carton;	//Carton full of different cadbury bars
	int children;				//Number of children who get served

public:
	//Initializer
	Distributor(vector<CadburyBar> recCarton):carton(recCarton),children(0){}
	
	//Set number of lucky childrens
	void distribute(){
		int length=0;
		int breadth=0;
		
		//Checkcardbury bars one by one and give that to a first child of a queue
		for(int i=0; i<carton.size();i++){
			
			//Getting length and breadth of a cadbury bar
			length = carton[i].getLength();
			breadth = carton[i].getBreadth();
			
			//Best case ever
			if(length == breadth){
				++children;
			}
			else{
				
				//Have to do something untill we get square bar
				while(length != breadth){
					
					//Cut bars in square and give that to a child
					if(breadth > length){
						breadth -= length;
					}
					else if(length > breadth){
						length -= breadth;
					}
					++children;
				}
				
				//Yuhhuu.. Finally got square one
				if(length == breadth){
					++children;
				}
			}
		}
	}
	
	//get number of children who got cadbury bar
	int get_nr_of_children(){ return children;}
	
};


int cadbury(int input1,int input2,int input3,int input4)
{
	int m,n,p,q;    //Taken variables specified by you, I think it's easy to link
	
	m=input1;
    n=input2;
    p=input3;
    q=input4;
	
	//Get a carton of cadbury bars
	vector<CadburyBar> carton;
	
	//Check what we got in carton
	for(int i=m; i<=n; ++i ){
		
		for (int j=p; j<=q; ++j ){
			CadburyBar single_bar(i,j);
			carton.push_back(single_bar);
		}
	}
	
	//Give carton to distributor
	Distributor distributor(carton);
	
	//Let distributor distribute them
	distributor.distribute();
	
	//Here is number of childrens who got served
    return	distributor.get_nr_of_children();
}
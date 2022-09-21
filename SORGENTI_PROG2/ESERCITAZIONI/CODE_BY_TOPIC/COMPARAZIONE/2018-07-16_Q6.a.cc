/*
 * ! Attention
 * Compile the program with the option: -Wno-write-strings
 * g++ -Wno-write-strings 2018-07-16_Q6.a.cc 
 */
#include <iostream>
#include <cstring>

using namespace std;

struct persona
{      
	char* nome;      
	int id; 
};

/*********COMPARE*PERSONS*FUNCTION*********/
int compare(persona p1, persona p2)
{
	int cmp = strcmp(p1.nome,p2.nome);
	
	if(cmp == 0 && p1.id == p2.id)
	{
		cout<<"#1: ";
		return (p1.id - p2.id); 
	}
	else if(cmp <= 0 && p1.id < p2.id)
	{
		cout<<"#2: ";		
		return (p1.id - p2.id); 
	}
	else
	{
		cout<<"#3: ";				
		return (p1.id - p2.id)+1;
	}
}
/******************************************/

int main(){
	persona p1;
	persona p2;

	/* test #1 */
	p1.nome = "Filippo";
	p1.id = 1998;
	p2.nome = "Filippo";
	p2.id = 1998;
	cout<<compare(p1,p2)<<endl;

	/* test #2 */
	p1.nome = "Filippo";
	p1.id = 1998;	
	p2.nome = "Filippo";
	p2.id = 2022;	
	cout<<compare(p1,p2)<<endl;

	/* test #2 */
	p1.nome = "Antonio";
	p1.id = 1998;	
	p2.nome = "Filippo";
	p2.id = 2022;	
	cout<<compare(p1,p2)<<endl;

	/* test 3 */
	p1.nome = "Filippo";
	p1.id = 1998;	
	p2.nome = "Antonio";
	p2.id = 1998;	
	cout<<compare(p1,p2)<<endl;

	/* test 3 */
	p1.nome = "Antonio";
	p1.id = 2022;	
	p2.nome = "Filippo";
	p2.id = 1998;	
	cout<<compare(p1,p2)<<endl;

	return 0;
}

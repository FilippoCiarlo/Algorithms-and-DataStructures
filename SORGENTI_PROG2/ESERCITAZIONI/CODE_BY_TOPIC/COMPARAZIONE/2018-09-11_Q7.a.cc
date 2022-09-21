#include <iostream>

using namespace std;

struct libro
{      
	char* autore;     
	char* titolo; 
};

/************COMPARE*BOOKS************/
// THIS IS THE BEST OF THE TWO
int compare(libro l1, libro l2)
{    
	if(strcmp(l1.autore,l2.autore) == 0)
    {
		if(strcmp(l1.titolo,l2.titolo) == 0)
			return strcmp(l1.titolo,l2.titolo);
        else if (strcmp(l1.titolo,l2.titolo) < 0)
			return strcmp(l1.titolo,l2.titolo);
	}
	else if(strcmp(l1.autore,l2.autore) < 0)
		return strcmp(l1.autore,l2.autore);

	return strcmp(l1.autore,l2.autore)+1;
}

/*
int compare(libro l1, libro l2)
{    
	if((strcmp(l1.autore,l2.autore) == 0) && (strcmp(l1.titolo,l2.titolo) == 0 || strcmp(l1.titolo,l2.titolo)))
			return strcmp(l1.titolo,l2.titolo);	
	if(strcmp(l1.autore,l2.autore) < 0)
		return strcmp(l1.autore,l2.autore);
	return strcmp(l1.autore,l2.autore)+1;
}
*/
/*****************************************/

int main()
{
	libro l1 = {"B", "A"};
	libro l2 = {"A", "B"};
	libro l3 = {"A", "A"};
	libro l4 = {"B", "B"};

	cout<<l1.autore<<":"<<l1.titolo<<" cmp "<<l1.autore<<":"<<l1.titolo<<" = ";
	cout<<compare(l1,l1)<<endl;

	cout<<l1.autore<<":"<<l1.titolo<<" cmp "<<l2.autore<<":"<<l2.titolo<<" = ";
	cout<<compare(l1,l2)<<endl;

	cout<<l1.autore<<":"<<l1.titolo<<" cmp "<<l3.autore<<":"<<l3.titolo<<" = ";
	cout<<compare(l1,l3)<<endl;

	cout<<l1.autore<<":"<<l1.titolo<<" cmp "<<l4.autore<<":"<<l4.titolo<<" = ";
	cout<<compare(l1,l4)<<endl;
	
	cout<<endl;
	cout<<l2.autore<<":"<<l2.titolo<<" cmp "<<l1.autore<<":"<<l1.titolo<<" = ";
	cout<<compare(l2,l1)<<endl;
	
	cout<<l2.autore<<":"<<l2.titolo<<" cmp "<<l2.autore<<":"<<l2.titolo<<" = ";
	cout<<compare(l2,l2)<<endl;
		
	cout<<l2.autore<<":"<<l2.titolo<<" cmp "<<l3.autore<<":"<<l3.titolo<<" = ";
	cout<<compare(l2,l3)<<endl;

	cout<<l2.autore<<":"<<l2.titolo<<" cmp "<<l4.autore<<":"<<l4.titolo<<" = ";
	cout<<compare(l2,l4)<<endl;
	return 0;
}

/*
1°CASO
compare(l1,l2) = 0	(autore l1 == autore l2) && (titolo l1 == titolo l2)

2°CASO
compare(l1,l2) < 0	(autore l1) < (autore l2) || [(autore l1 == autore l2) && (titolo l1 < titolo l2)]

3°CASO
compare(e1,e2) > 0	altrimenti

CASI:
(autore l1 == autore l2) && (titolo l1 == titolo l2)	1°CASO

(autore l1 == autore l2) && (titolo l1 < titolo l2)	2°CASO

(autore l1 < autore l2) && (titolo l1 == titolo l2)	2°CASO
(autore l1 < autore l2) && (titolo l1 < titolo l2)	2°CASO
(autore l1 < autore l2) && (titolo l1 > titolo l2)	2°CASO

(autore l1 == autore l2) && (titolo l1 > titolo l2)	3°CASO
(autore l1 > autore l2) && (titolo l1 == titolo l2)	3°CASO
(autore l1 > autore l2) && (titolo l1 > titolo l2)	3°CASO
(autore l1 > autore l2) && (titolo l1 < titolo l2)	3°CASO
*/
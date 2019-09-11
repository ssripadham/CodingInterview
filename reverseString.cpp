#include <iostream>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

void reverse( char *start, char *end )
{
    while( start < end )
    {
        char c = *start;
        *start++ = *end;
        *end-- = c;
    }
}

char *reverse_char( char *start )
{
    char *end = start;
    //Bit mask 1100 0000      1000 0000
    //If top 2 bits of the value = 10
    cout<<end<<" "<<start<<endl;
    while( (end[1] & 0xC0) == 0x80 ) end++;
    //reverse( start, end );
    while( start < end )
    {
        char c = *start;
        cout<<c<<endl;
        *start++ = *end;
        *end-- = c;
    }
    return( end+1 );
}

void reverse_string( char *string )
{
    char *end = string;
    while( *end ) end = reverse_char( end );
    reverse( string, end-1 );
}


void myReverse(char s[]){

	int i = 0, j = 0;

	while (s[i]) {
		if ( (s[i] & 0xc0) != 0x80) j++;
		i++;		
	}

	i = 0;
	cout<<j<<i<<endl;
	int c;
	while (i<j) {
		cout<<i<<" "<<j<<endl;
		if ((s[i] & 0xc0) == 0x80) { 
			i++ ; 
			continue;
		}


		if ((s[j] & 0xc0) == 0x80) { 
			j-- ; 
			continue;
		}
		
		cout<<"swap"<<endl;
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++; j--;
	}

}

int main() {
	char str[] = "உஈஇஆஅ";
	//char str[] = "abc";
	//reverse_string(str);
	//char str[] = "abc";
	myReverse(str);
	cout<<"str = "<<str<<endl;
	float f = 1.234567890123456789;
	cout<<f<<endl;
	//assert(string(str).compare("அஆஇஈஉ")==0);
	//"handles unicode characters";
}
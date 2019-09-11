#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

void reverse(char s[]){
	char tmp;
	int i,j;
	for (i=0, j = strlen(s)-1; i<j; i++,j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}

int main(){
	char s1[] = "tableau"; reverse(s1);
	assert(strcmp(s1,"uaelbat")==0);
	
	char s2[] = "";reverse(s1);
	assert(strcmp(s2,"")==0);

	char s3[] = "a"; reverse(s3);
	assert(strcmp(s3,"a")==0);


	char s4[] = "ab"; reverse(s4);
	assert(strcmp(s4,"ba")==0);
}
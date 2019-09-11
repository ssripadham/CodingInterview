http://wp.acm.org/bitmesra/2010/07/31/input-taking-strategies-2/

Use ifstream to read data from a file:

std::ifstream input("filename.ext");
If you really need to read line by line, then do this:

for( std::string line; getline( input, line );){...for each line in input...}
But you probably just need to extract coordinate pairs:

int x, y;
input >> x >> y;
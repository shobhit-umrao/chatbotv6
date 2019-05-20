

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
const int MAX_RESP = 2;
const std::string delim = "?!.;,";

typedef std::vector<std::string> vstring;

vstring find_match( std::string input );
void copy( char *array[], vstring &v );
void preprocess_input( std::string &str );
void UpperCase( std::string &str );
void cleanString( std::string &str );
bool isPunc(char c);

typedef struct {
	char *input;
	char *responses[MAX_RESP];
}record;

record KnowledgeBase[] = {
	{"WHAT IS PROLOG IN AI",
	{"In AI, Prolog is a programming language based on logic.",
	"In AI, Prolog is a programming language based on logic."}
	},
	
	{"WHAT IS YOUR NAME",
	{"MY NAME IS chatbot.",
		"i forgot :D..:D"}
	},

	{"HI", 
	{	"HI THERE!"
		"\n Copy Questions from below to skip typing,"
		"\n To Copy highlight and press Enter,"
		"\n Ctrl+V to Paste"
		"\n What is Prolog in AI?"
		"\n Which search method takes less memory?"
		"\n A star algorithm is based on which search method?"
		"\n What does a hybrid Bayesian network contain?"
		"\n What is a heuristic function?"
		"\n What is a top down parser?"
		"\n What is FOPL"
		"\n ************************"
		"\n OR simply type FOPL or bayes terms"
		"\n For building a Bayes model how many terms are required?"
		"\n Press Ctrl + C to EXIT",
		"HI THERE!"
		"\n Copy Questions from below to skip typing,"
		"\n To Copy highlight and press Enter,"
		"\n Ctrl+V to Paste"
		"\n What is Prolog in AI?"
		"\n Which search method takes less memory?"
		"\n A star algorithm is based on which search method?"
		"\n What does a hybrid Bayesian network contain?"
		"\n What is a heuristic function?"
		"\n What is a top down parser?"
		"\n What is FOPL"
		"\n For building a Bayes model how many terms are required?"
		"\n ************************"
		"\n OR simply type FOPL or bayes model"
		"\n Press Ctrl + C to EXIT"}
	},
	

	{"WHO ARE YOU",
	{"I'M AN A.I PROGRAM.",
	"I will answer some of the the AI related questions"}
	},
	
	{"WHICH SEARCH METHOD TAKES LESS MEMORY",
	{"The depth first search method takes less memory."
	"The depth first search method takes less memory.",}
	},
	
	
	
	
	{"LESS MEMORY",
	{"The depth first search method takes less memory."
	"The depth first search method takes less memory.",}
	},
	
	{"A STAR ALGORITHM IS BASED ON WHICH SEARCH METHOD",
	{"A* algorithm is based on best first search method, as it gives an idea of optimization and quick choose of path, and all characteristics lie in A* algorithm.",
	"A* algorithm is based on best first search method, as it gives an idea of optimization and quick choose of path, and all characteristics lie in A* algorithm."}
	},
	
	
	
	
	
	{"WHAT DOES A HYBRID BAYESIAN NETWORK CONTAIN",
	{"A hybrid Bayesian network contains both a discrete and continuous variables.",
	"A hybrid Bayesian network contains both a discrete and continuous variables."}
	},
	
	{"HYBRID BAYESIAN",
	{"A hybrid Bayesian network contains both a discrete and continuous variables.",
	"A hybrid Bayesian network contains both a discrete and continuous variables."}
	},
	
	{"BAYESIAN CONTAIN",
	{"A hybrid Bayesian network contains both a discrete and continuous variables.",
	"A hybrid Bayesian network contains both a discrete and continuous variables."}
	},
	
	{"WHAT IS A HEURISTIC FUNCTION",
	{"A heuristic function ranks alternatives, in search algorithms, at each branching step based on the information to decide which branch to follow.",
	"A heuristic function ranks alternatives, in search algorithms, at each branching step based on the information to decide which branch to follow."}
	},
	
	{"HEURISTIC FUNCTION",
	{"A heuristic function ranks alternatives, in search algorithms, at each branching step based on the information to decide which branch to follow.",
	"A heuristic function ranks alternatives, in search algorithms, at each branching step based on the information to decide which branch to follow."}
	},
	
	{"HEURISTIC",
	{"A heuristic function ranks alternatives, in search algorithms, at each branching step based on the information to decide which branch to follow.",
	"A heuristic function ranks alternatives, in search algorithms, at each branching step based on the information to decide which branch to follow."}
	},
	
	{"WHAT IS A TOP DOWN PARSER",
	{"A top-down parser begins by hypothesizing a sentence and successively predicting lower level constituents until individual pre-terminal symbols are written.",
	"A top-down parser begins by hypothesizing a sentence and successively predicting lower level constituents until individual pre-terminal symbols are written."}
	},
	
	{"TOP DOWN",
	{"A top-down parser begins by hypothesizing a sentence and successively predicting lower level constituents until individual pre-terminal symbols are written.",
	"A top-down parser begins by hypothesizing a sentence and successively predicting lower level constituents until individual pre-terminal symbols are written."}
	},
	
	{"PARSER",
	{"A top-down parser begins by hypothesizing a sentence and successively predicting lower level constituents until individual pre-terminal symbols are written.",
	"A top-down parser begins by hypothesizing a sentence and successively predicting lower level constituents until individual pre-terminal symbols are written."}
	},
	
	{"WHAT IS FOPL",
	{"FOPL stands for First Order Predicate Logic",
	"FOPL stands for First Order Predicate Logic"}
	},
	
	{"FOPL",
	{"FOPL stands for First Order Predicate Logic",
	"FOPL stands for First Order Predicate Logic"}
	},
	
	{"FOR BUILDING A BAYES MODEL HOW MANY TERMS ARE REQUIRED",
	{"For building a Bayes model in AI, three terms are required; \n1. Conditional probability \n2. unconditional probability.",
	"For building a Bayes model in AI, three terms are required; \n1. Conditional probability \n2.two unconditional probability."}
	},
	
	{"BAYES MODEL TERMS",
	{"For building a Bayes model in AI, three terms are required; \n1. conditional probability \n2. unconditional probability.",
	"For building a Bayes model in AI, three terms are required; \n1. conditional probability \n2. unconditional probability."}
	},
	
	{"BAYES TERMS",
	{"For building a Bayes model in AI, three terms are required; \n1. conditional probability \n2. unconditional probability.",
	"For building a Bayes model in AI, three terms are required; \n1. conditional probability \n2. unconditional probability."}
	}
	
	
	};

size_t nKnowledgeBaseSize = sizeof(KnowledgeBase)/sizeof(KnowledgeBase[0]);
int main()
{
	system("Color 02");
	cout << ("##############################################################") <<endl;
	cout << ("##                                                          ##") <<endl;
	cout << ("##                    Created By Shobhit                    ##") <<endl;
	cout << ("##     Simple Chat Bot to answer AI related questions       ##") <<endl;
	cout << ("##                                                          ##") <<endl;
	cout << ("##      Start by typing Hi and type your questions          ##") <<endl;
	cout << ("##############################################################") <<endl;
	
	srand((unsigned) time(NULL));

	std::string sInput = "";
	std::string sResponse = "";
	std::string sPreviousResponse = "";
	std::string sPreviousInput = "";

	while(1) 
	{
		std::cout << endl << "User>";
		sPreviousResponse = sResponse;
		sPreviousInput = sInput;
		std::getline(std::cin, sInput);
		preprocess_input(sInput);
		vstring responses = find_match(sInput);

		if ( sInput == sPreviousInput && sInput.length() > 0 ) 
		{
			std::cout << "I think its a repetition, isn't it ?'." << std::endl;
		}
		else if ( sInput == "BYE" ) 
		{
			std::cout << "It was nice talking to you, have a nice day !!" << std::endl;
			break;
		} 
		else if ( responses.size() == 0 ) 
		{
			std::cout << "I'M NOT SURE IF I HAVE LEARNT THIS YET." << std::endl;
		} 
		else 
		{
			int nSelection = rand() % responses.size();
			sResponse = responses[nSelection];
			if(sResponse == sPreviousResponse) 
			{
				responses.erase(responses.begin() + nSelection);
				nSelection = rand() % responses.size();
				sResponse = responses[nSelection];
			}
			std::cout << sResponse << std::endl;
		}
	}
	
	return 0;
}

void preprocess_input( std::string &str ) 
{
	cleanString(str);
	UpperCase(str);
}

vstring find_match(std::string input) 
{
	vstring result;
	for(int i = 0; i < nKnowledgeBaseSize; ++i) 
	{
		std::string keyWord(KnowledgeBase[i].input);
		if( input.find(keyWord) != std::string::npos ) 
		{
			copy( KnowledgeBase[i].responses, result );
			return result;
		}
	}
	return result;
}
void copy(char *array[], vstring &v) 
{
	for(int i = 0; i < MAX_RESP; ++i) 
	{
		if(array[i] != NULL) 
		{
			v.push_back(array[i]);
		} 
		else 
		{
			break;
		}
	}
}
void UpperCase( std::string &str ) 
{
	int len = str.length();
	for( int i = 0; i < len; i++ ) 
	{
		if ( str[i] >= 'a' && str[i] <= 'z' ) 
		{
			str[i] -= 'a' - 'A';
		}
	}
}
bool isPunc(char c) 
{
	return delim.find(c) != std::string::npos;
}
void cleanString( std::string &str ) 
{
	int len = str.length();
	std::string temp = "";

	char prevChar = 0;

	for(int i = 0; i < len; ++i) 
	{
		if(str[i] == ' ' && prevChar == ' ') 
		{
			continue;
		}

		else if(!isPunc(str[i])) 
		{
			temp += str[i];
		}

		prevChar = str[i];
	}
	str = temp;
}

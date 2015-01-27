// Effective C++::Third Edition::Item 2:p14
// Try to take a address of a class Effective static const
// "" Usuallly C++ requires us to provide a definition along with 
// the declaration, but class specific static consts of integral
// type ( int, char, bool ) are an exception to it until unless 
// we try to take the address. We can declare them without providing
// any definition. ""

class Game
{
public:
  static const int numTurns = 5; // const declartion 
  int score[numTurns];
};

const int Game::numTurns; // comment this line to get the error 

int main()
{
  Game object;
  const int * temp = &(object.numTurns);
  return 0;
}

// error looks somthing like
// EffectiveItem1.o: In function `main':
// EffectiveItem1.cxx:(.text+0x8): undefined reference to `Game::numTurns'
// collect2: error: ld returned 1 exit status

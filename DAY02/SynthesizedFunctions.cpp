#include <iostream>
using namespace std;


class GameBoard{
public:
    GameBoard()
    {
        std::cout << "GameBoard()\n";
    }

    GameBoard(const GameBoard&)
    {
        std::cout << "GameBoard(const GameBoard &)\n";
    }

    GameBoard& operator=(const GameBoard&){
        std::cout << "GameBoard::operator=()\n";
        return *this;
    }

    ~GameBoard() { std::cout << "~GameBoard()\n";}
};


class Game{
    GameBoard gb;

public:
    Game() {std::cout << "Game()\n";}

    Game(const Game &g): gb(g.gb){
        std::cout << "Game(const Game&)\n";
    }

    Game& operator=(const Game& g){
        gb = g.gb;
        std::cout<< "Game::operator=()\n";
        return *this;
    }


    class Other {};

    operator Other() const{
        std::cout << "Game::operator Other()\n";
        return Other();
    }

    ~Game() { cout << "~Game()\n";}
};


class Checkers : public Game{
public:
    Checkers() { std::cout << "Checkers()\n";}

    Checkers(const Checkers& c): Game(c){
        std::cout << "Checkers(const Checkers&c)\n";
    }

    Checkers& operator=(const Checkers& c){
        Game::operator=(c);
        std::cout << "Checkers::operator=()\n";
        return *this;
    }
};

class Chess : public Game{};

void f(Game::Other)
{

}

int main()
{
    Chess d1;
    Chess d2(d1);

}



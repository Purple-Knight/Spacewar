#include "Score.h"

void SetScore(Score* score, sf::RenderWindow* window)
{
    std::string tempo = getAssetsPath() + "arial.ttf";
    score->arial.loadFromFile(tempo);

	score->score = 0;

    score->idleScore.setFont(score->arial);
	score->idleScore.setCharacterSize(24);
    score->idleScore.setOrigin(sf::Vector2f(score->idleScore.getGlobalBounds().width / 2, score->idleScore.getGlobalBounds().height / 2));
	score->idleScore.setPosition(sf::Vector2f(sf::Vector2f(window->getSize().x / 2, 0)));
    score->idleScore.setString(std::to_string(score->score));

    score->idleGameOver.setFont(score->arial);
    score->idleGameOver.setCharacterSize(48);
    score->idleGameOver.setPosition(sf::Vector2f(sf::Vector2f(window->getSize().x / 2, (window->getSize().y / 2) - window->getSize().y / 10)));
    score->idleGameOver.setString("GAME OVER");
    score->idleGameOver.setOrigin(sf::Vector2f(score->idleGameOver.getGlobalBounds().width / 2, score->idleGameOver.getGlobalBounds().height/2));
}    


std::string getAppPath(void)
{
    char cExeFilePath[256];
    GetModuleFileNameA(NULL, cExeFilePath, 256);
    std::string exeFilePatch = cExeFilePath;
    int exeNamePos = exeFilePatch.find_last_of("\\/");
    std::string appPath = exeFilePatch.substr(0, exeNamePos + 1);
    return appPath;
}

std::string getAssetsPath(void)
{
    return getAppPath() + "Assets\\";
}

void ScoreUp(Score* score, int value)
{
    score->score += value;
    score->idleScore.setString(std::to_string(score->score));
}

void GameOver(Score* score, sf::RenderWindow* window)
{
    score->idleScore.setPosition(sf::Vector2f(window->getSize().x/2, window->getSize().y / 2));
    window->draw(score->idleScore);
    window->draw(score->idleGameOver);
}
#include "Score.h"

void SetScore(Score* score)
{
    std::string tempo = getAssetsPath() + "arial.ttf";
    bool isLoaded = score->arial.loadFromFile(tempo);

	score->score = 10;

    score->idleScore.setFont(score->arial);
	score->idleScore.setCharacterSize(24);
	score->idleScore.setPosition(sf::Vector2f(450, 0));
    score->idleScore.setString(std::to_string(score->score));
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
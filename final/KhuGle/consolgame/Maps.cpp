#include "Maps.h"

Map::Map() {

    mapLength = 0;    
    startData = NULL;
    lastData = NULL;

}


void Map::SaveData(const int mapContent[HEIGHT - 10][WIDTH], vector<Word>& gameWords, vector<int>& gameDir) {
    //map 저장
    memcpy(map, mapContent, sizeof(map));

    //단어를 list에 저장
    int previous = 0; 
    int current = 0;

    for (int i = 0; i < gameWords.size(); i++) {
        InsertItem(gameWords[i]);
        lastData->word.getWordLocation(gameDir[int(3)*i], gameDir[int(3) * i+1], gameDir[int(3) * i + 2]);
    }

    //단어의 방향 지정
}

void Map::InsertItem(Word item)
// item is in the list; length has been incremented.
{
    WordType* location;

    location = new WordType;
    location->word = item;

    if (startData == NULL) {
        startData = location;       
    }
    else {
        location->back = lastData;
        location->next = NULL;
        lastData->next = location;
    }

    lastData = location;
    mapLength++;
}

void Map::GetNextItem(bool& isEnd)
// Post:  Current position has been updated; item is current item.
{  
    if (currentWord == lastData) {
        isEnd = false;
    }
    else {
        currentWord = currentWord->next;
        isEnd = true;
    }
}

void Map::GetPreItem(bool& isEnd){
  
    if (currentWord == startData) {
        isEnd = false;
    }
    else {
        currentWord = currentWord->back;
        isEnd = true;
    }
}


Word Map::GetCurrentItem() {
    return currentWord->word;
}


void Map::SaveAnswer() {
    currentWord->word.answer = true;
}


Map::~Map()
// Class destructor
{
    MakeEmpty();
}

void Map::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    WordType* tempPtr;

    for (int i = 0; i < mapLength; i++) {
        tempPtr = startData;
        startData = startData->next;
        delete tempPtr;
    }

    mapLength = 0;
}


void Map::ResetList()
// Post: Current position has been initialized.
{
    currentWord = startData;
}
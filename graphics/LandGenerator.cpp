#include "Engine.h"
#include <set>
#include <map>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstring>

std::vector<std::pair<glm::vec3, std::set<std::pair<int, int>>::iterator>> CurrentLand;
std::set<std::pair<int, int>> LandSet;
std::map<std::pair<int, int>, bool> DontErase;
glm::vec3 CurrentPos;
bool Generate = false;
bool isPosCalculated = false;
std::thread *GenerationThread = nullptr;
std::mutex PosMutex, LandMutex, mPosChanged;
std::condition_variable cvPosChanged;
CubeShape* RefCube = nullptr;

void Generator()
{
    LandSet.clear();
    std::unique_lock<std::mutex> ul(mPosChanged);
    while(Generate)
    {
        PosMutex.lock();
        if(isPosCalculated)
        {
            PosMutex.unlock();
            cvPosChanged.wait(ul);
        }
        else
        {
            vec3 pos = CurrentPos;
            isPosCalculated = true;
            PosMutex.unlock();
            pos.x = (int)pos.x / 2;
            pos.z = (int)pos.z / 2;
            DontErase.clear();
            for(int x = -21; x <= 21; x++)
            {
                for(int z = -21; z <= 21; z++)
                {
                    int xPos = x + pos.x;
                    int zPos = z + pos.z;
                    auto itr = LandSet.find({xPos, zPos});
                    DontErase[{xPos,zPos}] = 1;
                    if(itr == LandSet.end())
                    {
                        LandMutex.lock();
                        itr = LandSet.insert({xPos, zPos}).first;
                        CurrentLand.push_back({glm::vec3(xPos * 2, 0.0f, zPos * 2), itr});
                        LandMutex.unlock();
                    }
                }
            }
            for(int i = 0; i < CurrentLand.size() && CurrentLand.size() > 2000; i++)
            {
                if(DontErase.find({(int)CurrentLand[i].first.x / 2, (int)CurrentLand[i].first.z / 2}) == DontErase.end())
                {
                    LandSet.erase(CurrentLand[i].second);
                    CurrentLand.erase(CurrentLand.begin() + i);
                    i--;
                }
            }
        }
    }
}
void LandGenerator::StartGeneration(const glm::vec3& InitialPos)
{
    if(Generate == true || GenerationThread != nullptr || CurrentLand.size() != 0)
    {  
        ClearLand();
    }
    CurrentPos = InitialPos;
    Generate = true;
    isPosCalculated = false;
    GenerationThread = new std::thread(Generator);
}
void LandGenerator::FlushLand(std::vector<CubeShape*> &land)
{
    if(RefCube == nullptr)
    {
        const char* sameface[6] = 
        {
            "grass-texture_1000x.jpeg",
            "grass-texture_1000x.jpeg",
            "grass-texture_1000x.jpeg",
            "grass-texture_1000x.jpeg",
            "grass-texture_1000x.jpeg",
            "grass-texture_1000x.jpeg"
        };
        RefCube = new CubeShape();
        RefCube->SetTexture(sameface);
    }
    LandMutex.lock();
    for(int i = 0; i < CurrentLand.size(); i++)
    {
        if(i < land.size())
        {
            if(land[i]->GetPosition() != CurrentLand[i].first)
            {
                land[i]->SetPosition(CurrentLand[i].first);
            }
        }
        else
        {
            CubeShape* c = new CubeShape();
            c->SetTexture(*RefCube);
            c->Translate(CurrentLand[i].first);
            land.push_back(c);
        }
    }
    LandMutex.unlock();
}
void LandGenerator::UpdatePosition(const glm::vec3& Pos)
{
    PosMutex.lock();
    CurrentPos = Pos;
    isPosCalculated = false;
    PosMutex.unlock();
    cvPosChanged.notify_all();
}
void LandGenerator::ClearLand()
{
    if(Generate)
    {
        Generate = false;
    }
    if(GenerationThread != nullptr)
    {
        cvPosChanged.notify_all();
        GenerationThread->join();
        delete GenerationThread;
        GenerationThread = nullptr;
    }
    if(RefCube != nullptr)
    {
        delete RefCube;
        RefCube = nullptr;
    }
    CurrentLand.clear();
    LandSet.clear();
}
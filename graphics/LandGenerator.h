#include "CubeShape.h"
#include <vector>

namespace LandGenerator
{
    void StartGeneration(const glm::vec3&);
    void FlushLand(std::vector<CubeShape*>&);
    void UpdatePosition(const glm::vec3&);
    void ClearLand();
}
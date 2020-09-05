// C++ includes
#include <string>

// Project includes
#include "LaptopCPU.hpp"

LaptopCPU::LaptopCPU(std::string brandName,
                     std::string modelName,
                     uint16_t generationNumber,
                     uint16_t numberOfCores,
                     float maxClockSpeedGHz)
  : brandName(brandName),
    modelName(modelName),
    platformName("Laptop"),
    generationNumber(generationNumber),
    numberOfCores(numberOfCores),
    maxClockSpeedGHz(maxClockSpeedGHz)
{
}

LaptopCPU::~LaptopCPU()
{
}

const std::string LaptopCPU::getBrand()
{
  return brandName;
}

const std::string LaptopCPU::getModel()
{
  return modelName;
}

const std::string LaptopCPU::getPlatform()
{
  return platformName;
}

const uint16_t LaptopCPU::getGeneration()
{
  return generationNumber;
}

const uint16_t LaptopCPU::getNumberOfCores()
{
  return numberOfCores;
}

const float LaptopCPU::getMaxClockSpeedGHz()
{
  return maxClockSpeedGHz;
}


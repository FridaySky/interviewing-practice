#include <string>

class Android : Computer
{
public:
  const std::string getBrand();
  const std::string getModel();
  const std::string getPlatform();
  CPU& getCPU();
  RAM& getRAM();
};


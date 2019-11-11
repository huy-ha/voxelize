#include <iostream>
#include <Voxelize.hpp>
#include <nlohmann/json.hpp>
using namespace std;
int main(int argc, char **argv)
{
    nlohmann::json j;
    VoxelMask mask(2);
    Voxelize(mask,j);
    cout << j.dump(4) << endl;
    return 0;
}
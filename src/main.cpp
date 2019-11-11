#include <iostream>
#include <Voxelize.hpp>
using namespace std;
int main(int argc, char **argv)
{
    VoxelMask mask(2);
    Voxelize(mask);
    return 0;
}
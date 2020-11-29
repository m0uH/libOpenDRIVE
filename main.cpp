#include "Lanes.h"
#include "Math.hpp"
#include "OpenDriveMap.h"
#include "Road.h"

#include <fstream>
#include <memory>
#include <stdio.h>
#include <vector>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("ERROR: too few arguments\n");
        return -1;
    }
    odr::OpenDriveMap odr(argv[1]);

    for (std::shared_ptr<odr::Road> road : odr.get_roads())
    {
        printf("road: %d\n", road->id);
        for (std::shared_ptr<odr::LaneSection> lanesec : road->get_lanesections())
        {
            std::vector<odr::LaneVertices> lane_vertices = lanesec->get_lane_vertices(0.1);
        }
    }
    printf("Finished\n");

    return 0;
}

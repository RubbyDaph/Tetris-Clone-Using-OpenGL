#ifndef Physics_header
#define Physics_header

#include <Patterns.h>
#include <VAO.h>
#include <iostream>

inline int   Random    = std::rand() % 7 + 1;
inline float rep       = 0.f;
inline float side_move = 0.f;
inline int   angle     = 0;
// 0 - facing up
// 90 - facing right
// 180 - facing down
// 270 - facing left

inline static std::array<glm::vec4, 10> positions;

inline static std::array<std::array<int , 10>, 20> Collision_Array;

enum pattern_type
{
    IShape =    1,
    OShape, //  2
    JShape, //  3
    LShape, //  4
    TShape, //  5
    SShape, //  6
    ZShape  //  7
};


enum vertex_pos
{
    LowerLeft,
    LowerRight,
    UpperRight,
    UpperLeft
};

enum Dot_positions
{         //
    dot_0,//
    dot_1,//
    dot_2,//
    dot_3,//
    dot_4,//
    dot_5,//
    dot_6,//
    dot_7,//
    dot_8,//
    dot_9,//
};


namespace Oshape
{
    void Update_pos(Vertex vertices[], const pattern& temp, float& rep);
    void Update_Collision_Array();

    bool Check_Left();
    bool Check_Right();
    bool Check_below();
    bool Check_Collision_Below();
    bool Check_Collision_Left();
    bool Check_Collision_Right();
}

namespace Ishape
{
    void Update_pos(Vertex vertices[], const pattern& temp, float& rep);
    void Update_Collision_Array();

    bool Check_Left(bool For_Rotation);
    bool Check_Right(bool For_Rotation);
    bool Check_below();
    bool Check_Collision_Below();
    bool Check_Collision_Left();
    bool Check_Collision_Right();
    bool Check_Ceiling();
}

namespace Jshape
{
    void Update_pos(Vertex vertices[], const pattern& temp, float& rep);
    void Update_Collision_Array();

    bool Check_Left(bool For_Rotation);
    bool Check_Right(bool For_Rotation);
    bool Check_below();
    bool Check_Collision_Below();
    bool Check_Collision_Left();
    bool Check_Collision_Right();
}

namespace Lshape
{
    void Update_pos(Vertex vertices[], const pattern& temp, float& rep);
    void Update_Collision_Array();

    bool Check_Left(bool For_Rotation);
    bool Check_Right(bool For_Rotation);
    bool Check_below();
    bool Check_Collision_Below();
    bool Check_Collision_Left();
    bool Check_Collision_Right();
}

namespace Tshape
{
    void Update_pos(Vertex vertices[], const pattern& temp, float& rep);
    void Update_Collision_Array();

    bool Check_Left(bool For_Rotation);
    bool Check_Right(bool For_Rotation);
    bool Check_below();
    bool Check_Collision_Below();
    bool Check_Collision_Left();
    bool Check_Collision_Right();
}

namespace Sshape
{
    void Update_pos(Vertex vertices[], const pattern& temp, float& rep);
    void Update_Collision_Array();

    bool Check_Left(bool For_Rotation);
    bool Check_Right(bool For_Rotation);
    bool Check_below();
    bool Check_Collision_Below();
    bool Check_Collision_Left();
    bool Check_Collision_Right();
}

namespace Zshape
{
    void Update_pos(Vertex vertices[], const pattern& temp, float& rep);
    void Update_Collision_Array();

    bool Check_Left(bool For_Rotation);
    bool Check_Right(bool For_Rotation);
    bool Check_below();
    bool Check_Collision_Below();
    bool Check_Collision_Left();
    bool Check_Collision_Right();
}

bool Check_All_Left();
bool Check_All_Right();
bool Check_All_Left_Rotation();
bool Check_All_Right_Rotation();
bool Check_All_Below();
bool Check_All_Collision_Below();
bool Check_All_Collision_Left();
bool Check_All_Collision_Right();
void Update_Instance_matrix(std::vector<glm::mat4>& Instance_matrix, int& amount);
void Update_Ground();

void Print_Ground();

#endif

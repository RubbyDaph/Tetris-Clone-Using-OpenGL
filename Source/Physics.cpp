#include <Physics.h>

//======================================Shape Area=========================================//

//--------------------------------------OShape---------------------------------------------//
bool Oshape::Check_below()
{
    using enum Dot_positions;
    bool Check_below =(positions[dot_4].y == 0.f  && positions[dot_5].y == 0.f)||
                      (positions[dot_5].y == 0.f  && positions[dot_6].y == 0.f);
    return Check_below;
}
bool Oshape::Check_Left()
{
    using enum Dot_positions;
    bool Check_sides=(positions[dot_0].x == 0 && positions[dot_4].x == 0);
    return Check_sides;
}
bool Oshape::Check_Right()
{
    using enum Dot_positions;
    bool Check_sides=(positions[dot_1].x == 330 && positions[dot_6].x == 330);
    return Check_sides;
}
bool Oshape::Check_Collision_Below()
{
    bool Check_Collision_Below =
       (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f + 1)][(int)(positions[dot_2].x/33.f)] == 1||
        Collision_Array[(int)((627.f - positions[dot_7].y)/33.f + 1)][(int)(positions[dot_7].x/33.f)] == 1||
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f + 1)][(int)(positions[dot_4].x/33.f)] == 1||
        Collision_Array[(int)((627.f - positions[dot_5].y)/33.f + 1)][(int)(positions[dot_5].x/33.f)] == 1);
    return Check_Collision_Below;
}
bool Oshape::Check_Collision_Left()
{
    bool Check_Collision_Below =
       (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) - 1] == 1||
        Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) - 1] == 1||
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
        Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1);
    return Check_Collision_Below;
}
bool Oshape::Check_Collision_Right()
{
    bool Check_Collision_Below =
       (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) + 1] == 1||
        Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) + 1] == 1||
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
        Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1);
    return Check_Collision_Below;
}


void Oshape::Update_pos(Vertex vertices[], const pattern& temp,float& rep)
{
    positions[dot_0] = temp.Facing_up[0] * glm::vec4(vertices[UpperLeft].coordinates, 0.f, 1.f);
    positions[dot_1] = temp.Facing_up[1] * glm::vec4(vertices[UpperRight].coordinates,0.f, 1.f);
    positions[dot_2] = temp.Facing_up[2] * glm::vec4(vertices[UpperLeft].coordinates, 0.f, 1.f);
    positions[dot_3] = temp.Facing_up[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f, 1.f);
    positions[dot_4] = temp.Facing_up[2] * glm::vec4(vertices[LowerLeft].coordinates, 0.f, 1.f);
    positions[dot_5] = temp.Facing_up[3] * glm::vec4(vertices[LowerLeft].coordinates, 0.f, 1.f);
    positions[dot_6] = temp.Facing_up[3] * glm::vec4(vertices[LowerRight].coordinates,0.f, 1.f);
    positions[dot_7] = temp.Facing_up[3] * glm::vec4(vertices[UpperLeft].coordinates,0.f, 1.f);
    for (int i = 0 ; i < 8; i++)
    {
        positions[i] =  glm::translate(glm::mat4(1.f) , glm::vec3(side_move , -33.f*rep, 0.f )) * positions[i];
    }
}

void Oshape::Update_Collision_Array()
{
    Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f)] = 1;
    Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f)] = 1;
    Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
    Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
}


//--------------------------------------IShape---------------------------------------------//
bool Ishape::Check_below()
{
    if (angle == 0 || angle == 180)
    {
        using enum Dot_positions;
        bool Check_below =(positions[dot_2].y  == 0.f && positions[dot_3].y == 0.f)||
                          (positions[dot_3].y  == 0.f && positions[dot_4].y == 0.f)||
                          (positions[dot_4].y  == 0.f && positions[dot_5].y == 0.f)||
                          (positions[dot_5].y  == 0.f && positions[dot_6].y == 0.f);
        return Check_below;
    }
    else
    {
        using enum Dot_positions;
        bool Check_below =(positions[dot_4].y  == 0.f && positions[dot_5].y == 0.f)||
                          (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
        return Check_below;
    }
}
bool Ishape::Check_Left(bool For_Rotation)
{
    if (!For_Rotation)
    {
        if (angle == 0 || angle == 180)
        {
        bool check_side = (positions[dot_0].x == 0.f && positions[dot_2].x == 0.f);
        return check_side;
        }
        else
        {
        bool check_side = (positions[dot_0].x == 0 && positions[dot_8].x == 0);
        return check_side;
        }
    }
    else
    {
        if (angle == 0 || angle == 180)
        {
            bool check_side = (positions[dot_0].x == -33.f && positions[dot_2].x == -33.f)||
                              (positions[dot_3].x == -33.f);
            return check_side;
        }
        else
        {
            bool check_side = (positions[dot_0].x == -33.f && positions[dot_8].x == -33.f);
            return check_side;
        }
    }
}
bool Ishape::Check_Right(bool For_Rotation)
{
    if (!For_Rotation)
    {
        if (angle == 0 || angle == 180)
        {
            bool check_side = (positions[dot_1].x == 330.f && positions[dot_6].x == 330.f);
            return check_side;
        }
        else
        {
            bool check_side =(positions[dot_1].x == 330 && positions[dot_9].x == 330);
            return check_side;
        }
    }
    else
    {
        if (angle == 0 || angle == 180)
        {
            bool check_side = (positions[dot_1].x == 363.f && positions[dot_6].x == 363.f)||
                              (positions[dot_5].x == 363.f);
            return check_side;
        }
        else
        {
            bool check_side =(positions[dot_1].x == 363.f && positions[dot_9].x == 363.f);
            return check_side;
        }
    }
}
bool Ishape::Check_Collision_Below()
{
    if (angle == 0 || angle == 180)
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f + 1)][(int)(positions[dot_2].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_3].y)/33.f + 1)][(int)(positions[dot_3].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_4].y)/33.f + 1)][(int)(positions[dot_4].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_5].y)/33.f + 1)][(int)(positions[dot_5].x/33.f)] == 1);
        return Check_Collision_Below;
    }
    else
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f + 1)][(int)(positions[dot_2].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_4].y)/33.f + 1)][(int)(positions[dot_4].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_6].y)/33.f + 1)][(int)(positions[dot_6].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_8].y)/33.f + 1)][(int)(positions[dot_8].x/33.f)] == 1);
        return Check_Collision_Below;
    }
}
bool Ishape::Check_Collision_Left()
{
    if (angle == 0 || angle == 180)
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1);
        return Check_Collision_Below;
    }
    else
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
        return Check_Collision_Below;
    }
}
bool Ishape::Check_Collision_Right()
{
    if (angle == 0 || angle == 180)
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1);
        return Check_Collision_Below;
    }
    else
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
        return Check_Collision_Below;
    }
}


void Ishape::Update_pos(Vertex vertices[], const pattern& temp, float& rep)
{
    using enum Dot_positions;
    switch (angle)
    {
    case 0:
        positions[dot_0] = temp.Facing_up[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_up[3] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_up[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_3] = temp.Facing_up[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_up[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_up[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_up[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_up[3] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        break;
    case 90:
        positions[dot_0] = temp.Facing_right[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_right[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_right[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_3] = temp.Facing_right[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_right[1] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_5] = temp.Facing_right[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_right[2] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_7] = temp.Facing_right[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_right[3] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_9] = temp.Facing_right[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 180:
        positions[dot_0] = temp.Facing_down[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_down[3] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_down[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_3] = temp.Facing_down[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_down[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_down[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_down[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_down[3] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        break;
    case 270:
        positions[dot_0] = temp.Facing_left[0] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_1] = temp.Facing_left[0] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_2] = temp.Facing_left[0] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_left[0] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_4] = temp.Facing_left[1] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_left[1] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_6] = temp.Facing_left[2] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_left[2] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_8] = temp.Facing_left[3] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_9] = temp.Facing_left[3] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        break;
    }

    for (int i = 0 ; i < 10; i++)
    {
        positions[i] =  glm::translate(glm::mat4(1.f) , glm::vec3(side_move , -33.f*rep, 0.f )) * positions[i];
    }
}

void Ishape::Update_Collision_Array()
{
    if (angle == 0 || angle == 180)
    {
        Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
    }
    else
    {
        Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
    }
}

bool Ishape::Check_Ceiling()
{
    if (Random != IShape)
    {
        return false;
    }
    if (angle == 90 || angle == 270)
    {
        bool ceiling = (positions[dot_2].y == 660 && positions[dot_3].y == 660);
        return ceiling;
    }
    return false;
}


//--------------------------------------JShape---------------------------------------------//
bool Jshape::Check_below()
{
    using enum Dot_positions;
    switch (angle)
    {
    case 0:
        {
            bool Check_below_up =(positions[dot_6].y  == 0.f && positions[dot_7].y == 0.f)||
                                 (positions[dot_7].y  == 0.f && positions[dot_8].y == 0.f)||
                                 (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
            return Check_below_up;
            break;
        }
    case 90:
        {
            bool Check_below_right =(positions[dot_4].y  == 0.f && positions[dot_5].y == 0.f)||
                                    (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
            return Check_below_right;
            break;
        }
    case 180:
        {
            bool Check_below_down = (positions[dot_4].y == 0.f && positions[dot_5].y == 0.f) ||
                (positions[dot_5].y == 0.f && positions[dot_6].y == 0.f) ||
                (positions[dot_7].y == 0.f && positions[dot_8].y == 0.f) ||
                (positions[dot_9].y == 0.f && positions[dot_9].y == 0.f);
            return Check_below_down;
            break;
        }
    case 270:
        {
            bool Check_below_left = (positions[dot_7].y == 0.f && positions[dot_8].y == 0.f) ||
                                    (positions[dot_8].y == 0.f && positions[dot_9].y == 0.f);
            return Check_below_left;
            break;
        }
    }
}
bool Jshape::Check_Left(bool For_Rotation)
{
    using enum Dot_positions;
    if (!For_Rotation)
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_0].x == 0.f && positions[dot_6].x == 0.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_0].x == 0.f && positions[dot_8].x == 0.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_0].x == 0.f && positions[dot_4].x == 0.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_4].x == 0.f && positions[dot_7].x == 0.f);
                return Check_sides;
            }
        }
    }
    else
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_0].x == -33.f && positions[dot_6].x == -33.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_0].x == -33.f && positions[dot_8].x == -33.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_0].x == -33.f && positions[dot_4].x == -33.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_4].x == -33.f && positions[dot_7].x == -33.f);
                return Check_sides;
            }
        }
    }
}
bool Jshape::Check_Right(bool For_Rotation)
{
    using enum Dot_positions;
    if (!For_Rotation)
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_5].x == 330.f && positions[dot_9].x == 330.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_2].x == 330.f && positions[dot_5].x == 330.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_3].x == 330.f && positions[dot_9].x == 330.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_1].x == 330.f && positions[dot_9].x == 330.f);
                return Check_sides;
            }
        }
    }
    else
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_5].x == 363.f && positions[dot_9].x == 363.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_2].x == 363.f && positions[dot_5].x == 363.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_3].x == 363.f && positions[dot_9].x == 363.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_1].x == 363.f && positions[dot_9].x == 363.f);
                return Check_sides;
            }
        }
    }
}
bool Jshape::Check_Collision_Below()
{
    switch (angle)
    {
    case 0:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f) + 1][(int)(positions[dot_2].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f) + 1][(int)(positions[dot_7].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    case 90:
        {
            bool Check_Collison =
                (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f) + 1][(int)(positions[dot_3].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_4].y)/33.f) + 1][(int)(positions[dot_4].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collison;
            break;
        }
    case 180:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_4].y)/33.f) + 1][(int)(positions[dot_4].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_5].y)/33.f) + 1][(int)(positions[dot_5].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    case 270:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f) + 1][(int)(positions[dot_2].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_5].y)/33.f) + 1][(int)(positions[dot_5].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f) + 1][(int)(positions[dot_7].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    }
}
bool Jshape::Check_Collision_Left()
{
    switch (angle)
    {
    case 0:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 90:
        {
            bool Check_Collison =
                (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collison;
            break;
        }
    case 180:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 270:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    }
}
bool Jshape::Check_Collision_Right()
{
    switch (angle)
    {
    case 0:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 90:
        {
            bool Check_Collison =
                (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collison;
            break;
        }
    case 180:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 270:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    }
}


void Jshape::Update_pos(Vertex vertices[], const pattern& temp, float& rep)
{
    using enum Dot_positions;
    switch (angle)
    {
    case 0:
        positions[dot_0] = temp.Facing_up[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_up[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_up[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_3] = temp.Facing_up[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_up[3] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_5] = temp.Facing_up[3] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_up[1] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_7] = temp.Facing_up[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_up[3] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_9] = temp.Facing_up[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 90:
        positions[dot_0] = temp.Facing_right[1] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_right[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_right[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_right[1] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_4] = temp.Facing_right[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_right[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_right[2] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_7] = temp.Facing_right[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_right[3] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_9] = temp.Facing_right[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 180:
        positions[dot_0] = temp.Facing_down[3] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_down[3] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_down[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_down[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_down[3] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_5] = temp.Facing_down[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_down[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_down[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_down[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_9] = temp.Facing_down[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 270:
        positions[dot_0] = temp.Facing_left[3] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_1] = temp.Facing_left[3] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_2] = temp.Facing_left[3] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_left[3] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_4] = temp.Facing_left[0] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_left[0] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_6] = temp.Facing_left[1] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_7] = temp.Facing_left[0] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_left[0] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_9] = temp.Facing_left[1] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        break;
    }

    for (int i = 0 ; i < 10; i++)
    {
        positions[i] =  glm::translate(glm::mat4(1.f) , glm::vec3(side_move  , -33.f*rep, 0.f )) * positions[i];
    }
    //std::cout<< " dot_1 "<< positions[dot_1].x << " dot_4 " << positions[dot_4].x << " dot_8 " << positions[dot_8].x << std::endl;
}

void Jshape::Update_Collision_Array()
{
    switch (angle)
    {
    case 0:
        Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    case 90:
        Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    case 180:
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    case 270:
        Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    }
}


//--------------------------------------LShape---------------------------------------------//
bool Lshape::Check_below()
{
    using enum Dot_positions;
    switch (angle)
    {
    case 0:
        {
            bool Check_below_up =(positions[dot_6].y  == 0.f && positions[dot_7].y == 0.f)||
                                 (positions[dot_7].y  == 0.f && positions[dot_8].y == 0.f)||
                                 (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
            return Check_below_up;
            break;
        }
    case 90:
        {
            bool Check_below_right =(positions[dot_7].y  == 0.f && positions[dot_8].y == 0.f)||
                                    (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
            return Check_below_right;
            break;
        }
    case 180:
        {
            bool Check_below_down = (positions[dot_5].y == 0.f && positions[dot_6].y == 0.f) ||
                                    (positions[dot_6].y == 0.f && positions[dot_7].y == 0.f) ||
                                    (positions[dot_8].y == 0.f && positions[dot_9].y == 0.f);
            return Check_below_down;
            break;
        }
    case 270:
        {
            bool Check_below_left = (positions[dot_3].y == 0.f && positions[dot_4].y == 0.f) ||
                                    (positions[dot_8].y == 0.f && positions[dot_9].y == 0.f);
            return Check_below_left;
            break;
        }
    }
}
bool Lshape::Check_Left(bool For_Rotation)
{
    using enum Dot_positions;
    if (!For_Rotation)
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_2].x == 0.f && positions[dot_6].x == 0.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_0].x == 0.f && positions[dot_7].x == 0.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_0].x == 0.f && positions[dot_8].x == 0.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_0].x == 0.f && positions[dot_3].x == 0.f);
                return Check_sides;
            }
        }
    }
    else
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_2].x == -33.f && positions[dot_6].x == -33.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_0].x == -33.f && positions[dot_7].x == -33.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_0].x == -33.f && positions[dot_8].x == -33.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_0].x == -33.f && positions[dot_3].x == -33.f);
                return Check_sides;
            }
        }
    }
}
bool Lshape::Check_Right(bool For_Rotation)
{
    using enum Dot_positions;
    if (!For_Rotation)
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_1].x == 330.f && positions[dot_9].x == 330.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_6].x == 330.f && positions[dot_9].x == 330.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_3].x == 330.f && positions[dot_7].x == 330.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_2].x == 330.f && positions[dot_9].x == 330.f);
                return Check_sides;
            }
        }
    }
    else
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_1].x == 363.f && positions[dot_9].x == 363.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_6].x == 363.f && positions[dot_9].x == 363.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_3].x == 363.f && positions[dot_7].x == 363.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_2].x == 363.f && positions[dot_9].x == 363.f);
                return Check_sides;
            }
        }
    }
}
bool Lshape::Check_Collision_Below()
{
    switch (angle)
    {
    case 0:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_4].y)/33.f) + 1][(int)(positions[dot_4].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f) + 1][(int)(positions[dot_7].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    case 90:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f) + 1][(int)(positions[dot_2].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_4].y)/33.f) + 1][(int)(positions[dot_4].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f) + 1][(int)(positions[dot_7].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    case 180:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_4].y)/33.f) + 1][(int)(positions[dot_4].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_5].y)/33.f) + 1][(int)(positions[dot_5].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    case 270:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f) + 1][(int)(positions[dot_3].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_4].y)/33.f) + 1][(int)(positions[dot_4].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    }
}
bool Lshape::Check_Collision_Left()
{
    switch (angle)
    {
    case 0:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 90:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 180:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 270:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    }
}
bool Lshape::Check_Collision_Right()
{
    switch (angle)
    {
    case 0:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 90:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 180:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 270:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    }
}


void Lshape::Update_pos(Vertex vertices[], const pattern& temp, float& rep)
{
    using enum Dot_positions;
    switch (angle)
    {
    case 0:
        positions[dot_0] = temp.Facing_up[3] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_up[3] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_up[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_3] = temp.Facing_up[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_up[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_up[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_up[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_7] = temp.Facing_up[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_up[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_9] = temp.Facing_up[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 90:
        positions[dot_0] = temp.Facing_right[0] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_1] = temp.Facing_right[0] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_2] = temp.Facing_right[0] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_right[0] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_4] = temp.Facing_right[1] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_right[1] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_6] = temp.Facing_right[3] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_right[2] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_right[2] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_9] = temp.Facing_right[3] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        break;
    case 180:
        positions[dot_0] = temp.Facing_down[2] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_down[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_down[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_down[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_down[2] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_5] = temp.Facing_down[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_down[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_down[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_down[3] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_9] = temp.Facing_down[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 270:
        positions[dot_0] = temp.Facing_left[3] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_1] = temp.Facing_left[3] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_2] = temp.Facing_left[2] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_3] = temp.Facing_left[3] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_left[3] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_5] = temp.Facing_left[2] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_6] = temp.Facing_left[1] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_left[1] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_8] = temp.Facing_left[0] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_9] = temp.Facing_left[0] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        break;
    }

    for (int i = 0 ; i < 10; i++)
    {
        positions[i] =  glm::translate(glm::mat4(1.f) , glm::vec3(side_move , -33.f*rep, 0.f )) * positions[i];
    }
}

void Lshape::Update_Collision_Array()
{
    switch (angle)
    {
    case 0:
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    case 90:
        Collision_Array[(int)((627.f - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    case 180:
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    case 270:
        Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    }
}


//--------------------------------------TShape---------------------------------------------//

bool Tshape::Check_below()
{
    using enum Dot_positions;
    switch (angle)
    {
    case 0:
        {
            bool Check_below_up =(positions[dot_6].y  == 0.f && positions[dot_7].y == 0.f)||
                                 (positions[dot_7].y  == 0.f && positions[dot_8].y == 0.f)||
                                 (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
            return Check_below_up;
            break;
        }
    case 90:
        {
            bool Check_below_right =(positions[dot_6].y  == 0.f && positions[dot_7].y == 0.f)||
                                    (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
            return Check_below_right;
            break;
        }
    case 180:
        {
            bool Check_below_down = (positions[dot_4].y == 0.f && positions[dot_5].y == 0.f) ||
                                    (positions[dot_6].y == 0.f && positions[dot_7].y == 0.f) ||
                                    (positions[dot_8].y == 0.f && positions[dot_9].y == 0.f);
            return Check_below_down;
            break;
        }
    case 270:
        {
            bool Check_below_left = (positions[dot_5].y == 0.f && positions[dot_6].y == 0.f) ||
                                    (positions[dot_8].y == 0.f && positions[dot_9].y == 0.f);
            return Check_below_left;
            break;
        }
    }
}
bool Tshape::Check_Left(bool For_Rotation)
{
    using enum Dot_positions;
    if (!For_Rotation)
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_2].x == 0.f && positions[dot_6].x == 0.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_0].x == 0.f && positions[dot_8].x == 0.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_0].x == 0.f && positions[dot_4].x == 0.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_2].x == 0.f && positions[dot_5].x == 0.f);
                return Check_sides;
            }
        }
    }
    else
    {
        switch (angle)
        {
        case 0:
            {
            bool Check_sides =(positions[dot_2].x == -33.f && positions[dot_6].x == -33.f);
            return Check_sides;
            }
        case 90:
            {
            bool Check_sides =(positions[dot_0].x == -33.f && positions[dot_8].x == -33.f);
            return Check_sides;
            }
        case 180:
            {
            bool Check_sides =(positions[dot_0].x == -33.f && positions[dot_4].x == -33.f);
            return Check_sides;
            }
        case 270:
            {
            bool Check_sides =(positions[dot_2].x == -33.f && positions[dot_5].x == -33.f);
            return Check_sides;
            }
        }
    }
}
bool Tshape::Check_Right(bool For_Rotation)
{
    using enum Dot_positions;
    if (!For_Rotation)
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_5].x == 330.f && positions[dot_9].x == 330.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_4].x == 330.f && positions[dot_7].x == 330.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_3].x == 330.f && positions[dot_7].x == 330.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_1].x == 330.f && positions[dot_9].x == 330.f);
                return Check_sides;
            }
        }
    }
    else
    {
        switch (angle)
        {
        case 0:
            {
                bool Check_sides =(positions[dot_5].x == 363.f && positions[dot_9].x == 363.f);
                return Check_sides;
            }
        case 90:
            {
                bool Check_sides =(positions[dot_4].x == 363.f && positions[dot_7].x == 363.f);
                return Check_sides;
            }
        case 180:
            {
                bool Check_sides =(positions[dot_3].x == 363.f && positions[dot_7].x == 363.f);
                return Check_sides;
            }
        case 270:
            {
                bool Check_sides =(positions[dot_1].x == 363.f && positions[dot_9].x == 363.f);
                return Check_sides;
            }
        }
    }
}
bool Tshape::Check_Collision_Below()
{
    switch (angle)
    {
    case 0:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_3].y)/33.f) + 1][(int)(positions[dot_3].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_7].y)/33.f) + 1][(int)(positions[dot_7].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    case 90:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_2].y)/33.f) + 1][(int)(positions[dot_2].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_5].y)/33.f) + 1][(int)(positions[dot_5].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    case 180:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_4].y)/33.f) + 1][(int)(positions[dot_4].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_5].y)/33.f) + 1][(int)(positions[dot_5].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    case 270:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_3].y)/33.f) + 1][(int)(positions[dot_3].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_5].y)/33.f) + 1][(int)(positions[dot_5].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
            return Check_Collision_Below;
            break;
        }
    }
}
bool Tshape::Check_Collision_Left()
{
    switch (angle)
    {
    case 0:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 90:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 180:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 270:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
            return Check_Collision_Below;
            break;
        }
    }
}
bool Tshape::Check_Collision_Right()
{
    switch (angle)
    {
    case 0:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 90:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 180:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    case 270:
        {
            bool Check_Collision_Below =
                (Collision_Array[(int)((627 - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
                 Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
            return Check_Collision_Below;
            break;
        }
    }
}


void Tshape::Update_pos(Vertex vertices[], const pattern& temp, float& rep)
{
    using enum Dot_positions;
    switch (angle)
    {
    case 0:
        positions[dot_0] = temp.Facing_up[3] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_up[3] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_up[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_3] = temp.Facing_up[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_up[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_up[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_up[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_7] = temp.Facing_up[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_up[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_9] = temp.Facing_up[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 90:
        positions[dot_0] = temp.Facing_right[0] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_1] = temp.Facing_right[0] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_2] = temp.Facing_right[0] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_right[0] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_4] = temp.Facing_right[3] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_5] = temp.Facing_right[1] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_right[1] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_7] = temp.Facing_right[3] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_8] = temp.Facing_right[2] * glm::vec4(vertices[LowerLeft].coordinates,0.f , 1.f);
        positions[dot_9] = temp.Facing_right[2] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        break;
    case 180:
        positions[dot_0] = temp.Facing_down[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_down[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_down[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_down[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_down[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_5] = temp.Facing_down[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_down[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_down[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_down[3] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_9] = temp.Facing_down[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 270:
        positions[dot_0] = temp.Facing_left[2] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_1] = temp.Facing_left[2] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_2] = temp.Facing_left[3] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_left[1] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_left[1] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_5] = temp.Facing_left[3] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_left[3] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_7] = temp.Facing_left[1] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_8] = temp.Facing_left[0] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_9] = temp.Facing_left[0] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        break;
    }

    for (int i = 0 ; i < 10; i++)
    {
        positions[i] =  glm::translate(glm::mat4(1.f) , glm::vec3(side_move  , -33.f*rep, 0.f )) * positions[i];
    }
}

void Tshape::Update_Collision_Array()
{
    switch (angle)
    {
    case 0:
        Collision_Array[(int)((627 - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    case 90:
        Collision_Array[(int)((627 - positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    case 180:
        Collision_Array[(int)((627 - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    case 270:
        Collision_Array[(int)((627 - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627 - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
        break;
    }
}

//--------------------------------------SShape---------------------------------------------//

bool Sshape::Check_below()
{
    using enum Dot_positions;
    if (angle == 0 || angle == 180)
    {
        bool Check_below =(positions[dot_5].y  == 0.f && positions[dot_6].y == 0.f)||
                             (positions[dot_7].y  == 0.f && positions[dot_8].y == 0.f)||
                             (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
        return Check_below;
    }
    else
    {
        bool Check_below =(positions[dot_5].y  == 0.f && positions[dot_6].y == 0.f)||
                          (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
        return Check_below;
    }
}
bool Sshape::Check_Left(bool For_Rotation)
{
    using enum Dot_positions;
    if (!For_Rotation)
    {
        if (angle == 0 || angle == 180)
        {
            bool Check_sides = (positions[dot_3].x == 0.f && positions[dot_7].x == 0.f);
            return Check_sides;
        }
        else
        {
            bool Check_sides = (positions[dot_0].x == 0.f && positions[dot_5].x == 0.f);
            return Check_sides;
        }
    }
    else
    {
        if (angle == 0 || angle == 180)
        {
            bool Check_sides = (positions[dot_3].x == -33.f && positions[dot_7].x == -33.f);
            return Check_sides;
        }
        else
        {
            bool Check_sides = (positions[dot_0].x == -33.f && positions[dot_5].x == -33.f);
            return Check_sides;
        }
    }
}
bool Sshape::Check_Right(bool For_Rotation)
{
    using enum Dot_positions;
    if (!For_Rotation)
    {
        if (angle == 0 || angle == 180)
        {
            bool Check_sides = (positions[dot_2].x == 330.f && positions[dot_6].x == 330.f);
            return Check_sides;
        }
        else
        {
            bool Check_sides = (positions[dot_4].x == 330.f && positions[dot_9].x == 330.f);
            return Check_sides;
        }
    }
    else
    {
        if (angle == 0 || angle == 180)
        {
            bool Check_sides = (positions[dot_2].x == 363.f && positions[dot_6].x == 363.f);
            return Check_sides;
        }
        else
        {
            bool Check_sides = (positions[dot_4].x == 363.f && positions[dot_9].x == 363.f);
            return Check_sides;
        }
    }
}
bool Sshape::Check_Collision_Below()
{
    if (angle == 0 || angle == 180)
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f -positions[dot_4].y)/33.f) + 1][(int)(positions[dot_4].x/33.f)] == 1||
             Collision_Array[(int)((627.f -positions[dot_5].y)/33.f) + 1][(int)(positions[dot_5].x/33.f)] == 1||
             Collision_Array[(int)((627.f -positions[dot_7].y)/33.f) + 1][(int)(positions[dot_7].x/33.f)] == 1||
             Collision_Array[(int)((627.f -positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
        return Check_Collision_Below;
    }
    else
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f -positions[dot_2].y)/33.f) + 1][(int)(positions[dot_2].x/33.f)] == 1||
             Collision_Array[(int)((627.f -positions[dot_5].y)/33.f) + 1][(int)(positions[dot_5].x/33.f)] == 1||
             Collision_Array[(int)((627.f -positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
             Collision_Array[(int)((627.f -positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
        return Check_Collision_Below;
    }
}
bool Sshape::Check_Collision_Left()
{
    if (angle == 0 || angle == 180)
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f -positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
        return Check_Collision_Below;
    }
    else
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f -positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
        return Check_Collision_Below;
    }
}
bool Sshape::Check_Collision_Right()
{
    if (angle == 0 || angle == 180)
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f -positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
        return Check_Collision_Below;
    }
    else
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f -positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f -positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
        return Check_Collision_Below;
    }
}


void Sshape::Update_pos(Vertex vertices[], const pattern& temp, float& rep)
{
    using enum Dot_positions;
    switch (angle)
    {
    case 0:
        positions[dot_0] = temp.Facing_up[2] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_up[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_up[3] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_up[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_4] = temp.Facing_up[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_up[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_up[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_up[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_8] = temp.Facing_up[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_9] = temp.Facing_up[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 90:
        positions[dot_0] = temp.Facing_right[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_right[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_right[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_3] = temp.Facing_right[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_right[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_right[1] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_6] = temp.Facing_right[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_right[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_right[3] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_9] = temp.Facing_right[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 180:
        positions[dot_0] = temp.Facing_down[2] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_down[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_down[3] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_down[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_4] = temp.Facing_down[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_down[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_down[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_down[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_8] = temp.Facing_down[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_9] = temp.Facing_down[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 270:
        positions[dot_0] = temp.Facing_left[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_left[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_left[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_3] = temp.Facing_left[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_left[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_left[1] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_6] = temp.Facing_left[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_left[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_left[3] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_9] = temp.Facing_left[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    }

    for (int i = 0 ; i < 10; i++)
    {
        positions[i] =  glm::translate(glm::mat4(1.f) , glm::vec3(side_move  , -33.f*rep, 0.f )) * positions[i];
    }
}

void Sshape::Update_Collision_Array()
{
    if (angle == 0 || angle == 180)
    {
        Collision_Array[(int)((627.f -positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627.f -positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
        Collision_Array[(int)((627.f -positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f)] = 1;
        Collision_Array[(int)((627.f -positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
    }
    else
    {
        Collision_Array[(int)((627.f -positions[dot_2].y)/33.f)][(int)(positions[dot_2].x/33.f)] = 1;
        Collision_Array[(int)((627.f -positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
        Collision_Array[(int)((627.f -positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627.f -positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
    }
}

//--------------------------------------ZShape---------------------------------------------//
bool Zshape::Check_below()
{
    using enum Dot_positions;
    if (angle == 0 || angle == 180)
    {
        bool Check_below =(positions[dot_3].y  == 0.f && positions[dot_4].y == 0.f)||
                          (positions[dot_7].y  == 0.f && positions[dot_8].y == 0.f)||
                          (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
        return Check_below;
    }
    else
    {
        bool Check_below =(positions[dot_6].y  == 0.f && positions[dot_7].y == 0.f)||
                          (positions[dot_8].y  == 0.f && positions[dot_9].y == 0.f);
        return Check_below;
    }
}
bool Zshape::Check_Left(bool For_Rotation)
{
    using enum Dot_positions;
    if (!For_Rotation)
    {
        if (angle == 0 || angle == 180)
        {
            bool Check_sides = (positions[dot_0].x == 0.f && positions[dot_3].x == 0.f);
            return Check_sides;
        }
        else
        {
            bool Check_sides = (positions[dot_2].x == 0.f && positions[dot_8].x == 0.f);
            return Check_sides;
        }
    }
    else
    {
        if (angle == 0 || angle == 180)
        {
            bool Check_sides = (positions[dot_0].x == -33.f && positions[dot_3].x == -33.f);
            return Check_sides;
        }
        else
        {
            bool Check_sides = (positions[dot_2].x == -33.f && positions[dot_8].x == -33.f);
            return Check_sides;
        }
    }
}
bool Zshape::Check_Right(bool For_Rotation)
{
    using enum Dot_positions;
    if (!For_Rotation)
    {
        if (angle == 0 || angle == 180)
        {
            bool Check_sides = (positions[dot_6].x == 330.f && positions[dot_9].x == 330.f);
            return Check_sides;
        }
        else
        {
            bool Check_sides = (positions[dot_1].x == 330.f && positions[dot_7].x == 330.f);
            return Check_sides;
        }
    }
    else
    {
        if (angle == 0 || angle == 180)
        {
            bool Check_sides = (positions[dot_6].x == 363.f && positions[dot_9].x == 363.f);
            return Check_sides;
        }
        else
        {
            bool Check_sides = (positions[dot_1].x == 363.f && positions[dot_7].x == 363.f);
            return Check_sides;
        }
    }
}
bool Zshape::Check_Collision_Below()
{
    if (angle == 0 || angle == 180)
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f) + 1][(int)(positions[dot_3].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_4].y)/33.f) + 1][(int)(positions[dot_4].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_7].y)/33.f) + 1][(int)(positions[dot_7].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
        return Check_Collision_Below;
    }
    else
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f) + 1][(int)(positions[dot_3].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_5].y)/33.f) + 1][(int)(positions[dot_5].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_6].y)/33.f) + 1][(int)(positions[dot_6].x/33.f)] == 1||
             Collision_Array[(int)((627.f - positions[dot_8].y)/33.f) + 1][(int)(positions[dot_8].x/33.f)] == 1);
        return Check_Collision_Below;
    }
}
bool Zshape::Check_Collision_Left()
{
    if (angle == 0 || angle == 180)
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
        return Check_Collision_Below;
    }
    else
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) - 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) - 1] == 1);
        return Check_Collision_Below;
    }
}
bool Zshape::Check_Collision_Right()
{
    if (angle == 0 || angle == 180)
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
        return Check_Collision_Below;
    }
    else
    {
        bool Check_Collision_Below =
            (Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f) + 1] == 1||
             Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f) + 1] == 1);
        return Check_Collision_Below;
    }
}


void Zshape::Update_pos(Vertex vertices[], const pattern& temp, float& rep)
{
    using enum Dot_positions;
    switch (angle)
    {
    case 0:
        positions[dot_0] = temp.Facing_up[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_up[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_up[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_up[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_4] = temp.Facing_up[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_up[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_up[3] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_up[2] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_8] = temp.Facing_up[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_9] = temp.Facing_up[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 90:
        positions[dot_0] = temp.Facing_right[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_right[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_right[2] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_3] = temp.Facing_right[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_right[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_right[2] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_6] = temp.Facing_right[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_right[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_right[3] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_9] = temp.Facing_right[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 180:
        positions[dot_0] = temp.Facing_down[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_down[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_down[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_down[0] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_4] = temp.Facing_down[0] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_down[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_down[3] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_down[2] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_8] = temp.Facing_down[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_9] = temp.Facing_down[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    case 270:
        positions[dot_0] = temp.Facing_left[0] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_1] = temp.Facing_left[0] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_2] = temp.Facing_left[2] * glm::vec4(vertices[UpperLeft].coordinates,  0.f , 1.f);
        positions[dot_3] = temp.Facing_left[2] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_4] = temp.Facing_left[1] * glm::vec4(vertices[UpperRight].coordinates, 0.f , 1.f);
        positions[dot_5] = temp.Facing_left[2] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_6] = temp.Facing_left[2] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_7] = temp.Facing_left[1] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        positions[dot_8] = temp.Facing_left[3] * glm::vec4(vertices[LowerLeft].coordinates,  0.f , 1.f);
        positions[dot_9] = temp.Facing_left[3] * glm::vec4(vertices[LowerRight].coordinates, 0.f , 1.f);
        break;
    }

    for (int i = 0 ; i < 10; i++)
    {
        positions[i] =  glm::translate(glm::mat4(1.f) , glm::vec3(side_move  , -33.f*rep, 0.f )) * positions[i];
    }
}

void Zshape::Update_Collision_Array()
{
    if (angle == 0 || angle == 180)
    {
        Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_4].y)/33.f)][(int)(positions[dot_4].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_7].y)/33.f)][(int)(positions[dot_7].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
    }
    else
    {
        Collision_Array[(int)((627.f - positions[dot_3].y)/33.f)][(int)(positions[dot_3].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_5].y)/33.f)][(int)(positions[dot_5].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_6].y)/33.f)][(int)(positions[dot_6].x/33.f)] = 1;
        Collision_Array[(int)((627.f - positions[dot_8].y)/33.f)][(int)(positions[dot_8].x/33.f)] = 1;
    }
}

//========================================================================================//

void Update_Instance_matrix(std::vector<glm::mat4>& Instance_matrix, int& amount)
{
    for (int n = 0; n < 4; n++)
    {
        Instance_matrix[(amount - 4) + n] = glm::translate(Instance_matrix[(amount - 4) + n], glm::vec3(side_move , -33.f*rep, 0.f));
    }
}

bool Check_All_Left()
{
    using enum pattern_type;
    switch (Random)
    {
    case IShape: return Ishape::Check_Left(false);
    case OShape: return Oshape::Check_Left();
    case JShape: return Jshape::Check_Left(false);
    case LShape: return Lshape::Check_Left(false);
    case TShape: return Tshape::Check_Left(false);
    case SShape: return Sshape::Check_Left(false);
    case ZShape: return Zshape::Check_Left(false);
    }
}
bool Check_All_Right()
{
    using enum pattern_type;
    switch (Random)
    {
    case IShape: return Ishape::Check_Right(false);
    case OShape: return Oshape::Check_Right();
    case JShape: return Jshape::Check_Right(false);
    case LShape: return Lshape::Check_Right(false);
    case TShape: return Tshape::Check_Right(false);
    case SShape: return Sshape::Check_Right(false);
    case ZShape: return Zshape::Check_Right(false);
    }
}

bool Check_All_Left_Rotation()
{
    using enum pattern_type;
    switch (Random)
    {
    case IShape: return Ishape::Check_Left(true);
    case OShape: return false;
    case JShape: return Jshape::Check_Left(true);
    case LShape: return Lshape::Check_Left(true);
    case TShape: return Tshape::Check_Left(true);
    case SShape: return Sshape::Check_Left(true);
    case ZShape: return Zshape::Check_Left(true);
    default: return false;
    }
}
bool Check_All_Right_Rotation()
{
    using enum pattern_type;
    switch (Random)
    {
    case IShape: return Ishape::Check_Right(true);
    case OShape: return false;
    case JShape: return Jshape::Check_Right(true);
    case LShape: return Lshape::Check_Right(true);
    case TShape: return Tshape::Check_Right(true);
    case SShape: return Sshape::Check_Right(true);
    case ZShape: return Zshape::Check_Right(true);
    }
}

bool Check_All_Below()
{
    using enum pattern_type;
    switch (Random)
    {
    case IShape: return Ishape::Check_below();
    case OShape: return Oshape::Check_below();
    case JShape: return Jshape::Check_below();
    case LShape: return Lshape::Check_below();
    case TShape: return Tshape::Check_below();
    case SShape: return Sshape::Check_below();
    case ZShape: return Zshape::Check_below();
    }
}

bool Check_All_Collision_Below()
{
    using enum pattern_type;
    switch (Random)
    {
    case IShape: return Ishape::Check_Collision_Below();
    case OShape: return Oshape::Check_Collision_Below();
    case JShape: return Jshape::Check_Collision_Below();
    case LShape: return Lshape::Check_Collision_Below();
    case TShape: return Tshape::Check_Collision_Below();
    case SShape: return Sshape::Check_Collision_Below();
    case ZShape: return Zshape::Check_Collision_Below();
    }
}

bool Check_All_Collision_Left()
{
    switch (Random)
    {
    case IShape: return Ishape::Check_Collision_Left();
    case OShape: return Oshape::Check_Collision_Left();
    case JShape: return Jshape::Check_Collision_Left();
    case LShape: return Lshape::Check_Collision_Left();
    case TShape: return Tshape::Check_Collision_Left();
    case SShape: return Sshape::Check_Collision_Left();
    case ZShape: return Zshape::Check_Collision_Left();
    }
}
bool Check_All_Collision_Right()
{
    switch (Random)
    {
    case IShape: return Ishape::Check_Collision_Right();
    case OShape: return Oshape::Check_Collision_Right();
    case JShape: return Jshape::Check_Collision_Right();
    case LShape: return Lshape::Check_Collision_Right();
    case TShape: return Tshape::Check_Collision_Right();
    case SShape: return Sshape::Check_Collision_Right();
    case ZShape: return Zshape::Check_Collision_Right();
    }
}


void Update_Ground()
{
    switch (Random)
    {
    case IShape:    Ishape::Update_Collision_Array(); break;
    case OShape:    Oshape::Update_Collision_Array(); break;
    case JShape:    Jshape::Update_Collision_Array(); break;
    case LShape:    Lshape::Update_Collision_Array(); break;
    case TShape:    Tshape::Update_Collision_Array(); break;
    case SShape:    Sshape::Update_Collision_Array(); break;
    case ZShape:    Zshape::Update_Collision_Array(); break;
    }
}

void Print_Ground()
{
    for (int i = 0 ; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << Collision_Array[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
}

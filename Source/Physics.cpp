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
        positions[dot_0] = temp.Facing_left[3] * glm::vec4(vertices[UpperLeft].coordinates, 0.f , 1.f);
        positions[dot_1] = temp.Facing_left[3] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_2] = temp.Facing_left[3] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_3] = temp.Facing_left[3] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
        positions[dot_4] = temp.Facing_left[1] * glm::vec4(vertices[UpperRight].coordinates,0.f , 1.f);
        positions[dot_5] = temp.Facing_left[2] * glm::vec4(vertices[LowerLeft].coordinates, 0.f , 1.f);
        positions[dot_6] = temp.Facing_left[2] * glm::vec4(vertices[LowerRight].coordinates,0.f , 1.f);
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


//--------------------------------------ZShape---------------------------------------------//
bool Zshape::Check_below()
{
    using enum Dot_positions;
    if (angle == 0 || angle == 180)
    {
        bool Check_below =(positions[dot_7].y  == 0.f && positions[dot_8].y == 0.f)||
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

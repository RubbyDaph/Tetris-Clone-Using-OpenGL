#include<Patterns.h>

pattern get_Ishape()
{
    pattern I
    {
     {//-------------------------Facing up--------------------------------------//
      glm::translate(glm::mat4(1.f), glm::vec3(-33.f,  0.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3( 33.f,  0.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3( 66.f,  0.f, 0.f))
     },
     {//------------------------Facing right-----------------------------------//
      glm::translate(glm::mat4(1.f), glm::vec3( 33.f, 33.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3( 33.f,  0.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-66.f, 0.f))
     },
     {//------------------------Facing left------------------------------------//
      glm::translate(glm::mat4(1.f), glm::vec3(  0.f, 33.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f))
     },
     {//------------------------Facing down------------------------------------//
      glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f)),
      glm::translate(glm::mat4(1.f), glm::vec3( 66.f,-33.f, 0.f))
     }
    };
    return I;
}

pattern get_Oshape()
{
 pattern O
{
  { //-----------------Always Facing up----------------------------------//
   glm::translate(glm::mat4(1.f), glm::vec3( 0.f,   0.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3(33.f,   0.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3( 0.f, -33.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3(33.f, -33.f, 0.f))
  },
  { //-----------------Always Facing up----------------------------------//
   glm::translate(glm::mat4(1.f), glm::vec3( 0.f,   0.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3(33.f,   0.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3( 0.f, -33.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3(33.f, -33.f, 0.f))
  },
  { //-----------------Always Facing up----------------------------------//
   glm::translate(glm::mat4(1.f), glm::vec3( 0.f,   0.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3(33.f,   0.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3( 0.f, -33.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3(33.f, -33.f, 0.f))
  },
  { //-----------------Always Facing up----------------------------------//
   glm::translate(glm::mat4(1.f), glm::vec3( 0.f,   0.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3(33.f,   0.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3( 0.f, -33.f, 0.f)),
   glm::translate(glm::mat4(1.f), glm::vec3(33.f, -33.f, 0.f))
  }
 };
 return O;
}

pattern get_Jshape()
{
    pattern J
    {
     {//-------------------------Facing up--------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,   0.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f, -33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f, -33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f, -33.f, 0.f))
     },
     {//------------------------Facing right-----------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,  0.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f))
     },
     {//------------------------Facing left------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-66.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f))
     },
     {//------------------------Facing down------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-66.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f))
     }
    };
    return J;
}

pattern get_Lshape()
{
    pattern L
    {
     {//-------------------------Facing up--------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,  0.f, 0.f))
     },
     {//------------------------Facing right-----------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-66.f, 0.f))
     },
     {//------------------------Facing left------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,  0.f, 0.f))
     },
     {//------------------------Facing down------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-66.f, 0.f))
     }
    };
 return L;
}

pattern get_Tshape()
{
    pattern T
    {
     {//-------------------------Facing up--------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f))
     },
     {//------------------------Facing right-----------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f))
     },
     {//------------------------Facing left------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f))
     },
     {//------------------------Facing down------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f))
     }
    };
 return T;
}

pattern get_Sshape()
{
    pattern S
    {
     {//-------------------------Facing up--------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,  0.f, 0.f))
     },
     {//------------------------Facing right-----------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-66.f, 0.f))
     },
     {//------------------------Facing left------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,  0.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f))
     },
     {//------------------------Facing down------------------------------------//
       glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-66.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
       glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f))
     }
    };
 return S;
}

pattern get_Zshape()
{
    pattern Z
    {
            {//-------------------------Facing up--------------------------------------//
                glm::translate(glm::mat4(1.f), glm::vec3(-33.f,  0.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f))
            },
            {//------------------------Facing right-----------------------------------//
                glm::translate(glm::mat4(1.f), glm::vec3( 33.f,  0.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-33.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f))
            },
            {//------------------------Facing left------------------------------------//
                glm::translate(glm::mat4(1.f), glm::vec3(  0.f,  0.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-66.f, 0.f))
            },
            {//------------------------Facing down------------------------------------//
                glm::translate(glm::mat4(1.f), glm::vec3(-33.f,-33.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-33.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3(  0.f,-66.f, 0.f)),
                glm::translate(glm::mat4(1.f), glm::vec3( 33.f,-66.f, 0.f))
            }
    };
 return Z;
}
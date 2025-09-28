#ifndef Patterns_header
#define Patterns_header
#include <array>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>


struct pattern
{
    std::array<glm::mat4, 4> Facing_up;
    std::array<glm::mat4, 4> Facing_right;
    std::array<glm::mat4, 4> Facing_left;
    std::array<glm::mat4, 4> Facing_down;
};

pattern get_Ishape();
pattern get_Oshape();
pattern get_Jshape();
pattern get_Lshape();
pattern get_Tshape();
pattern get_Sshape();
pattern get_Zshape();




#endif

#ifndef SFML_DEFAULTSHADERS_HPP
#define SFML_DEFAULTSHADERS_HPP

namespace sf
{

extern const char* DefaultFragmentShaderUntextured;
extern const char* DefaultVertexShaderUntextured;
extern const char* DefaultFragmentShaderTextured;
extern const char* DefaultVertexShaderTextured;

void InitDefaultShaders();
void DeinitDefaultShaders();

}

#endif

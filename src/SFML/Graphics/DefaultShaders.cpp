#include <SFML/Graphics/DefaultShaders.hpp>
#include <SFML/Graphics/Shader.hpp>

namespace sf
{

const char* DefaultFragmentShaderUntextured =
"#version 120"
"void main(void)"
"{"
"	gl_FragColor = gl_Color;"
"}";

const char* DefaultVertexShaderUntextured =
"#version 120"
"uniform vec4 u_colour;"
"void main(void)"
"{"
"	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
"	gl_FrontColor = gl_Color * u_colour;"
"}";

const char* DefaultFragmentShaderTextured =
"#version 120"
"uniform sampler2D u_tex;"
"void main(void)"
"{"
"	vec4 colour = texture2D(u_tex, gl_TexCoord[0].st);"
"	gl_FragColor = gl_Color * colour;"
"}";

const char* DefaultVertexShaderTextured =
"#version 120"
"uniform vec4 u_colour;"
"void main(void)"
"{	"
"	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
"	gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
"	gl_FrontColor = gl_Color * u_colour;"
"}";

static bool s_initialised = false;
static sf::Shader* s_defaultShaderTextured;
static sf::Shader* s_defaultShaderUntextured;

void InitDefaultShaders()
{
	if (s_initialised)
		return;

	s_defaultShaderUntextured = new sf::Shader();
	s_defaultShaderUntextured->loadFromMemory(DefaultVertexShaderUntextured, DefaultFragmentShaderUntextured);
	sf::Shader::setDefaultShader(sf::Shader::Untextured, s_defaultShaderUntextured);

	s_defaultShaderTextured = new sf::Shader();
	s_defaultShaderTextured->loadFromMemory(DefaultVertexShaderTextured, DefaultFragmentShaderTextured);
	sf::Shader::setDefaultShader(sf::Shader::Textured, s_defaultShaderTextured);
}

void DeinitDefaultShaders()
{
	if (!s_initialised)
		return;

	s_initialised = false;

	delete s_defaultShaderUntextured;
	delete s_defaultShaderTextured;
}

}

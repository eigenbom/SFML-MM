#include <SFML/Graphics/DefaultShaders.hpp>
#include <SFML/Graphics/Shader.hpp>

namespace sf
{

static const char* DefaultFragmentShaderUntextured =
"#version 120\n"
"void main(void)\n"
"{\n"
"	gl_FragColor = gl_Color;\n"
"}";

static const char* DefaultVertexShaderUntextured =
"#version 120\n"
"uniform vec4 u_colour;\n"
"void main(void)\n"
"{\n"
"	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;\n"
"	gl_FrontColor = gl_Color * u_colour;\n"
"}";

static const char* DefaultFragmentShaderTextured =
"#version 120\n"
"uniform sampler2D u_tex;\n"
"void main(void)\n"
"{"
"	vec4 colour = texture2D(u_tex, gl_TexCoord[0].st);\n"
"	gl_FragColor = gl_Color * colour;\n"
"}";

static const char* DefaultVertexShaderTextured =
"#version 120\n"
"uniform vec4 u_colour;\n"
"void main(void)\n"
"{\n"
"	gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;\n"
"	gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;\n"
"	gl_FrontColor = gl_Color * u_colour;\n"
"}";

static bool s_initialised = false;
static sf::Shader* s_defaultShaderTextured;
static sf::Shader* s_defaultShaderUntextured;

void DefaultShaders::init()
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

void DefaultShaders::deinit()
{
	if (!s_initialised)
		return;

	s_initialised = false;

	delete s_defaultShaderUntextured;
	delete s_defaultShaderTextured;
}

}
